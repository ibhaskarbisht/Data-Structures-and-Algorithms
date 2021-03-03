#include<bits/stdc++.h>
using namespace std;




int partitions(int low,int high,int A[])
{
  int p=low,r=high,x=A[r],i=p-1;
  for(int j=p;j<=r-1;j++)
  {
    if (A[j]<=x)
    {

      i=i+1;
      swap(A[i],A[j]);
    }
  }
  swap(A[i+1],A[r]);
  return i+1;
}
int solve(int left,int right,int kth,int A[])
{
  for(;;)
  {
    int pivotIndex=partitions(left,right,A);      //Select the Pivot Between Left and Right
    int len=pivotIndex-left+1;

    if(kth==len)
      return A[pivotIndex];

    else if(kth<len)
      right=pivotIndex-1;

    else
    {
      kth=kth-len;
      left=pivotIndex+1;
    }
  }
}
int main()
{
  int A[10]={1,2,3,4,5,6,7,8,9,10};
int N=10;

if(N%2!=0)
cout<<solve(1,N,N/2,A);
else
{
  cout<<(solve(1,N,(N/2)-1,A) + solve(1,N,N/2,A))/2 ;
}
}