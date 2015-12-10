#include <stdio.h>
#include <string.h>
//插入排序，j的取值是从i到总数，比选择排序稍微优化了点。
void insert(int a[])
{
	for(int i=0;i<sizeof(a);i++)
	{
		for (int j = i; j < sizeof(a); ++j)
		{
			if (a[i]>a[j])
			{
				int m=a[i];
				a[i]=a[j];
				a[j]=m;
			}
		}
	}

}

//希尔排序，插入排序的升级版，不是相邻的元素比较，而是相隔一段距离元素的比较，最后变成相隔1
void shell(int a[],int N)
{
	for (int increament=N/2;increament>0;increament/=2)
	{
		for(int i=increament;i<N;++i)
		{
			for(int j=i;j>=increament;j-=increament)
			{
				if (a[j-increament]>a[j])
				{
					int m=a[j];
					a[j]=a[j-increament];
					a[j-increament]=m;
				}
				else
				{
					break;
				}
			}
		}
	}
}


//我的希尔
void myShell(int a[],int N)
{
	for(int increament=N/2;increament>0;increament/=2)
	{
		for (int i=0;i<increament;i++)
		{
			for(int j=i+increament;j<N;j++)
			{
				if (a[i]>a[j])
				{
					int m=a[i];
					a[i]=a[j];
					a[j]=m;
				}
			}
		}
	}
}
int main()
{
	int s[]={3,5,7,2,9,4,0,1,8,6};
	printf("排序前\n");
	int num=sizeof(s)/sizeof(int);
	for (int i = 0; i < num; ++i)
	{
		printf("%4d",s[i]);
	}

	printf("\n");
//	insert(s);
//	shell(s,num);
	myShell(s,num);
	printf("排序后\n");

	for (int i = 0; i < num; ++i)
	{
		printf("%4d",s[i]);
	}
	printf("\n");

	return 0;
}