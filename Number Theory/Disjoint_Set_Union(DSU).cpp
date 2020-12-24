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

ll parent[100005];
ll rankk[100005];

void make_parent(int n)
{
    for (int i = 0; i <= n; i++)
        parent[i] = i;
}
int find(int x)
{
    if (x == parent[x])
      return x;

  parent[x]= find(parent[x]);
  return parent[x];
}

void make_union(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x == y)
        return;

    if (rankk[x] > rankk[y])
    {
        parent[y]=x;
    }
    else 
        parent[x]=y;

 if(rankk[x]==rankk[y])
    rankk[y]++;
}

int main()
{
    bhaskar;

    make_parent(5);
    memset(rankk,0,5);
    make_union(0,1);
    make_union(2,3);
    make_union(4,5);

    cout<<find(3)<<endl;


    return 0;
}
