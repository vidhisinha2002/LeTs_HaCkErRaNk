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
    int n,d,ni;
    int *arr=malloc(sizeof(int)*n);        //old array
    scanf("%d%d",&n,&d);                    //taking n and d
    for(int oi=0;oi<n;oi++)
    {
        scanf("%d",&arr[oi]);                //scanning elements of array
    }
    int *rotatedarray=malloc(sizeof(int)*n);
    for(int oi=0;oi<n;oi++)
    {
         ni=(oi+n-d)%n;                    //getting new index
        rotatedarray[ni]=arr[oi];           //assigning
    }
    for(ni=0;ni<n;ni++)
    {
    printf("%d",rotatedarray[ni]);        //printing new array with new index
    printf(" ");
    }
return 0;
}
