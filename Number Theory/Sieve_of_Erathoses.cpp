#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define pb push_back
#define mp make_pair
#define bhaskar ios_base::sync_with_stdio(false)
#define endl "\n"
using namespace std;

bool prime[10000005];
void sieve()
{
    for(int i=2;i<=sqrt(10000005);i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=(10000005);j=j+i)
            {
                prime[j]=false;
            }
        }
    }
}

int main()
{
  bhaskar;
   
   memset(prime,true,10000005);
   sieve(); 
  for(int i=1;i<=100;i++)
  {
    if(prime[i])
        cout<<i<<" ";
  }
  
  return 0;
}
