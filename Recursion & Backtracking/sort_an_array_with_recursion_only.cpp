#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false)
#define endl "\n"
using namespace std;
void insert(vector<int>&v,int last)
{
    if(v.size()==0||v[v.size()-1]<=last)
    {
        v.push_back(last);
        return;
    }

    int val=v.back();
    v.pop_back();
    insert(v,last);
    v.push_back(val);
}

void sorting(vector<int>&v)
{

    if(v.size()==0)
    {  
        return;
    }
    int x=v.back();
    v.pop_back();
    sorting(v);
    insert(v,x);
}

int main()
{
     fast_io;


     vector<int>v={8,7,6,1,2,9,-1};

     sorting(v);
     for(auto it:v)
        cout<<it<<" ";
     
     
     
     return 0;

}

