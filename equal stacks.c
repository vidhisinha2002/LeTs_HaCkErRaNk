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
{
    int n1,n2,n3,i,j=0,k=0,s1=0,s2=0,s3=0;
    scanf("%d %d %d",&n1,&n2,&n3);
    int arr1[n1];
    int arr2[n2];
    int arr3[n3];
    for(i=0;i<n1;i++)
    {
        scanf("%d",&arr1[i]);
        s1=s1+arr1[i];
    }
    for(i=0;i<n2;i++)
    {
        scanf("%d",&arr2[i]);
        s2=s2+arr2[i];
    }
    for(i=0;i<n3;i++)
    {
        scanf("%d",&arr3[i]);
        s3=s3+arr3[i];
    }
    i=0;
    while(1)
    {
        if(s1==s2 && s2==s3 && s3==s1)
            break;
        if(s1>=s2 && s1>=s3)
            s1=s1-arr1[i++];
        else if(s2>=s1 && s2>=s3)
            s2=s2-arr2[j++];
        else 
            s3=s3-arr3[k++];
    }
    if(s1==0||s2==0||s3==0)
        printf("0");
    else 
        printf("%d",s1);
    return 0;
    
}
