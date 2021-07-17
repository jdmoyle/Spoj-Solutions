#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1001;
 
char maze[M][M];
bool visited[M][M];
 
ll cnt;
ll n,m;
 
bool check(ll x,ll  y)
{
	return (x>=0 && y>=0 && x<n && y<m);
}
 
int a[4]={1,0,0,-1};
int b[4]={0,1,-1,0};
 
void dfs(ll u,ll v)
{
	visited[u][v]=true;
	cnt++;
	
	for(int i=0;i<4;i++)
	{
		ll x=u+a[i];
		ll y=v+b[i];
		if(visited[x][y]==false && check(x,y) && maze[x][y]=='#')
		{
			dfs(x,y);
		}
	}
}
 
ll GCD(ll a,ll b)
{
	if(b==0)
	return a;
	
	return GCD(b,a%b);
}

 
int main() {
	
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		
		ll p=0,q=(ll)n*m;
		
		//memset(visited,false,sizeof(visited));
		
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<m;j++)
			{
				cin>>maze[i][j];
				visited[i][j]=false;
				//if(maze[i][j]=='#')
			}
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(visited[i][j]==false && maze[i][j]=='#')
				{
					cnt=0;
					dfs(i,j);
					p+=1LL*cnt*cnt;
				}
			}
		}
		
		
		ll g=GCD(p,q);
		
		p=p/g;
		q=q/g;
		if(q==1)
		{
			cout<<p<<endl;
		}
		else
		cout<<p<<" / "<<q<<endl;
	}
	
	return 0;
} 
