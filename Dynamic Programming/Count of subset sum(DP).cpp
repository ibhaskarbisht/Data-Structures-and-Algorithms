
#include <bits/stdc++.h> 
using namespace std;

void countofsubsetsum(int a[], int n, int sum) 
{ 
int dp[n+1][sum+1];
for(int i=1;i<=sum;i++)
dp[0][i]=0;
for(int i=0;i<=n;i++)
dp[i][0]=1;

for(int i=1;i<=n;i++)
{
    for(int j=1;j<=sum;j++)
    {
        if(a[i-1]<=j)
        {

            dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i-1]]);

                
        }
        else
            dp[i][j]=dp[i-1][j];
    }
}
cout<<"Total number of subsets with sum "<<sum<<"->";
cout<<dp[n][sum];


   
} 

 
int main() 
{ 
    int s[] = {2,3,5,6,8,10}; 
    int divisible=10;
    int n = sizeof(s) / sizeof(s[0]); 
    countofsubsetsum(s, n, divisible); 
} 

