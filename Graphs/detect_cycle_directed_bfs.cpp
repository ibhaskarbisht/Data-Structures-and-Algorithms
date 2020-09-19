#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 


using namespace std;
	int distance[5]={0};
	int parent[5]={-1};
	int visited[5]={false};

  void addEdge(vector<int>graph[],int a,int b)
  {
  	graph[a].push_back(b);
  }

bool detect(vector<int>graph[],int a,int v)
{

int degree[v+1]={0};
bool visited[v+1]={false};

for(int i=0;i<v;i++)
{
	for(auto it:graph[i])
	{
		degree[it]++;
	}
}
queue<int>q;
for(int i=0;i<v;i++)
{
	if(degree[i]==0)
		q.push(i);
}
int c=0;
while(q.size()!=0)
{
int current=q.front();
q.pop();

for(auto it:graph[current])
{

	degree[it]--;
if(degree[it]==0)
	{
q.push(it);


	}
c++;
}

}

if(c!=v)return true;
else
return false;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
	

	int V = 4; 
    vector<int> adj[V+1]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 0,3); 
    addEdge(adj, 2, 4); 
  
    if (detect(adj,0,V))
        cout << "Yes"; 
    else
        cout << "No"; 



	return 0;
}