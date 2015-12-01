#include <stdio.h>
int main()
{   
    int m=100,max=0,n=0;
    for(;m<=999;m++)
    {
    	int s=(m/53)+(m%53);
     	if(max<s)
     	{
     		n=m;
  			max=s;
     	}
    }
  	printf("三位数为%d,a+b=%d\n",n,max);
  	return 0;
}
