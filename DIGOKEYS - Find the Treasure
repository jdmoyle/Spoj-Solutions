#include <iostream>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;
 
void add_edge(int u,int v,vector<int> adj[])
{
	adj[u].push_back(v);
	//adj[v].push_back(u);
}
 
void bfs(int n,int s,int d,vector<int> adj[])
{
	vector<int> path;
 
	vector<int> dis(n+1,10000000);
 
	vector<int> parent(n+1);
 
	vector<int> visited(n+1,false);
 
	queue<int> q;
	q.push(s);
 
	parent[s]=-1;
	dis[s]=0;
 
	visited[s]=true;
 
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
 
		if(u==d)
		break;
 
		for(int v:adj[u])
		{
			if(visited[v]==false)
			{
				q.push(v);
				visited[v]=true;
 
				int dmin=dis[u]+1;
				if(dmin<dis[v])
				{
					dis[v]=dmin;
					parent[v]=u;
				}
 
			}
		}
	}
 
	if(visited[d]==false)
	{
		cout<<-1<<endl;
		return;
	}
 
	cout<<dis[d]<<endl;
 
	for(int v=parent[d];v!=-1;v=parent[v])
	{
		path.push_back(v);
	}
	reverse(path.begin(),path.end());
 
	for(auto it:path)
	{
		cout<<it<<" ";
	}
	cout<<endl;
 
}
 
int main() {
	int t;
	cin>>t;
 
 
 
	while(t--)
	{
		int n;
		cin>>n;
 
		vector<int> adj[n+1];
 
		for(int i=1;i<n;i++)
		{
			int m;
			cin>>m;
			while(m--)
			{
				int v;
				cin>>v;
 
				add_edge(i,v,adj);
			}
			sort(adj[i].begin(),adj[i].end());
		}
 
		bfs(n,1,n,adj);
 
		cout<<endl;
	}
	return 0;
}
