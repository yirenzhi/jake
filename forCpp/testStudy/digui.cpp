#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
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


//链表递归

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

 //递归求链表长度
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

 //尾递归求链表长度
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
	 //常用的std::lambda表达式的语法如下：
	 //[ capture ] ( params ) mutable exception attribute -> ret { body }  (1)     
		// [ capture ] ( params ) -> ret { body }                  (2)     
		// [ capture ] ( params ) { body }                     (3)     
		// [ capture ] { body }                            (4)     

		 //[]      不捕获任何外部变量  
		 //[=]     以值的形式捕获lambda表达式所在函数的函数体中的所有外部变量  
		 //[&]     以引用的形式捕获lambda表达式所在函数的函数体中的所有外部变量  
		 //[a,&b]  按值捕获a，并按引用捕获b  
		 //[=, &a] 以引用的形式捕获a，其余变量以值的形式捕获  
		 //[&， a] 以值的形式捕获a，其余变量以引用的形式捕获  
		 //[this]  按值捕获了this指针 

	 //尾部的()使改lambda可立即执行
	 //前面的lambda表达式产生一个匿名对象，结合后面的()相当于与一个无参的函数调用
	 []{cout<<"hello lambda"<<endl;}();


	 //->string 表示返回类型
	 //接受一个const string 参数
	 string lambda_return = [](const string &str)->string{return "hello "+str;}("zhouda");
	 cout<<lambda_return<<endl;


	 auto func = [](const string &str){return "hello"+str;};
	 cout<<func("abc")<<endl;
	 cout<<func("def")<<endl;

	 //传值方式捕获外部变量
	 //必须加mutable才能修改
	 int total = 0;
	 [total](int num)mutable{total+=num;cout<<total<<endl;}(2);
	 cout<<"capture by value"<<total<<endl;

	 //传址方式
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