#include <stdio.h>
void insertSort(int a[],int N);
int main()
{
	char c[16]={0};

	printf("----------------------------\n");
	printf("算法学习总结\n");
	printf("1.插入排序\n");
	printf("----------------------------\n");
	printf("请输入数字选择算法，输入exit退出.\n");
	while(1)
	{
		scanf("%s",c);
		printf("%s\n",c);
		//strcmp比较两个字符串，从第一个字符开始比,如果相同,继续向下比,如果不同,
		//看这两个字符的ASCII码,如果第一个字符串的比较大,则返回1,否则返回-1
		if (strcmp(c,"exit")==0)
		{
			printf("已退出\n");
			break;
		}
		else
		{
		
			printf("请输入想要排序的数列，以空格相间隔\n");
			if(strcmp(c,"1")==0)
			{
				//插入排序
			}
			if(strcmp(c,"2")==0)
			{
				//
			}
		}
	}

void insertSort(int a[],int N)
{
	for(int i=0;i<N;i++)
	{
		for(int j=i;j<N;j++)
		{
			if(a[i]<a[j])
			{
				int m=a[i];
				a[i]=a[j];
				a[j]=m;
			}
		}
	}
}
	return 0;
}
