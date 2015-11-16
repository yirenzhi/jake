#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#define MAXLINE 1024
int main(int argc, char const *argv[])
{
	size_t  len;
    ssize_t n;
    char    buff[MAXLINE];
    int readfd=open("./fifo1",O_RDONLY,0);
    while(1)
    {
        if((n=read(readfd,buff,MAXLINE))>0)
            write(STDOUT_FILENO,buff,n);
    }
	return 0;
}