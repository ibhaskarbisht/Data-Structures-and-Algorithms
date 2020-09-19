#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace std;

int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};
int dis[10][10];
bool visited[10][10];

bool isvalid(int x, int y)
{
	if(x>=1&&x<=8&&y>=1&&y<=8)
		return true;

	if(visited[x][y]==true)
		return false;
	return false;
}

int knight(int a,int b,int x,int y)
{
	dis[a][b]=0;
	visited[a][b]=true;

	queue<pair<int,int>>q;
	q.push(make_pair(a,b));

	while(q.size()!=0)
	{
		int currentx=q.front().first;
		int currenty=q.front().second;
		q.pop();

		if(currentx==x&&currenty==y)
			return dis[x][y];

		for(int i=0;i<8;i++)
		{
			if(isvalid(currentx+dx[i],currenty+dy[i]))
			{
				int x1=currentx+dx[i];
				int y1=currenty+dy[i];

				visited[x1][y1]=true;
				dis[x1][y1]=1+dis[currentx][currenty];
				q.push(make_pair(x1,y1));

				if(x1==x&&y1==y)
					return dis[x1][y1];
			}
		}
	}

}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
	

int t;
cin>>t;
while(t--)
{
	for(int i=1;i<=8;i++)
{
	for(int j=1;j<=8;j++)
	{
		visited[i][j]=false;
		dis[i][j]=-1;
	}
}
int c,d;
char a,b;
cin>>a>>c;
cin>>b>>d;

int x=c,y;
int end1=d,end2;

if(a=='a')
	y=1;
else if(a=='b')
	y=2;
else if(a=='c')
	y=3;
else if(a=='d')
	y=4;
else if(a=='e')
	y=5;
else if(a=='f')
	y=6;
else if(a=='g')
	y=7;
else if(a=='h')
	y=8;


if(b=='a')
	end2=1;
else if(b=='b')
	end2=2;
else if(b=='c')
	end2=3;
else if(b=='d')
	end2=4;
else if(b=='e')
	end2=5;
else if(b=='f')
	end2=6;
else if(b=='g')
	end2=7;
else if(b=='h')
	end2=8;


cout<<knight(x,y,end1,end2)<<endl;


}

	return 0;
}