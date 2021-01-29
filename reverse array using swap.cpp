#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
 int main()
 {
     int N;
     cin >> N;
     int arr[N];    //take n
     
     for(int i=0;i<N;i++)
     {
         cin>>arr[i];   //take array input
     }
     int temp;
     for(int i=0,j=N-1;i<N/2;i++,j--)   // i front 0----j back n-1
     {
       temp=arr[i];
       arr[i]=arr[j];   //swap
       arr[j]=temp;  
     }
     for(int i=0;i<N;i++)
     {
         cout<<arr[i]<<" " ;   //display array
     }
     return 0;
 }
 
