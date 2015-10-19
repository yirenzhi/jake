#include <iostream>
#include <fnmatch.h>
using namespace std;
int main()
{
    char *s = "*.*.*";
    char str[20];
    cin>>str;
    int tag;
    tag = fnmatch(s,str,FNM_PATHNAME);
    cout<<tag<<endl;
    return 0;
}

