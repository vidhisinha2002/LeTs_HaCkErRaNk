#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
   
int same(char a, char b)
{
    if(a=='['&&b==']')
        return 1;
    if(a=='{'&&b=='}')
        return 1;
    if(a=='('&&b==')')
        return 1;
    return 0;
}

int check(char *a)
{
    char s[1001],top=-1;
    for(int j=0;j<strlen(a);j++)
    {
    if(a[j]=='['||a[j]=='{'||a[j]=='(')
        s[++top]=a[j];
    if(a[j]==']'||a[j]=='}'||a[j]==')') 
    {
        if(top==-1)
            return 0;
        else 
            {
                if(!same(s[top--],a[j]))
                    return 0;
            }
    }   
    }


if(top!=-1)
    return 0;
else 
    return 1;
}


int main()
{
    char a[1001];
    int n,valid;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a);
        valid=check(a);
        if(valid==1)
            printf("YES\n");
        else 
            printf("NO\n");
    }
return 0;
}
 
