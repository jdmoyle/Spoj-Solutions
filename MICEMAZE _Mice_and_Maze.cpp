#include <iostream>
#include<vector>
#include<queue>
using namespace std;
 
/* we reverse the edges here because we choose the exit cell as the starting cell
it is a directed graph so path will lead to exit cell and from exit cell we may not be able to traverse back the graph
there may be no edges which will help to traverse back to each vertex of the graph
So we reverse the edges and traverse it backwards while storing their weights.
example to check this
5
5
2
6
1 5 1
1 2 1
2 1 1
2 3 1
3 4 1
4 5 1
 
void add_Edge(int u,int v,int w,vector<pair<int,int>> adj[])
{
	adj[u].push_back({v,w});
}
*/
 
void add_Edge(int u,int v,int w,vector<pair<int,int>> adj[])
{
	adj[v].push_back({u,w});
}
 
void bfs(int s,int n,int t,vector<pair<int,int>> adj[])
{
	vector<bool> visited(n+1,false);
 
	queue<int> q;
	q.push(s);
 
	vector<int> d(n+1,10000000);
 
	visited[s]=true;
 
	d[s]=0;
 
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
 
 
 
		for(auto u:adj[v])
		{
			if(visited[u.first]==false)
			{
				q.push(u.first);
 
				int m=d[v]+u.second;
				if(m<d[u.first])
				d[u.first]=m;
 
				visited[v]=true;
			}
		}
 
	}
 
	int c=0;
 
	for(int i=1;i<=n;i++)
	{
		//cout<<d[i]<<" ";
		if(d[i]<=t)
		c++;
	}
	//cout<<endl;
	cout<<c<<endl;
}
 
 
int main() {
 
	int num,exit_p,time_t,edges;
	cin>>num>>exit_p>>time_t>>edges;
 
	vector<pair<int,int>> adj[num+1];
 
 
	while(edges--)
	{
		int a,b,w;
		cin>>a>>b>>w;
 
		add_Edge(a,b,w,adj);
 
	}
 
	bfs(exit_p,num,time_t,adj);
 
	return 0;
}
