#include<bits/stdc++.h>

using namespace std;
int main()
{

int n;
cin>>n;
unordered_map<string,vector<int>>m;
for(int i=0;i<n;i++)
{
    string s;
    cin>>s;
    m[s].push_back(i+1);
}
int q;
cin>>q;

for(int i=0;i<q;i++)
{
    int a,b;
    string s;
    cin>>a>>b>>s;

    int lower=lower_bound(m[s].begin(),m[s].end(),a) -m[s].begin();

    int upper=upper_bound(m[s].begin(),m[s].end(),b)-m[s].begin() ;
    cout<<upper-lower<<endl;
}

    
}
