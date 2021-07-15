#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
 
#define N (ll)1e5
 
vector<bool> isPrime(N+1,true);
vector<ll> v;
vector<ll> cnt(N+1,0);
 
void sieve()
{
	
	for(ll i=2;i*i<=N;i++)
    {
        if(isPrime[i])
        {
            for(ll j=i*i;j<=N;j+=i)
            {
                isPrime[j]=false;
            }
        }
        
    }
    int c=0;
    for(ll i=2;i<=N;i++)
    {
    	if(isPrime[i])
    	{
    		v.push_back(i);
    		c++;
    	}
    	cnt[i]=c;
    }
	
}
 
 
int main() {
	ll t;
	cin>>t;
	sieve();
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		
		if(n<4)
		{
			cout<<"0 0"<<endl;
		}
		else
		{
			ll sqrtn=(ll)sqrt((double)n);
			ll sqrtk=(ll)sqrt((double)k);
			ll choices=cnt[sqrtn];
			ll likes=choices-cnt[sqrtk];
			
			if(k>n)
			likes=0;
			
			cout<<choices<<" "<<likes<<endl;
		}
	}
	return 0;
} 
