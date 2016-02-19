#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int array[]={1,2,3,4,5,6,7,8};
	int count=sizeof(array)/sizeof(int);
	vector<int> vec1(array,array+count);
	for (int i = 0; i < count; ++i)
	{
		cout<<"vec1:"<<vec1[i]<<endl;
		/* code */
	}

	vector<int>::iterator int_ite;
	for (int_ite=vec1.begin() ; int_ite < vec1.end(); ++int_ite)
	{		
		cout<<"vec1:"<<*int_ite<<endl;
	}

	return 0;
}