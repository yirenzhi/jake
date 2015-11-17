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
    int readfd=open("./fifo2",O_RDONLY,0);

    if (fork()==0)
    {    int writefd=open("./fifo1",O_WRONLY,0);

        
        while(1)
        {
            if((n=read(readfd,buff,MAXLINE))>0)
            {
                buff[n]='\0';
                buff[n+1]='\n';
                fputs("other:",stdout);
                write(STDOUT_FILENO,buff,n+2);
            }
        }

    }
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