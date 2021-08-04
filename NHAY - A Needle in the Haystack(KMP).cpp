
//KMP is faster than Z func and RK Hash

#include <iostream>
#include<vector>
using namespace std;

bool KMP(string s,int k,vector<int> &pi){
	int n=s.size();
	bool  flag=false;
	for(int i=1;i<n;i++){
		int l=pi[i-1];
		while(l>0 && s[i]!=s[l])
		l=pi[l-1];
		if(s[i]==s[l])
		l++;
		pi[i]=l;
		if(l==k) flag=true;
	}
	return flag;
}

int main() {
	int n;
	while(cin>>n){
		string p,s;
		cin>>p>>s;
		s=p+'#'+s;
		int N=s.size();
		vector<int> pi(N);
		pi[0]=0;
		if(KMP(s,n,pi)){
			for(int i=n+1;i<N;i++){
				if(pi[i]==n)
				cout<<i-2*n<<endl;
			}
		}
		else
		cout<<endl;
	}
	return 0;
}
