#include <iostream>
#include<algorithm>
using namespace std;
 
const int N=50000;
const int K=15;
int st[N+1][K+1];
int hills[N];
int Log[N+1];
 
void sparseTable()
{
	for(int i=0;i<=N;i++)
	st[i][0]=hills[i];
	
	for(int j=1;j<=K;j++)
	{
		for(int i=0;i+(1<<j)<=N;i++)
		{
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
 
int main() {
	int n,m;
	cin>>n>>m;
	
	
	for(int i=0;i<n;i++){
		cin>>hills[i];
	}
	
	Log[1]=0;
	for(int i=2;i<=N;i++)
	{
		Log[i]=Log[i/2]+1;
	}
	
	sparseTable();
	
	int ans=0;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		if(a==b) continue;
		a--,b--;
		
		//using abs() for b<a
		int j=abs(b-a);
		int m=hills[a];
		
		//it doesnot matter if b has a higher hill ,,
		//check till b-1;
		if(m>=max(st[a][Log[j]],st[b-(1<<Log[j])][Log[j]]))
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}  
