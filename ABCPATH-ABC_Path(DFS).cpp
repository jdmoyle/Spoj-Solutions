//DFS

#include<bits/stdc++.h>
using namespace std;
 
int a[8]={0,1,1,-1,-1,0,-1,1};
int b[8]={1,0,1,-1,0,-1,1,-1};
 
int n,m;
//int x,y;
int dis[51][51];
char maze[51][51];
 
bool isValid(int a,int b)
{
	return (a>=0 && b>=0 && a<n && b<m );
}
 
void dfs(int si,int sj,int dist)
{
	
	int x,y;
	dis[si][sj]=dist+1;
	
	
	for(int i=0;i<8;i++)
	{
		x=si+a[i];
		y=sj+b[i];
		
		if(isValid(x,y)&& maze[x][y]==maze[si][sj]+1 && dis[x][y]<dis[si][sj]+1)
		dfs(x,y,dis[si][sj]);
	}
}
 
 
int main() {
	
	int t=0;
	while(true)
	{
		cin>>n>>m;
		t++;
		
		if(n==0&&m==0)
		exit(0);
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>maze[i][j];
				
				dis[i][j]=0;
				
				//if(maze[i][j]=='A')  dis[i][j]=0;
				
			}
		}
		
		for(int i=0;i<n;i++)
			{
			for(int j=0;j<m;j++)
			{
				if(maze[i][j]=='A'&&dis[i][j]==0)
				dfs(i,j,dis[i][j]);
			}
		}
	
		int max=dis[0][0];
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
