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

extern  void stdForeach();

extern  void stdLambda();

extern  void stdFunction();

extern  void stdBind();
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

	//�����߳�
//	testThread::runThread3();

	//cout<<jiecheng(5)<<endl;

	//cout<<"�����뺺ŵ���Ĳ���:";
	//int a;
	//cin>>a;
	//hannoi(a,'A','B','C');
	//heneita(a,'A','B','C');

	//feibona(5);

	//��������
	//int nums[]={0,1,2,3,4};
	//cout<<"���鳤��Ϊ��"<<sizeof(nums)/sizeof(int)<<endl;
	//linkList list1= initlinkList(nums,sizeof(nums)/sizeof(int));
	//printLink(list1);

	//int len =0;
	//cout<<"�ݹ鷨��������Ϊ:"<<getlengthRecursion(list1)<<endl;

	//cout<<"β�ݹ���������Ϊ:"<<getlengthTailRecursion(list1,&len)<<endl;

	//string �ĳ���Ϊ28
	//string menus[] = {"new","start","regret"};
	//cout<<"����"<<sizeof(menus)<<endl;
	//cout<<"����"<<sizeof(menus[0])<<endl;
	//string str = "012345678901234567890123456789012345678901234567890123456789";
	//string *p=&str;
	//cout<<"����"<<sizeof(str)<<endl;
	//cout<<"����"<<strlen(str.c_str())<<endl;
	//cout<<"����"<<sizeof(string)<<endl;
	//cout<<"����"<<sizeof(&str)<<endl;
	//cout<<"����"<<sizeof(struct fle)<<endl;
	

	//stdForeach();

	//stdLambda();

	//stdFunction();

	stdBind();
	while(true){

	}

	return 0;
}

