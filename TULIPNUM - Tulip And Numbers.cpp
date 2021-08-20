#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int main() {
	
	
	int tc,n,x,y,q,one = 1;
	cin>>tc;
	
	for(int t = 1; t<=tc;t++){
		scanf("%d",&n);
		scanf("%d",&q);
		
		scanf("%d",&x);
		int dp[n+1]={0};
		dp[1] = 1;
		int y;
		for(int i = 2; i<=n ; i++){
			scanf("%d",&y);
			if(i<2) continue;
			if( x != y){
				dp[i] = dp[i-1] +1;
			}else dp[i] = dp[i-1];
			x=y;
		}
		
		printf("Case %d:\n",t);
		if(n == 1){
			printf("%d\n",one);
			continue;
		}
		
		
		int l,r;
		for(int i = 0; i<q;i++){
			scanf("%d%d",&l,&r);
			if(dp[l] == dp[l-1]) printf("%d\n",dp[r]-dp[l-1]+1);
			else{
				int ans = dp[r] - dp[l-1];
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
