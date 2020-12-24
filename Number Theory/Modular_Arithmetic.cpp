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

int main()
{
  bhaskar;

  //Modular Arithmetic is useful when two number are very large
  //if a=10^18 , b= 10^18

  // (a*b)%c=((a%c) * (b%c))%c;

  ll a=1e10,b=1e10,c=1e9+7;
  cout<<( (a%c) * (b%c))%c<<endl;

  
  return 0;
}
