#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

bool rangeTest(int a)
{
    if(a>=0&&a<=255)
        return true;
    else
        return false;
}

bool check(const char *p) 
{
    if(p == NULL) 
        return false;
    else {
        while(*p != '\0')
            {
            if(*p <= '9' && *p++ >= '0')
                continue;
            else 
                return false;
            }
        }
    return true;
}
int parseIP(char *ip)
{
    char *temp = ip;
    int count = 0;
    int flag = 0;
    char s[4][10];
    int ipNum[4];
    while(*temp != '\0')
    {
        if(*temp=='.')
            count++;
            temp++;
    }
    cout<<count<<endl;
    
    flag = sscanf(ip,"%[^.].%[^.].%[^.].%[^.]",s[0],s[1],s[2],s[3]);
    if(count!=3 || flag!=4)
    {
        cout<<"count or flag error"<<endl;
        return -1;
    }

    for(int i=0;i<4;i++)
    {
        cout<<s[i]<<endl;
        if(!check(s[i]))
        {
            cout<<"IP应该为合法数字！"<<endl;
            return -2;
        }
        ipNum[i]=atoi(s[i]);
    }
    if(!(rangeTest(ipNum[0])&&rangeTest(ipNum[1])&&rangeTest(ipNum[2])&&rangeTest(ipNum[3])))
    {
        cout<<"ip范围出错!"<<endl;
        return -3;
        
    }
    return 0;
}

int main()
{
    char m[40];
    cin>>m;
    parseIP(m);
    return 0;
}
