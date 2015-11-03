#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#define MAXLINE 1024
void client(int,int),server(int,int);

int main(int argc,char **argv)
{
    int     pipe1[2],pipe2[2];
    pid_t   childpid;
    pipe(pipe1);
    pipe(pipe2);
    if( (childpid = fork())==0)
    {
        close(pipe1[1]);
        close(pipe2[0]);

        server(pipe1[0],pipe2[1]);
        exit(0);
    }
    close(pipe1[0]);
    close(pipe2[1]);

    client(pipe2[0],pipe1[1]);
    waitpid(childpid,NULL,0);
    exit(0);
}

void client(int readfd,int writefd)
{
    size_t  len;
    ssize_t n;
    char    buff[MAXLINE];

    fgets(buff,MAXLINE,stdin);
    len = strlen(buff);
    if(buff[len-1]=='\n')
    {
        len--;
    }
    write(writefd,buff,len);
    while((n=read(readfd,buff,MAXLINE))>0)
        write(STDOUT_FILENO,buff,n);
}

void server(int readfd,int writefd)
{
    int fd;
    ssize_t n;
    char    buff[MAXLINE+1];

    if((n=read(readfd,buff,MAXLINE))==0)
    {
        printf("end-of-file while reading pathname");
        return;
    }
    buff[n]='\0';

    if((fd=open(buff,O_RDONLY))<0)
    {
        snprintf(buff+n,sizeof(buff)-n,":can't open,%s\n",strerror(errno));
        n=strlen(buff);
        write(writefd,buff,n);
    }
    else{
        while((n=read(fd,buff,MAXLINE))>0)
            write(writefd,buff,n);
        close(fd);

    }

}

