#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;
bool ld[1000]={false},rd[1000]={false},row[1000]={false};
vector<vector<int>>board={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}
};
int c=0;
bool solve(int j,int n)
{
	if(j>=n)
	{
		c++;
		return true;
	}

	for(int i=0;i<n;i++)
	{

		if(ld[i-j+n-1]==false&&rd[i+j]==false&&row[i]==false)
		{
			board[i][j]=1;
			ld[i-j+n-1]=rd[i+j]=row[i]=true;

		if(solve(j+1,n)==true)
			return true;

		board[i][j]=0;
			ld[abs(i-j)+n-1]=rd[i+j]=row[i]=false;
	
		}

	}
	
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
solve(0,board.size());


for(int it=0;it<board.size();it++)
{
	for(int i=0;i<board[it].size();i++)
	cout<<board[it][i]<<" ";
cout<<endl;
}



return 0;
}