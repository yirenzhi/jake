#include <iostream>
#include "Salesitem.h"
using namespace std;

void testcin()
{
	int sum=0, value =0;
	//������ʹ��һ��isstream������Ϊ����ʱ����Ч���Ǽ������״̬�����������Ч�ģ�����δ����������ô���ɹ���������
	//�ļ���������end-of-file����������һ����Ч����ʱ����������ֵ������������isstream�����״̬������Ч��

	//���������ļ�������
	//windowsϵͳ�У�����Ctrl+Z  unixϵͳ����Ctrl+D
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
	//int *p3=1;  ����int�����͵�ֵ����������ʼ��ָ��
	int bb=42;
	const int &r1=bb;
	const int &r3=r1*2;
	//int &r4 = r1*2;
	//int &ss=24;

	double dval =3.14;
	const double *cptr = &dval;

}