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
	
	if (fork()==0)
	{
		sleep(2);
		if(read(fd[1],&c,1)!=1)
			printf("childre read error\n");
		printf("childre read is %c\n", c);
		printf("1111\n");
		write(fd[1],"b",1);
		printf("22222\n");
		exit(0);
	}
	
	write(fd[0],"p",1);
	// if(read(fd[0],&c,1)!=1)
	// 	printf("parent read error\n");

	// printf("parent read is %c\n", c);
	return 0;
}