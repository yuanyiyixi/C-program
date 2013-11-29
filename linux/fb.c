#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <stdlib.h>

int main(void)
{
	int fd;
	if ((fd = open("/dev/fb0", O_RDWR)) < 0){
		perror("open");
		return -1;
	}

	struct fb_var_screeninfo fb_var;
	if (ioctl(fd, FBIOGET_VSCREENINFO, &fb_var) < 0){
		perror("ioctl");
		return -1;
	}

	printf("width:%d\thign:%d\tbpp:%d\n",
			fb_var.xres, fb_var.yres, fb_var.bits_per_pixel);

	int *mm = mmap(NULL, fb_var.xres * fb_var.yres * fb_var.bits_per_pixel/8, PROT_WRITE, MAP_SHARED, fd, 0);
	if (mm == MAP_FAILED)
	{
		perror("mmap");
		exit(-1);
	}
	int i;
	while(1)
	{
		for (i = 0; i < fb_var.xres * fb_var.yres; i++)
			mm[i] = 0x00ff0000;
			sleep(1);
		for (i = 0; i < fb_var.xres * fb_var.yres; i++)
			mm[i] = 0x00ffff00;
			sleep(1);
		for (i = 0; i < fb_var.xres * fb_var.yres; i++)
			mm[i] = 0x0000ff00;
			sleep(1);
		for (i = 0; i < fb_var.xres * fb_var.yres; i++)
			mm[i] = 0x0000ffff;
			sleep(1);
		for (i = 0; i < fb_var.xres * fb_var.yres; i++)
			mm[i] = 0x000000ff;
			sleep(1);
		for (i = 0; i < fb_var.xres * fb_var.yres; i++)
			mm[i] = 0x00ff00ff;
			sleep(1);
		for (i = 0; i < fb_var.xres * fb_var.yres; i++)
			mm[i] = 0x00ffffff;
			sleep(1);
	}
	munmap(mm, fb_var.xres * fb_var.yres * fb_var.bits_per_pixel/8);
	close(fd);

	close(fd);
	return 0;
}

