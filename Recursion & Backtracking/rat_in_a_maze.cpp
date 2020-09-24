#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
  
using namespace std;

int sol[4][4]={0};
 vector<vector<int>>maze = { { 1, 0, 0, 0 }, 
		                     { 1, 1, 1, 1 }, 
		                     { 0, 1, 0, 1 }, 
		                     { 1, 1, 1, 1 } }; 

	bool solve(int i,int j,int x,int y)
	{
		
		if(i==x&&j==y)
		{

				sol[i][j]=1;

			 

			return true;
		}	

		if(i>x||j>y||i<0||j<0)
			return false;



		if(maze[i][j]==1&&i>=0&&i<=x&&j>=0&&j<=y)
		{
			maze[i][j]=0;
			sol[i][j]=1;

			if(solve(i+1,j,x,y))
				return true;
			if(solve(i,j+1,x,y))
				return true;
			if(solve(i-1,j,x,y))
				return true;
			if(solve(i,j-1,x,y))
				return true;

			maze[i][j]=1;
			sol[i][j]=0;
		}
		
		return false;
	}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
	
	
		  

		                       solve(0,0,3,3);

		                         for(int i=0;i<4;i++)
		                       {
		                       	for(int j=0;j<4;j++)
		                       		cout<<sol[i][j]<<" ";
		                       	cout<<endl;
		                       }


		                      



	return 0;
}