#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int n,m;
 
vector<vector<int>> adj;
vector<int> tin,low,vis,cnt;
int ind=0,timer=0;
map<pair<int,int>,int> bridges;
 
void Find_Bridges(int u,int p = -1){
	vis[u] = 1;
	low[u] = tin[u] = timer++;
	for(int v:adj[u]){
		if( p == v) continue;
		if(vis[v]){
			low[u] = min(low[u],tin[v]);
		}else{
			Find_Bridges(v,u);
			low[u] = min(low[u],low[v]);
			if(tin[u] < low[v]) bridges[{u,v}]++;
		}
	}
}
 
void dfs(int u,int p=-1){
	vis[u] = 1;
	cnt[ind]++;
	for(auto v:adj[u]){
		if(vis[v] == false && !bridges[{u,v}]){
			dfs(v,u);
		}
	}
}
 
 
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	adj.resize(n+1);
	vis.assign(n+1,0);
	low.assign(n+1,-1);
	tin.assign(n+1,-1);
	cnt.resize(n+1);
	
	for(int i = 0; i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	Find_Bridges(1);
	
	vis.assign(n+1,0);
	for(int i = 1; i<n+1;i++){
		ind++;
		dfs(i);
	}
	
	ll ways=0;
	
	for(int i = 1; i<=n;i++){
		if(cnt[i] == 0) break;
		ways += (1LL*cnt[i]*(cnt[i]-1))/2;
	}
	
	ll t = (1LL*n*(n-1))/2;
	double ans = (1.0*ways/t);
	ans = 1.0-ans;
	cout<<fixed<<setprecision(5)<<ans<<endl;
	
	return 0;
} 
