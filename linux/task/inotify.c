#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int watched_items;
int keep_running;

int open_inotify_fd(void)
{
	int fd;

	watched_items = 0;
	fd = inotify_init ();

	if (fd < 0)
	{
		perror ("inotify_init () = ");
	}
	return fd;
}

int watch_dir (int fd, const char *dirname, unsigned long mask)
{
	int wd;
	wd = inotify_add_watch(fd, dirname, mask);
	if (wd < 0)
	{
		printf ("Cannot add watch for \"%s\" with event mask %lX", dirname,
				mask);
		fflush (stdout);
		perror (" ");
	}
	else
	{
		watched_items++;
		printf ("Watching %s WD=%d\n", dirname, wd);
		printf ("Watching = %d items\n", watched_items); 
	}
	return wd;
}

int read_events (queue_t q, int fd)
{
	char buffer[16384];
	size_t buffer_i;
	struct inotify_event *pevent;
	queue_entry_t event;
	ssize_t r;
	size_t event_size, q_event_size;
	int count = 0;

	r = read (fd, buffer, 16384);
	if (r <= 0)
		return r;
	buffer_i = 0;
	while (buffer_i < r)
	{
		/* Parse events and queue them. */
		pevent = (struct inotify_event *) &buffer[buffer_i];
		event_size =  offsetof(struct inotify_event, name) + pevent->len;
		q_event_size = offsetof(struct queue_entry, inot_ev.name) + pevent->len;
		event = malloc (q_event_size);
		memmove (&(event->inot_ev), pevent, event_size);
		queue_enqueue(event, q);
		buffer_i += event_size;
		count++;
	}
	printf ("\n%d events queued\n", count);
	return count;
}
void handle_event(queue_entry_t event)
{
	/* If the event was associated with a filename, we will store it here */
	char *cur_event_filename = NULL;
	char *cur_event_file_or_dir = NULL;
	/* This is the watch descriptor the event occurred on */
	int cur_event_wd = event->inot_ev.wd;
	int cur_event_cookie = event->inot_ev.cookie;

	unsigned long flags;

	if (event->inot_ev.len)
	{
		cur_event_filename = event->inot_ev.name;
	}
	if ( event->inot_ev.mask & IN_ISDIR )
	{
		cur_event_file_or_dir = "Dir";
	}
	else 
	{
		cur_event_file_or_dir = "File";
	}
	flags = event->inot_ev.mask & ~(IN_ALL_EVENTS | IN_UNMOUNT | IN_Q_OVERFLOW | IN_IGNORED );

	/* Perform event dependent handler routines */
	/* The mask is the magic that tells us what file operation occurred */
	switch (event->inot_ev.mask & (IN_ALL_EVENTS | IN_UNMOUNT | IN_Q_OVERFLOW | IN_IGNORED))
	{
		/* File was accessed */
		case IN_ACCESS:
			printf ("ACCESS: %s \"%s\" on WD #%i\n",cur_event_file_or_dir, cur_event_filename, cur_event_wd);
			break;

			/* File was modified */
		case IN_MODIFY:
			printf ("MODIFY: %s \"%s\" on WD #%i\n",cur_event_file_or_dir, cur_event_filename, cur_event_wd);
			break;

			/* File changed attributes */
		case IN_ATTRIB:
			printf ("ATTRIB: %s \"%s\" on WD #%i\n", cur_event_file_or_dir, cur_event_filename, cur_event_wd);
			break;

			/* File open for writing was closed */
		case IN_CLOSE_WRITE:
			printf ("CLOSE_WRITE: %s \"%s\" on WD #%i\n",cur_event_file_or_dir, cur_event_filename, cur_event_wd);
			break;

			/* File open read-only was closed */
		case IN_CLOSE_NOWRITE:
			printf ("CLOSE_NOWRITE: %s \"%s\" on WD #%i\n",cur_event_file_or_dir, cur_event_filename, cur_event_wd);
			break;

			/* File was opened */
		case IN_OPEN:
			printf ("OPEN: %s \"%s\" on WD #%i\n",cur_event_file_or_dir, cur_event_filename, cur_event_wd);
			break;

			/* File was moved from X */
		case IN_MOVED_FROM:
			printf ("MOVED_FROM: %s \"%s\" on WD #%i. Cookie=%d\n",cur_event_file_or_dir, cur_event_filename, cur_event_wd, cur_event_cookie);
			break;

			/* Watch was removed explicitly by inotify_rm_watch or automatically
			   because file was deleted, or file system was unmounted.  */
		case IN_IGNORED:
			watched_items--;
			printf ("IGNORED: WD #%d\n", cur_event_wd);
			printf("Watching = %d items\n",watched_items); 
			break;

			/* Some unknown message received */
		default:
			printf ("UNKNOWN EVENT \"%X\" OCCURRED for file \"%s\" on WD #%i\n",event->inot_ev.mask, cur_event_filename, cur_event_wd);
			break;
	}
	/* If any flags were set other than IN_ISDIR, report the flags */
	if (flags & (~IN_ISDIR))
	{
		flags = event->inot_ev.mask;
		printf ("Flags=%lX\n", flags);
	}
}
int process_inotify_events(queue_t q, int fd)
{
	while (keep_running && (watched_items > 0))
	{
		if (event_check (fd) > 0)
		{
			int r;
			r = read_events (q, fd);
			if (r < 0)
			{
				break;
			}
			else
			{
				handle_events (q);
			}
		}
	}
	return 0;
}

int event_check (int fd)
{
	fd_set rfds;
	FD_ZERO (&rfds);
	FD_SET (fd, &rfds);
	/* Wait until an event happens or we get interrupted 
	   by a signal that we catch */
	return select(FD_SETSIZE, &rfds, NULL, NULL, NULL);
}

void signal_handler (int signum)
{
	keep_running = 0;
}

int main (int argc, char **argv)
{
	/* This is the file descriptor for the inotify watch */
	int inotify_fd;

	keep_running = 1;

	/* Set a ctrl-c signal handler */
	if (signal (SIGINT, signal_handler) == SIG_IGN)
	{
		/* Reset to SIG_IGN (ignore) if that was the prior state */
		signal (SIGINT, SIG_IGN);
	}

	/* First we open the inotify dev entry */
	inotify_fd = open_inotify_fd();
	if (inotify_fd > 0)
	{
		queue_t q;
		q = queue_create(128);

		int wd;


		int index;
		wd = 0;
		printf("\n");
		for (index = 1; (index < argc) && (wd >= 0); index++) 
		{
			wd = watch_dir (inotify_fd, argv[index], IN_ALL_EVENTS);
		}

		if (wd > 0) 
		{
			process_inotify_events (q, inotify_fd);
		}
		printf ("\nTerminating\n");

		close_inotify_fd (inotify_fd);
		queue_destroy(q);
	}
	return 0;
}
