#include <iostream>
using namespace std;
int main()
{
	int n=[](int x,int y){return x+y;}(5,4);
	cout<<n<<endl;
//	auto f=[](int x,int y){return x+y;};
	int m=[](int x ,int y){return x+y;}(2,3);
	cout<<m<<endl;

	int b=[](int x){return [](int y){return y*2;}(x)+3;}(5);
	cout<<b<<endl;
}