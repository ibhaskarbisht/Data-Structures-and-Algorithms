#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 


using namespace std;


  void addEdge(vector<int>graph[],int a,int b)
  {
    graph[a].push_back(b);
     graph[b].push_back(a);
  }


void dfs(vector<int>adj[],int u,bool visited[],int in[],int low[],int parent[])
{
static int timer=0;

in[u]=low[u]=timer;
timer++;
visited[u]=true;
for(auto it:adj[u])
{
    if(visited[it]==false)
    {
        parent[it]=u;
        dfs(adj,it,visited,in,low,parent);
        low[u]=min(low[u],low[it]);

        if(low[it]>in[u])
            cout<<u<<" "<<it<<endl;

    }
    else if(it!=parent[u])
        low[u]=min(low[u],in[it]);

}

}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
    
   

    int n = 5;
    vector<int> adj[6]; 
    addEdge(adj, 1, 0); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 2, 1); 
    addEdge(adj, 0,3);
    addEdge(adj, 3,4);
 

    int in[n+1];
    int low[n+1];
    bool visited[n+1]={false};
    int parent[n+1]={-1};

   dfs(adj,0,visited,in,low,parent);
  
 


    return 0;
}