#include <iostream>
using namespace std;
typedef long long ll;
#define MOD (ll)1000000007

void multiply(ll M[2][2],ll F[2][2])
{
	ll x=(F[0][0]*M[0][0])%MOD+(F[0][1]*M[1][0])%MOD;
	ll y=(F[0][0]*M[0][1])%MOD+(F[0][1]*M[1][1])%MOD;
	ll z=(F[1][0]*M[0][0])%MOD+(F[1][1]*M[1][0])%MOD;
	ll t=(F[1][0]*M[0][1])%MOD+(F[1][1]*M[1][1])%MOD;
	
	F[0][0]=x%MOD;
	F[0][1]=y%MOD;
	F[1][0]=z%MOD;
	F[1][1]=t%MOD;
	
}

void power(ll n,ll F[2][2])
{
	ll M[2][2]={{1,1},{1,0}};
	
	if(n==0||n==1)
	return;
	
	power(n>>1,F);
	
	multiply(F,F);
	if(n&1)
	{
		multiply(M,F);
	}
}

ll fib(ll n)
{
	ll F[2][2]={{1,1},{1,0}};
	if(n==0)
	return 0;
	
	power(n-1,F);
	return F[0][0];
}

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		
		ll result=(fib(m+2)-fib(n+1))%MOD;
		
		//in case the mod of fib(m+2)>fib(n+1);
		if(result<0)
		result+=MOD;
		cout<<result<<endl;
	}
	return 0;
}
