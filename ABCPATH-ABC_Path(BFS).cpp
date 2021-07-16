//BFS

#include <iostream>
#include<vector>
#include<queue>
using namespace std;

char maze[51][51];
int dis[51][51];

bool isValid(int x,int y,int n,int m)
{
	return (x>=0 && y>=0 && x<n && y<m);
}

int a[8]={0,1,1,-1,-1,0,-1,1};
int b[8]={1,0,1,-1,0,-1,1,-1};


int main() {
	
	int n,m,t=0;
	while(true)
	{
		cin>>n>>m;
		t++;
		if(n==0&&m==0)
		exit(0);
		
		queue<pair<int,int>> q;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>maze[i][j];
				dis[i][j]=0;
				
				if(maze[i][j]=='A') q.push({i,j}),dis[i][j]=1;
			}
		}
		
		while(!q.empty())
		{
			int x=q.front().first,y=q.front().second;
			q.pop();
			for(int i=0;i<8;i++)
			{
				int xx=x+a[i],yy=y+b[i];
				if(isValid(xx,yy,n,m) && maze[xx][yy]==maze[x][y]+1 && dis[xx][yy]<dis[x][y]+1)
				{
					q.push({xx,yy});
					dis[xx][yy]=dis[x][y]+1;
				}
			}
		}
		
		int max=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(max<dis[i][j])
				max=dis[i][j];
			}
		}
		
		cout<<"Case "<<t<<": "<<max<<endl;
	}
	return 0;
}
