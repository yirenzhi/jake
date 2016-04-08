#include <iostream>
using namespace std;
int main()
{
	for (int i = 1; i <= 500; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			cout << "very good" << endl;
		else if (i % 3 == 0)
			cout << "very" << endl;
		else if (i % 5 == 0)
			cout << "good" << endl;
		else
			cout << i << endl;
	}

	return 0;
}