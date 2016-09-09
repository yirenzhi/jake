#include <iostream>
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

 }