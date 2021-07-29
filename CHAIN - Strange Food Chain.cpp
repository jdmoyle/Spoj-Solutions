#include<iostream>
#include<vector>
using namespace std;
 
struct DSU{
	int n;
	std::vector<int> parent;
	std::vector<int> dis;
	
	explicit DSU(int x): n(x){
		parent.resize(n);
		dis.resize(n);
		for(int i=0;i<n;i++){
			parent[i]=i;
			dis[i]=0;
		}
	}
	
	int find(int n){
		if(n==parent[n]) return n;
		int p=parent[n];
		parent[n]=find(parent[n]);
		dis[n]+=dis[p];
		return parent[p];
	}
	
	bool unite(int x,int y,int type){
		if (x >= n || y >= n) return true;
		int nx=find(x);
		int ny=find(y);
		int val=((dis[x]-dis[y]-type)%3+3)%3;
		if(nx==ny)
		return val!=0;
		else{
			parent[nx]=ny;
			dis[nx]=3-val;
			return false;
		}
	}
};
 
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		DSU dsu(n);
		int ans=0;
		for(int i=0;i<k;i++){
			int d,x,y;
			cin>>d>>x>>y;
			d--,x--,y--;
			ans+=dsu.unite(x,y,d);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
