//测试全双工管道的双向通信能力
//之所以不成功是因为不是全双工管道
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
	int fd[2],n;
	char c;
	pipe(fd);
/*	
	if (fork()==0)//子进程
	{
		sleep(2);
		if ((n=read(fd[1],&c,1))!=1)
		{
			printf("child:read returned %d",n);
			exit(1);
		}
		printf("child read %c\n",c);
		write(fd[1],"c",1);
		exit(0);
	}	

	*/
	//父进程
	// printf("abc\n");
	 write(fd[1],"p",1);
//	if ((n=read(fd[1],&c,1))!=1)
	if(read(fd[0],&c,1)!=1)
	{
		printf("parent:read returned%d \n",n);
		exit(1);
	}
	printf("parent read %c\n", c);


//	write(fd[1],"p",1);
	// if(read(fd[0],&c,1)!=1)
	// 	printf("parent read error\n");

	// printf("parent read is %c\n", c);
	// return 0;

	exit(0);
}