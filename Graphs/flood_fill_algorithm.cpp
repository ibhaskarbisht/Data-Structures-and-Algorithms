#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
  
using namespace std;

vector<vector<int>>screen= {{1, 1, 1, 1, 1, 1, 1, 1}, 
                      {1, 1, 1, 1, 1, 1, 0, 0}, 
                      {1, 0, 0, 1, 1, 0, 1, 1}, 
                      {1, 2, 2, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 2, 2, 0}, 
                      {1, 1, 1, 1, 1, 2, 1, 1}, 
                      {1, 1, 1, 1, 1, 2, 2, 1},}; 

void floodfil(int n,int m,int x,int y,int currentcolor,int newcolor)
{
if(x>=n||x<0||y>=m||y<0)
return;
if(screen[x][y]!=currentcolor)
return;
if(screen[x][y]==newcolor)
	return;

screen[x][y]=newcolor;
floodfil(n,m,x+1,y,currentcolor,newcolor);
floodfil(n,m,x,y+1,currentcolor,newcolor);
floodfil(n,m,x+1,y+1,currentcolor,newcolor);
floodfil(n,m,x-1,y-1,currentcolor,newcolor);
floodfil(n,m,x-1,y,currentcolor,newcolor);
floodfil(n,m,x,y-1,currentcolor,newcolor);

}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);

int x=4,y=4;
int newcolor=3;
int currentcolor=screen[x][y];

floodfil(screen.size(),screen[0].size(),x,y,currentcolor,newcolor);

for(int i=0;i<screen.size();i++)
{
	for(int j=0;j<screen[i].size();j++)
		cout<<screen[i][j]<<" ";
	cout<<endl;
}


	return 0;
}