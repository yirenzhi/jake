#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	mkfifo("./fifo1",0777);


	return 0;
}