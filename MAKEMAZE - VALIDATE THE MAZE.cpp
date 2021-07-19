#include <iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int N=20,M=20;

char maze[N][M];
int visited[N][M];

int a[4]={1,0,0,-1};
int b[4]={0,1,-1,0};
int n,m;

bool isValid(int x,int y)
{
	return (x>=0 && x<n && y>=0 && y<m);
}
void dfs(int x,int y,int ex,int ey)
{
	visited[x][y]=1;
	if(x==ex && y==ey)
	{
		return;
	}
	
	for(int i=0;i<4;i++)
	{
		int nx=x+a[i],ny=y+b[i];
		if(isValid(nx,ny)==true && maze[nx][ny]!='#' && visited[nx][ny]==0)
		{
			dfs(nx,ny,ex,ey);
		}
	}
	
}


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int c=0;
		char ch;
		
		
		vector<pair<int,int>> entry;
		entry.clear();
		memset(visited,0,sizeof(visited));
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>ch;
				maze[i][j]=ch;
				if(i==0 || i==n-1 || j==0 || j==m-1)
				if(ch=='.')
				{
					c++;
					entry.push_back({i,j});
				}
			}
		}
		if(c!=2)
		{
			cout<<"invalid"<<endl;
		}
		else
		{
			int x=entry[0].first,y=entry[0].second;
			int ex=entry[1].first,ey=entry[1].second;
			
			
			dfs(x,y,ex,ey);
			
			if(visited[ex][ey]==1)
			cout<<"valid"<<endl;
			else
			cout<<"invalid"<<endl;
		}
		
	}
	return 0;
}
