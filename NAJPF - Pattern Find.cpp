//Rabin-Karp Algo

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

void RKA(string s,string t){
	const int M=1e9+7;
	const int p=31;
	
	int n=s.size(),m=t.size();
	vector<ll> p_pow(max(n,m),1);
	
	for ( int i=1;i<max(n,m);i++ ){
		p_pow[i]=p_pow[i-1]*p%M;
	}
	
	ll h=0;
	for(int i=0;i<n;i++)
	h=(h+(s[i]-'a'+1)*p_pow[i]%M)%M;
	
	vector<ll> hash(m+1,0);
	for(int i=0;i < m;i++){
		hash[i+1]=(hash[i]+(t[i]-'a'+1)*p_pow[i])%M;
	}
	ll ans=0;
	vector<int> index;
	for(int i = 0;i+n <= m;i++){
		ll currH = (hash[i+n]-hash[i]+M)%M;
		if(currH == h*p_pow[i]%M){
			ans++;
			index.push_back(i+1);
		}
	}
	if(ans==0){
		cout<<"Not Found"<<endl;
	}
	else{
		cout<<ans<<endl;
		for(int it:index){
			cout<<it<<" ";
		}
		cout<<endl;
	}
}

int main() {
	int tc;
	cin>>tc;
	while(tc--){
		string s,t;
		cin>>t>>s;
		RKA(s,t);
		cout<<endl;
	}
	return 0;
}
