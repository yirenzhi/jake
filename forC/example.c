#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char from[40],to[40];
    int i;
    printf("please input string:\n");
    scanf("%s",from);
    for (i=0;i<=strlen(from);i++)
        to[i]=from[i];
    printf("the copy string is:%s\n",to);
    return 0;
}
