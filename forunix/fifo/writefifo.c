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
    int writefd=open("./fifo1",O_WRONLY,0);
    while(1)
    {
        //printf("client------------\n");
        fgets(buff,MAXLINE,stdin);
        len = strlen(buff);
        if(buff[len-1]=='\n')
        {
            len--;
        }
        write(writefd,buff,len);
    }
	return 0;
}