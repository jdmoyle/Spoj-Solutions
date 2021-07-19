//Warning : not correct for all testcases
//Still got accepted on spoj
/* Does not work for this case
6 6
######
#kkvv#
######
kvv###
##kkv#
######

ans should be 3 5
*/

#include <iostream>
#include<vector>
using namespace std;
const int N=250,M=250;
 
char field[N][M];
int n,m;
bool visited[N][M];
int wolves=0,sheeps=0;
int s,w;
 
bool isValid(int x,int y)
{
	return (x>=0 && y>=0 && x<n && y<m && field[x][y]!='#');
}
 
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
 
void dfs(int u,int v)
{
	visited[u][v]=true;
	
	if(field[u][v]=='v')
	{
		w++;
	}
	if(field[u][v]=='k')
	{
		s++;
	}
	for(int i=0;i<4;i++)
	{
		int x=u+dx[i],y=v+dy[i];
		if(isValid(x,y) && visited[x][y]==false)
		dfs(x,y);
	}
	
}
 
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>field[i][j];
			
			visited[i][j]=false;
			
			if(field[i][j]=='k')
			sheeps++;
			if(field[i][j]=='v')
			wolves++;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		if(visited[i][j]==false && field[i][j]=='k')
		{
			s=0,w=0;
			
			dfs(i,j);
			
			if(s>w)
			wolves-=w;
			else
			sheeps-=s;
		}
	}
	cout<<sheeps<<" "<<wolves<<endl;
	
	return 0;
} 
