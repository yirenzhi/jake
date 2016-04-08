#include <iostream>
#include <vector>
using namespace std;

int isPrime(int num)
{
	for (int i = 2; i <= num/2; i++)
	{
		if (num%i==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int N;
	cin >> N;
	int sum=0;
	vector<int> nums;
	for (int i = 2; i <= N; i++)
	{
		//ÅÐ¶ÏÊÇ·ñËØÊý
		if (isPrime(i))
		{
			nums.push_back(i);
		}
	}

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums.at(i)-nums.at(i-1)==2)
		{
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}

