#include <iostream>
#include<algorithm>
using namespace std;
const int N=100000;
const int K=17;
int a[N+1];
int st[N+1][K+1];
 
void store()
{
	for(int i=0;i<=N;i++)
	st[i][0]=a[i];
	
	for(int j=1;j<=K;j++)
	{
		for(int i=0;i+(1<<j)<=N;i++)
		{
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	int Log[N+1];
	Log[1]=0;
	for(int i=2;i<=N;i++){
		Log[i]=Log[i/2]+1;
	}
	
	store();
	
	int q;
	cin>>q;
	
	for(int i=0;i<q;i++)
	{
		int l,r;
		cin>>l>>r;
		int j=Log[r-l+1];
		
		int ans=min(st[l][j],st[r-(1<<j)+1][j]);
		cout<<ans<<endl;
	}
	
	return 0;
} 
