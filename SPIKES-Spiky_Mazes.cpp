#include <iostream>
#include<vector>
#include<queue>
using namespace std;
 
int n,m,str;
char maze[40][40];
 
bool isValid(int x,int y)
{
	if(x<0||x>n||y<0||y>m)
	return false;
 
	return true;
}
 
 
bool bfs(vector<int> s,int st)
{
	bool visited[n][m];
 
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			visited[i][j]=false;
		}
	}
 
 
	queue<vector<int>> q;
	q.push(s);
	visited[s[0]][s[1]]=true;
 
	while(!q.empty())
	{
		vector<int> v=q.front();
		q.pop();
 
		if(maze[v[0]][v[1]]=='x')
		return true;
 
 
		int a[]={1,-1,0,0};
		int b[]={0,0,1,-1};
 
 
		for(int k=0;k<4;k++)
		{
			int x=v[0]+a[k];
			int y=v[1]+b[k];
			if(isValid(x,y))
			{
				if(maze[x][y]=='x')
				return true;
				if((visited[x][y]==false))
				{
					if((maze[x][y]=='.'))
					{
						vector<int> temp(2);
						temp[0]=x;
						temp[1]=y;
						q.push(temp);
						visited[x][y]=true;
					}
					else if(maze[x][y]=='s')
					{
						if(st>0)
						{
							vector<int> temp(2);
							temp[0]=x;
							temp[1]=y;
							q.push(temp);
							visited[x][y]=true;
							st--;
						}
						else
						return false;
					}
				}
			}
		}
 
	}
	return false;
}
 
 
void spiky_Mazes(vector<vector<int>> entrance)
{
	for(auto it:entrance)
	{
		if(bfs(it,str/2)==true)
		{
			cout<<"SUCCESS"<<endl;
			return;
		}
 
	}
	cout<<"IMPOSSIBLE"<<endl;
 
}
 
 
int main() {
 
	cin>>n>>m>>str;
 
 
	vector<vector<int>> entrance;
 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>maze[i][j];
			if(maze[i][j]=='@')
			{
				vector<int> temp(2);
				temp[0]=i;
				temp[1]=j;
				entrance.push_back(temp);
			}
		}
	}
	spiky_Mazes(entrance);
 
	return 0;
}
