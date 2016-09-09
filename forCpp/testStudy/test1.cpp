 #include <iostream>
#include <vector>
#include "testThread.h"
 using namespace std;

 //************************************
 // Method:    reverseString
 // FullName:  reverseString
 // Access:    public 
 // Returns:   std::string
 // Qualifier:
 // Parameter: string s
 //************************************

 extern int jiecheng(int n);
 string reverseString(string s) {
	
	 string temp = s;

	 for(int i=0;i<s.length();i++)
	 {
		 temp[i]=s[s.length()-i-1];
		printf("%d   ",&temp[i]);
	 }
	 printf("abc");
	 return temp;

 }

 void testVector()
 {
	 vector <int> vecN;
	 cout<<"before vecN capacity:"<<vecN.capacity()<<endl;

	 vecN.reserve(20);
	 cout<<"after vecN capacity:"<<vecN.capacity()<<endl;

	 cout<<"size"<<vecN.size()<<endl;

	 for (int i=0;i<1000;i++)
	 {
		 vecN.push_back(i);
		 cout<<vecN.size()<<endl;
		 printf("%d\n",&vecN+1);

	 }
	 vecN.clear();
	 cout<<"vecN capacity is "<<vecN.capacity()<<endl;
	 cout<<"vecN size is "<<vecN.size()<<endl;

 }

extern void hannoi(int n,char from,char buffer,char to);
extern void heneita(int n ,char from,char buffer,char to);
extern int feibona(int n);

typedef struct node *linkList;
extern  node* initlinkList(int num[],int length);
extern void printLink(linkList head);

extern int getlengthRecursion(linkList head);

extern int getlengthTailRecursion(linkList head,int *num);

extern void stdForeach();

struct fle
{
	char val;
	int array[];
};

int main()
{
// 	string get = reverseString("hello");
// 	printf("%s",get.c_str());
// 	while(true){
// 
// 	}

	//测试线程
//	testThread::runThread3();

	//cout<<jiecheng(5)<<endl;

	//cout<<"请输入汉诺塔的层数:";
	//int a;
	//cin>>a;
	//hannoi(a,'A','B','C');
	//heneita(a,'A','B','C');

	//feibona(5);

	//测试链表
	//int nums[]={0,1,2,3,4};
	//cout<<"数组长度为："<<sizeof(nums)/sizeof(int)<<endl;
	//linkList list1= initlinkList(nums,sizeof(nums)/sizeof(int));
	//printLink(list1);

	//int len =0;
	//cout<<"递归法求链表长度为:"<<getlengthRecursion(list1)<<endl;

	//cout<<"尾递归求链表长度为:"<<getlengthTailRecursion(list1,&len)<<endl;

	//string 的长度为28
	//string menus[] = {"new","start","regret"};
	//cout<<"长度"<<sizeof(menus)<<endl;
	//cout<<"长度"<<sizeof(menus[0])<<endl;
	//string str = "012345678901234567890123456789012345678901234567890123456789";
	//string *p=&str;
	//cout<<"长度"<<sizeof(str)<<endl;
	//cout<<"长度"<<strlen(str.c_str())<<endl;
	//cout<<"长度"<<sizeof(string)<<endl;
	//cout<<"长度"<<sizeof(&str)<<endl;
	//cout<<"长度"<<sizeof(struct fle)<<endl;
	
	while(true){

	}

	return 0;
}

