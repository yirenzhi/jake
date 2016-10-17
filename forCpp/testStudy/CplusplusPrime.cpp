#include <iostream>
#include "Salesitem.h"
using namespace std;

void testcin()
{
	int sum=0, value =0;
	//当我们使用一个isstream对象作为条件时，其效果是检测流的状态，如果流是有效的，即流未遇到错误，那么检测成功。当遇到
	//文件结束符（end-of-file），或遇到一个无效输入时（例如读入的值不是整数），isstream对象的状态会变成无效，

	//键盘输入文件结束符
	//windows系统中，输入Ctrl+Z  unix系统输入Ctrl+D
	while (cin>>value)
	{
		sum+=value;
	}
	cout<<sum<<endl;
}

void testif()
{
	int curVal =0,val =0;
	if (cin>>curVal)
	{
		int cnt =1;
		while (cin>>val)
		{
			if (curVal==val)
			{
				cnt++;
			}
			else
			{
				cout<<curVal<<"  chuxian  "<<cnt<<endl;
				curVal=val;
				cnt=1;
			}
			cout<<curVal<<"  chuxian  "<<cnt<<endl;
		}
	}

}

void testSignLoad()
{
	Sales_item book;
	//std::cin>>book;


}


void testVar()
{
	28L;	
	unsigned u =10,u2=42;
	cout<<u-u2<<endl;
	cout<<(1<<32)-32<<endl;
	unsigned m=(1<<32)-32;
	cout<<m<<endl;
	cout<<u2-u<<endl;
	
	int i=10,i2=42;
	cout<<i2-i<<endl;
	cout<<i-i2<<endl;
	cout<<i-u<<endl;
	cout<<u-i<<endl;

	cout<<"\thello"<<endl;
	cout<<'\115'<<endl;


	int *p1=nullptr;
	int *p2=0;
	int *p3=&i;
	int x=0;
	//int *p3=1;  错误int型类型的值不能用来初始化指针
	int bb=42;
	const int &r1=bb;
	const int &r3=r1*2;
	//int &r4 = r1*2;
	//int &ss=24;

	double dval =3.14;
	const double *cptr = &dval;

}