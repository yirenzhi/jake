//�ļ�����һ��������Ҫ��������������һ���ļ���
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
//#include <fstream>  
//ofstream         //�ļ�д���� �ڴ�д��洢�豸   
//ifstream         //�ļ����������洢�豸�������ڴ���  
//fstream          //��д�������Դ򿪵��ļ��ɽ��ж�д����
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
	//�����ݶ���vector��
	while (!in.eof())
	{
		in >> temp;
		nums.push_back(temp);
	}
	in.close();//�ر��ļ�������
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