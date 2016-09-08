#include <iostream>
using namespace std;
//阶乘
int jiecheng(int n)
{

	if (1==n)
	{
		return 1;
	}
	else
	{
		return n*jiecheng(n-1);
	}

}


//和内塔问题

void hannoi(int n,char from,char buffer,char to)
{
	if (1==n)
	{
		cout << "Move disk " << n << " from " << from << " to " << to << endl;
	}
	else
	{
		hannoi (n-1, from, to, buffer);
		cout << "Move disk " << n << " from " << from << " to " << to << endl;
		hannoi (n-1, buffer, from, to);
	}
}