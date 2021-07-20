//DFS with bitmask

#include <bits/stdc++.h>
using namespace std;
 
bitset<1001> mask[1001];
vector<bool> visited;
vector<vector<int>> adj;
 
int n,k;
 
void dfs(int u)
{
	visited[u]=true;
	
	for(int v:adj[u])
	{
		if(!visited[v])
		{
			dfs(v);
		}
		mask[u] |=mask[v];
		mask[u].set(v);
	}
}
 
 
int main() {
	cin>>n>>k;
	adj.resize(n+1);
	
	for(int i=0;i<k;i++)
	{
		int u,v;
		cin>>u>>v;
		
		if(mask[v][u] || u==v)
		cout<<u<<" "<<v<<endl;
		
		else if(mask[u][v]) continue;
		else
		{
			adj[u].push_back(v);
			visited.assign(n+1,false);
			for(int i=1;i<=n;i++)
			{
				if(visited[i]==false)
				{
					dfs(i);
				}
			}
		}
		
	}
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<mask[i]<<endl;
	}
	*/
	cout<<"0 0"<<endl;
	return 0;
} 
