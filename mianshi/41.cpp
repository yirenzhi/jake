//文件中有一组整数，要求排序后输出到另一个文件中
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
//#include <fstream>  
//ofstream         //文件写操作 内存写入存储设备   
//ifstream         //文件读操作，存储设备读区到内存中  
//fstream          //读写操作，对打开的文件可进行读写操作
// http://blog.csdn.net/kingstar158/article/details/6859379
void numsSort(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums.at(i)>nums.at(j))
			{
				//nums.at(i) = nums.at(i) ^ nums.at(j);
				//nums.at(j) = nums.at(j) ^ nums.at(i);
				//nums.at(i) = nums.at(i) ^ nums.at(j);

				//nums.at(i) ^= nums.at(j);
				//nums.at(j) ^= nums.at(i);
				//nums.at(i) ^= nums.at(j);

				nums.at(i) ^= nums.at(j) ^= nums.at(i) ^= nums.at(j);
			}
		}
	}
}
int main()
{
	vector<int> nums;
	ifstream in("data.txt");
	if (!in.is_open())
	{
		cout << "open file error" << endl;
	}
	int temp;
	//将数据读入vector中
	while (!in.eof())
	{
		in >> temp;
		nums.push_back(temp);
	}
	in.close();//关闭文件输入流
	numsSort(nums);
	ofstream out("result.txt");
	if (!out)
	{
		cout << "open result file error" << endl;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		out << nums.at(i) << " ";
	}
	out.close();
	//int a;
	//cin >> a;
	return 0;
}