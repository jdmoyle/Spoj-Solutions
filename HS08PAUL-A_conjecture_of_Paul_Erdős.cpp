#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//typedef long long ll;
 
 
vector<bool> sieve()
{
	vector<bool> isPrime(10000000+1,true);
	isPrime[0]=false;
	isPrime[1]=false;
 
	for(int i=2;i*i<=10000000;i++)
	{
		if(isPrime[i])
		{
			for(int j=i*i;j<=10000000;j+=i)
			isPrime[j]=false;
		}
	}
	return isPrime;
}
 
vector<int> solve(vector<bool> isPrime)
{
	vector<int> v;
 
	for(int i=1;i*i<10000000;i++)
	{	
		for(int j=1;j*j*j*j<10000000;j++)
		{
			if(isPrime[i*i+j*j*j*j]==true)
			v.push_back(i*i+j*j*j*j);
		}
	}
 
	sort(v.begin(),v.end());
	unique(v.begin(),v.end());
	return v;
}
 
 
int main() {
	int t;
	cin>>t;
	vector<bool> isPrime=sieve();
	vector<int> v=solve(isPrime);
	while(t--)
	{
		int n;
		cin>>n;
 
		if(n<2)
		cout<<0<<endl;
		else
		{
 
			int low=0,high=v.size()-1,mid;
 
			while(low<high)
			{
				mid=(high+low+1)/2;
				if(v[mid]>n)
				high=mid-1;
				else
				low=mid;
			}
			cout<<low +1<<endl;
		}
	}
	return 0;
}
