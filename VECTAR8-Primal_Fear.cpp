#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define io   ios_base::sync_with_stdio(false);cin.tie(NULL);
const int N= 1e6+5;
typedef long long ll;
 
vector<bool> isPrime(N+1,true);
int cnt[N+1];
 
ll power(ll a,ll b)
{
	if(b==0)
	return 1;
	ll res=1;
	while(b>0)
	{
		if(b&1)
		res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
 
 
void sieve()
{
	isPrime[0]=isPrime[1]=false;
	for(ll i=0;i*i<=N;i++)
	{
		if(isPrime[i])
		{
			for(ll j=i*i;j<=N;j+=i)
			{
				isPrime[j]=false;
			}
		}
	}
}
 
bool check(ll n)
{
	ll temp=n,dig=0;
	while(n>0)
	{
		if(n%10==0)
		return false;
		dig++;
		n=n/10;
	}
 
	ll div=power(10LL,dig-1);
 
	n=temp;
 
	while(n>0)
	{
		n=n%div;
		div/=10;
 
		if(n!=0&&isPrime[n]==false)
		return false;
 
	}
	return true;
}
 
void PrimalFear()
{
	for(ll i=2;i<=N;i++)
	{
		cnt[i]=cnt[i-1];
		if(isPrime[i]==true)
		{
			if(check(i))
			{
				cnt[i]++;
			}
		}
	}
}
 
int main() {
	io;
	ll t;
	cin>>t;
	sieve();
	PrimalFear();
 
	while(t--)
	{
		ll n;
		cin>>n;
		ll ans=0;
 
		cout<<cnt[n]<<endl;
	}
	return 0;
}
