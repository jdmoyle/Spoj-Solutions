//faster than ZFunc and RKA Hash
#include <iostream>
#include<vector>
using namespace std;

int preffixF(string s,int k,vector<int> &pi){
	int ans=0;
	for(int i=1;i<s.size();i++){
		int l=pi[i-1];
		while(l>0 && s[i]!=s[l]){
			l=pi[l-1];
		}
		if(s[i]==s[l]){
			l++;
		}
		pi[i]=l;
		if(l==k){
			ans++;
		}
	}
	return ans;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--){
		string t,s;
		cin>>t>>s;
		t=s+'#'+t;
		int n=t.size();
		int k=s.size();
		vector<int> pi(n);
		pi[0]=0;
		int ans=preffixF(t,k,pi);
		if(ans==0){
			cout<<"Not Found"<<endl;
		}
		else{
			cout<<ans<<endl;
			for(int i=k+1;i<n;i++){
				if(pi[i]==k)
				cout<<i-2*k+1<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}
