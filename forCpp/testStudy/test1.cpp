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
int main()
{
// 	string get = reverseString("hello");
// 	printf("%s",get.c_str());
// 	while(true){
// 
// 	}

	//²âÊÔÏß³Ì
//	testThread::runThread3();

	cout<<jiecheng(5)<<endl;

	cout<<"ÇëÊäÈëººÅµËþµÄ²ãÊý:";
	int a;
	cin>>a;
	hannoi(a,'A','B','C');
	while(true){

	}

	return 0;
}

