#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
const ll p=31;
const ll m=1e9+7;
 
void RKA(string s, string  t) {
	int S=s.size(),T=t.size();
	vector<ll> p_pow(max(S,T),1);
 
	for(int i=1;i<max(S,T);i++)
	p_pow[i]=p_pow[i-1]*p%m;
 
	ll h=0;
	for(int i=0;i<S;i++){
		h=(h+(s[i]-'a'+1)*p_pow[i])%m;
	}
	vector<ll> hash(T+1,0);
	for(int i=0;i<T;i++){
		hash[i+1]=(hash[i]+(t[i]-'a'+1)*p_pow[i])%m;
	}
	bool flag = false;
	for(int i=0;i+S-1<T;i++){
		ll currH=(hash[i+S]-hash[i]+m)%m;
		if(currH==h*p_pow[i]%m){
			flag = true;
			cout<< i <<endl;
		}
	}
	if(flag==false)
	cout<<endl;
}
 
int main() {
	int n;
	string s1,s2;
	while(cin>>n){
		cin>>s1>>s2;
		RKA(s1,s2);
	}
 
	return 0;
}
