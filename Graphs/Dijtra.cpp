#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace std;

void addEdge(vector<pair<int,int>>adj[],int a,int b,int c)
{
    adj[a].push_back(make_pair(b,c));
    adj[b].push_back(make_pair(a,c));
}

void dij(vector<pair<int,int>>graph[],int n,int s)
{
    int dis[n+1];
    for(int i=0;i<=n;i++)
        dis[i]=INT_MAX;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push(make_pair(0,s));
    dis[s]=0;

    while(q.size()!=0)
    {
        int v= q.top().second;
        q.pop();

        for(auto it:graph[v])
        {

                int x=it.first;
                int weight=it.second;
                if(dis[x]>dis[v]+weight)
                {
                    dis[x]=dis[v]+weight;
                    q.push(make_pair(dis[x],x));
                }
        }
    }
for(int i=0;i<n;i++)
    cout<<dis[i]<<" ";

    
}





int main()
{

     int V = 9; 
   vector<pair<int,int>>adj[V+1];

    addEdge(adj, 0, 1, 4); 
    addEdge(adj, 0, 7, 8); 
    addEdge(adj, 1, 2, 8); 
    addEdge(adj, 1, 7, 11); 
    addEdge(adj, 2, 3, 7); 
    addEdge(adj, 2, 8, 2); 
    addEdge(adj, 2, 5, 4); 
    addEdge(adj, 3, 4, 9); 
    addEdge(adj, 3, 5, 14); 
    addEdge(adj, 4, 5, 10); 
    addEdge(adj, 5, 6, 2); 
    addEdge(adj, 6, 7, 1); 
    addEdge(adj, 6, 8, 6); 
    addEdge(adj, 7, 8, 7); 

    dij(adj,V,0);

    


    return 0;
}