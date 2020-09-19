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


	queue<int>q;
	q.push(a);
	visited[a]=true;

	while(q.size()!=0)
	{
		int current=q.front();
		q.pop();

		for(auto it:graph[current])
		{
			if(visited[it]==false)
			{
				visited[it]=true;
				q.push(it);
				parent[it]=current;
			}
			else if(parent[it]!=current)
				return true;
		}
	}
return false;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
	

	int V = 4; 
    vector<int> adj[V]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 2, 4); 
    addEdge(adj, 2, 3); 
  
    if (detect(adj,0,V))
        cout << "Yes"; 
    else
        cout << "No"; 



	return 0;
}