#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
  
using namespace std;
string words[] = {"caa", "aaa", "aab"};
vector<int>graph[4];
set<int>v;
void add(int a,int b)
{
graph[a].push_back(b);
}

void create(string words[],int n)
{
for(int i=0;i<n-1;i++)
{
    string a=words[i];
    string b=words[i+1];

    for(int j=0;j<min(a.size(),b.size());j++)
    {
        if(a[j]!=b[j])
        {
            add( a[j] -'a',b[j] -'a' );
            v.insert(a[j]-'a');
            v.insert(b[j]-'a');
        

            break;
        }
    }
}

}


    void topsort(int u,bool visited[],stack<int>&s)
    {

visited[u]=true;

        for(auto it:graph[u])
        {
            if(visited[it]==false)
            topsort(it,visited,s);
        }

s.push(u);

    }


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);

create(words,3);

bool visited[4]={false};
stack<int>s;
for(int i=0;i<3;i++)
{
    if(visited[i]==false)
        topsort(i,visited,s);
}
vector<int>a;
for(auto it:v)
a.push_back(it);

for(auto it:a)
{
if(visited[it]==false)
    topsort(it,visited,s);
}


while(s.size()!=0)
{

    cout<<(char) ('a'+s.top())<<" ";
    s.pop();
}
    


    return 0;
}