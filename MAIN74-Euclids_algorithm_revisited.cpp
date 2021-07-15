#include <iostream>
using namespace std;
typedef unsigned long long llu;
#define mod (llu)1000000007
 
void multiply(llu F[2][2],llu M[2][2])
{
	llu x=(F[0][0]*M[0][0])%mod+(F[0][1]*M[1][0])%mod;
	llu y=(F[0][0]*M[0][1])%mod+(F[0][1]*M[1][1])%mod;
	llu z=(F[1][0]*M[0][0])%mod+(F[1][1]*M[1][0])%mod;
	llu w=(F[1][0]*M[0][1])%mod+(F[1][1]*M[1][1])%mod;
 
	F[0][0]=x%mod;
	F[0][1]=y%mod;
	F[1][0]=z%mod;
	F[1][1]=w%mod;
}
 
void power(llu n,llu F[2][2])
{
	llu M[2][2]={{1,1},{1,0}};
 
	if(n==0||n==1)
	return;
 
	power(n>>1,F);
	multiply(F,F);
	if(n&1)
	multiply(F,M);
}
 
llu fib(llu n)
{
	llu F[2][2]={{1,1},{1,0}};
 
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
		llu n;
		cin>>n;
 
		if(n==0)
		{
			cout<<0<<endl;
		}
		else if(n==1)
		{
			cout<<2<<endl;
		}
		else
		{
			llu f1=fib(n+3);
			cout<<f1<<endl;
		}
	}
 
	return 0;
}
