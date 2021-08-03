//faster than RKA Hash
#include <iostream>
#include<vector>
using namespace std;

vector<int> preffixF(string s,vector<int> &pi){
	for(int i=1;i<s.size();i++){
		int l=pi[i-1];
		while(l>0 && s[i]!=s[l]){
			l=pi[l-1];
		}
		if(s[i]==s[l]){
			l++;
		}
		pi[i]=l;
	}
	return pi;
}

int main() {
	int tc;
	cin>>tc;
	while(tc--){
		string t,s;
		cin>>t>>s;
		t=s+'#'+t;
		int n=t.size();
		vector<int> pi(n);
		pi[0]=0;
		pi=preffixF(t,pi);
		bool flag=false;
		int ans=0;
		vector<int> v;
		for(int i=0;i<n;i++){
			if(pi[i]==s.size()){
				ans++;
				v.emplace_back(i-2*s.size()+1);
				flag=true;
			}
		}
		if(flag==false){
			cout<<"Not Found"<<endl;
		}
		else{
			cout<<ans<<endl;
			for(auto it:v){
				cout<<it<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
