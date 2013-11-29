all:
	gcc server-poll.c wrap.c -o server
	gcc Client.c wrap.c -o client

.PHONY:clean

clean:
	-rm server
	-rm client
