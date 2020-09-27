#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
  
using namespace std;

void add_edge(vector<int>graph[],int a,int b)
{
graph[a].push_back(b);
graph[b].push_back(a);
}
bool shortest_path(vector<int>graph[],int s,int d,int dis[],bool visited[],int parent[])
{
	visited[s]=true;
	queue<int>q;
	q.push(s);
	dis[s]=0;
	parent[s]=-1;

	

	while(q.size()!=0)
	{
		int current=q.front();
		q.pop();
		for(int i=0;i<graph[current].size();i++)
		{
			if(visited[graph[current][i]]==false)
			{

				visited[graph[current][i]]=true;
				dis[graph[current][i]]=dis[current]+1;
				q.push(graph[current][i]);
				parent[graph[current][i]]=current;

				if(graph[current][i]==d)
					return true;

			}
		}
	}
	return false;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
int n=8;
	vector<int>graph[n];
 	add_edge(graph, 0, 1); 
    add_edge(graph, 0, 3); 
    add_edge(graph, 1, 2); 
    add_edge(graph, 3, 4); 
    add_edge(graph, 3, 7); 
    add_edge(graph, 4, 5); 
    add_edge(graph, 4, 6); 
    add_edge(graph, 4, 7); 
    add_edge(graph, 5, 6); 
    add_edge(graph, 6, 7); 
    int source = 0, destination = 7; 
     int dis[n]={-1};
    bool visited[n]={false};
    int parent[n]={-1};
   	if(shortest_path(graph,source,destination,dis,visited,parent))
   	{
   		int temp=destination;
   		vector<int>path;
   		path.push_back(destination);
   		while(parent[temp]!=-1)
   		{
   			path.push_back(parent[temp]);
   			temp=parent[temp];
   		}
   		reverse(path.begin(),path.end());
   		for(auto it:path)
   			cout<<it<<" ";
   		cout<<endl;

   	}

   	
   		

   		else
   		cout<<"No Path between Source and destination"<<endl;
   




	return 0;
}