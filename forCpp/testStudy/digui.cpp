#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;
//�׳�
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


//����������

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


void heneita(int n ,char from,char buffer,char to)
{
	if (1==n)
	{
		cout<<"Move disk"<<n<<" from "<<from<<" to "<<to<<endl;
	}
	else
	{
		heneita(n-1,from,to,buffer);
		cout<<"Move disk"<<n<<" from "<<from<<" to "<<to<<endl;
		heneita(n-1,buffer,from,to);
	}
}

int feibona(int n)
{
	if (1==n)
	{
		return 1;
	}
	else
	{
		return feibona(n-1)+feibona(n-2);
	}
}


//����ݹ�

typedef struct node
{
	int data;
	struct node* next;
}*linkList;

 node* initlinkList(int num[],int length)
{
	if (length<1)
	{
		return NULL;
	}

	node* headnode = (node*) malloc(sizeof(node));
	headnode->data=num[0];
	headnode->next=NULL;
	if (length>1)
	{
		node* p = headnode;
		for (int i = 1; i < length; i++)
		{
			node* newnode = (node*) malloc(sizeof(node));
			newnode->data=num[i];
			newnode->next=NULL;
			p->next=newnode;
			p=newnode;
		}
	}
	return headnode;
}

 void printLink(linkList head)
 {
	 while (head!=NULL)
	 {
		 cout<<head->data<<endl;
		 head=head->next;
	 }
 }

 //�ݹ���������
 int getlengthRecursion(linkList head)
 {
	 if (head!=NULL)
	 {
		 return getlengthRecursion(head->next)+1;
	 }
	 else
	 {
		 return 0;
	 }
 }

 //β�ݹ���������
 int getlengthTailRecursion(linkList head,int *num)
 {
	 if (NULL==head)
	 {
		 return *num;
	 }
	 else
	 {
		 *num = *num + 1;
		 return getlengthTailRecursion(head->next,num);
	 }

 }


 //test std::for_each
 void stdForeach()
 {
	 vector<int> nums;
	 for (int i=0;i<5;i++)
	 {
		 nums.push_back(i);
	 }
	 std::for_each(nums.begin(),nums.end(),[](int x){cout<<x<<"\t";});
	 cout<<endl;

	 std::for_each(nums.begin(),nums.end(),[](int&x){x++;});
	 std::for_each(nums.begin(),nums.end(),[](int x){cout<<x<<"\t";});
	 cout<<endl;

 }


 //test std::lambda
 void stdLambda()
 {
	 //���õ�std::lambda���ʽ���﷨���£�
	 //[ capture ] ( params ) mutable exception attribute -> ret { body }  (1)     
		// [ capture ] ( params ) -> ret { body }                  (2)     
		// [ capture ] ( params ) { body }                     (3)     
		// [ capture ] { body }                            (4)     

		 //[]      �������κ��ⲿ����  
		 //[=]     ��ֵ����ʽ����lambda���ʽ���ں����ĺ������е������ⲿ����  
		 //[&]     �����õ���ʽ����lambda���ʽ���ں����ĺ������е������ⲿ����  
		 //[a,&b]  ��ֵ����a���������ò���b  
		 //[=, &a] �����õ���ʽ����a�����������ֵ����ʽ����  
		 //[&�� a] ��ֵ����ʽ����a��������������õ���ʽ����  
		 //[this]  ��ֵ������thisָ�� 

	 //β����()ʹ��lambda������ִ��
	 //ǰ���lambda���ʽ����һ���������󣬽�Ϻ����()�൱����һ���޲εĺ�������
	 []{cout<<"hello lambda"<<endl;}();


	 //->string ��ʾ��������
	 //����һ��const string ����
	 string lambda_return = [](const string &str)->string{return "hello "+str;}("zhouda");
	 cout<<lambda_return<<endl;


	 auto func = [](const string &str){return "hello"+str;};
	 cout<<func("abc")<<endl;
	 cout<<func("def")<<endl;

	 //��ֵ��ʽ�����ⲿ����
	 //�����mutable�����޸�
	 int total = 0;
	 [total](int num)mutable{total+=num;cout<<total<<endl;}(2);
	 cout<<"capture by value"<<total<<endl;

	 //��ַ��ʽ
	 [&total](int num){total+=num;cout<<total<<endl;}(2);
	 cout<<"capture by reference"<<total<<endl;

	 vector <int> numss(1);
 }

 void stdFunction()
 {
	 vector<int> vecInt;
	 for (int i=0;i<5;i++)
	 {
		 vecInt.push_back(i);
	 }
	 function<void(int)> func = [](int val){cout<<val+2<<endl;};
	 for_each(vecInt.begin(),vecInt.end(),func);
 }

 void print_add(int value,int num)
 {
	 cout<<value+num<<endl;
 }
 void stdBind()
 {
	vector<int> vecInt;
	for (int i=0;i<5;i++)
	{
		vecInt.push_back(i);
	}

	auto func = std::bind(print_add,std::placeholders::_1,222);
	for_each(vecInt.begin(),vecInt.end(),func);

	for_each(vecInt.begin(),vecInt.end(),std::bind(print_add,std::placeholders::_1,333));

 }