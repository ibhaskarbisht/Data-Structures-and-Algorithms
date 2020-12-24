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
ll gcd( ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b)
{
    ll ans=0;
    ans=(a*b)/gcd(a,b);
    return ans;
}
int main()
{
  bhaskar;
   
   cout<<gcd(2,6)<<endl;
     
     cout<<lcm(2,9)<<endl;
  
  return 0;
}
