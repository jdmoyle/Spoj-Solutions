//here n<=2,000,000; now the 2,000,000th no. with two prime factors is 10527449;
//so we need minimum 10527449+1 to store the 2,000,000th no.;
//If 10527449 is the biggest no. in range then we have obtain it by 2*p(the biggest prime number to obtain)
//therefore the biggest prime must be greater than 10527449/2=5,265,000.
//The prime no. just greater than 5,265,000 is 5265023. So we take 5,300,000(>5265023) as the upper bound for counting prime numbers;
 
 
#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
#define N (ll)10000000
typedef long long ll;
 
vector<ll> result;
vector<bool> isPrime(10000000,true);
vector<ll> a;
vector<ll> b(11000000);
 
 
void sieve()
{
	//ll N=(ll)sqrt((double)MAX);
	isPrime[0]=isPrime[1]=false;
 
	for(ll i=2;i*i<5300000;i++)
	{
		if(isPrime[i])
		{
			for(ll j=i*i;j<5300000;j+=i)
			{
				isPrime[j]=false;
			}
		}
	}
 
 
	for(ll i=2;i<5300000;i++)
	{
		if(isPrime[i])
		a.push_back(i);
	}
 
 
 
 
 
	for(auto it:a)
	{
		ll k=it;
		for(ll j=it;j<11000000;j+=it)
		{
			if(isPrime[j/k]==true)
			{
				b[j]++;
			}
		}
	}
	for(ll i=4;i<10530000;i++)
	{
		if(b[i]==2)
		{
			result.push_back(i);
			//if(result.size()>=2000000)
			//break;
		}
	}
}
 
 
 
 
int main() {
	int t;
	cin>>t;
	sieve();
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<result[n-1]<<endl;
	}
	return 0;
}
