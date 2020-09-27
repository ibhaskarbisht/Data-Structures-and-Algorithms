#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
  
using namespace std;


int ans=0;
int parent[100004];
int sz[1000004];
  int find(int a)
    {
        if(parent[a]==a)
            return a;

        else
        return parent[a]=find(parent[a]);
    }
    
    void Union(int a,int b)
    {
        int x=find(a);
        int y=find(b);
        
        
        if(sz[x]<sz[y])
        {
            parent[x]=y;
            sz[y]+=sz[x];
        }
        else
        {
            parent[y]=x;
            sz[x]+=sz[y];
        
        }     
        
    }

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
int n,m;
cin>>n>>m;

vector<pair<int,pair<int,int>>>v;
for(int i=0;i<=n;i++)
{
    parent[i]=i;
    sz[i]=1;
}
for(int i=0;i<m;i++)
{
    int a,b,w;
    cin>>a>>b>>w;
    v.push_back(make_pair(w,make_pair(a,b)));
}
sort(v.begin(),v.end());
int count=0;
for(auto it:v)
{

    int w=it.first;
    int x=it.second.first;
    int y=it.second.second;

    if(find(x)!=find(y))
    {
        Union(x,y);
        count++;
        ans=ans+w;
    }
    if(count>n-1)
    break;

}

cout<<ans<<endl;



    


    return 0;
}