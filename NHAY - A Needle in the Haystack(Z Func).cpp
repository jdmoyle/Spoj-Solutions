//Faster than RK Hash

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int Zfunc(string s,int k,vector<int> &z){
	int n=s.size(),ans=0;
	for(int i=1,l=0,r=0;i<n;i++){
		if(i<=r){
			z[i]=min(z[i-l],r-i+1);
		}
		while(i+z[i]<n && s[z[i]]==s[z[i]+i])
		++z[i];
		if(i+z[i]-1>r)
		l=i,r=i+z[i]-1;
		if(z[i]==k){
			ans++;
		}
	}
	return ans;
}
 
int main() {
	int n;
	while(cin>>n){
		string p,s;
		cin>>p>>s;
		s=p+'#'+s;
		vector<int> z(s.size());
		int ans=Zfunc(s,n,z);
		
		if(ans==0)
		cout<<endl;
		else{
			for(int i=n+1;i<s.size();i++){
				if(z[i]==n){
					cout<<i-n-1<<endl;
				}
			}
		}
		
	}
	return 0;
} 
