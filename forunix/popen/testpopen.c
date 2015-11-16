#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
//const int MAXLINE 1024;
#define MAXLINE 1024
int main(int argc, char const *argv[])
{
	size_t n;
	char buff[MAXLINE],command[MAXLINE];
	FILE *fp;

	fgets(buff,MAXLINE,stdin);
	n = strlen(buff);
	if(buff[n-1]=='\n')
		n--;
	//字符串拼接函数，第二个参数为拼接后字符串的最大个数，
	snprintf(command,sizeof(command),"cat %s",buff);
	//popen函数开启一个进程通过pipe,forking和调用shell,管道通常会被定义成单向，将只能读或者写
	fp = popen(command,"r");

	while(fgets(buff,MAXLINE,fp)!=NULL)
	{
		fputs(buff,stdout);
	}
	pclose(fp);

	return 0;
}