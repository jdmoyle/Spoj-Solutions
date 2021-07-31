//O(n);
//NOTE: Using DSU is a faster solution in O(logn);
#include <iostream>
#include<cstring>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int ans[n+1];
	int left[m],right[m],color[m];
	memset(ans,0,sizeof(ans));
	for(int i=0;i<m;i++){
		int l,r,c;
		cin>>l>>r>>c;
		left[i]=l,right[i]=r,color[i]=c;
	}
	//coloring from the last query;
	for(int i=1;i<=n;i++){
		for(int j=m-1;j>=0;j--){
			if(i>=left[j] && i<=right[j]){
				ans[i]=color[j];
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	cout<<ans[i]<<endl;
	return 0;
}
