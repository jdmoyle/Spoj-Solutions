//Z func faster than Rk Hash

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int ZFunc(string s,int k,vector<int>& z){
	int n=s.size();
	int ans=0;
	for(int i=1,l=0,r=0;i<n;i++){
		if(i<=r)
		z[i]=min(r-i+1,z[l-1]);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]])
		++z[i];
		if(i+z[i]-1>r)
		l=i,r=i+z[i]-1;
		if(z[i]==k)
		ans++;
	}
	return ans;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		string s,p;
		cin>>s>>p;
		int n=p.size();
		s=p+'#'+s;
		int N=s.size();
		vector<int> z(N);
		int ans=ZFunc(s,n,z);
		if(ans==0){
			cout<<"Not Found"<<endl;
		}
		else{
			cout<<ans<<endl;
			for(int i=n+1;i<N;i++){
				if(z[i]==n){
					cout<<i-n<<" ";
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
