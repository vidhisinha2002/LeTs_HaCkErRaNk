#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{int t,arr_count,m;
scanf("%d",&t);
while(t--)  //tb tk turn 0 ni hota
{
scanf("%d",&m);
scanf("%d",&arr_count);
int arr[arr_count];
for(int k=0;k<arr_count;k++)  
{
    scanf("%d",&arr[k]);
}
  
for(int i=0;i<arr_count;i++)
{
    for(int j=i+1;j<arr_count;j++) //2 loop kyuki ek particular instant p have array k do different elements use kre he//j=0 kia to 1221 1441 opp bhi print hoga hme i k bad ka chie
    {
        if(m==arr[i]+arr[j]&&i!=j)//m k = ho or differnt ice cream le
        {
            printf("%d %d\n",i+1,j+1);  //+1 bkx indexng 1 m return krni h
        }
    }
}
}
return 0;
}


