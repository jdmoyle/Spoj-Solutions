#include <iostream>
#include<vector>
using namespace std;
 
 
const int N=1e6;
 
vector<int> divisor(N+10);
int ans[11][N+10];
 
 
void sieve()
{
	for(int i=2;i<=N;i++)
	{
		if(divisor[i]==0)
		{
			for(int j=i;j<=N;j+=i)
			{
				divisor[j]++;
			}
		}
	}
 
 
	for(int n=0;n<=10;n++)
    {
        for(int i=1;i<=1000000;i++) 
        ans[n][i] = ans[n][i-1] + (bool) ( divisor[i] == n ) ;
    }
}
 
int main() {
	int t;
	cin>>t;
	sieve();
	while(t--)
	{
		int a,b,n;
		cin>>a>>b>>n;
 
			cout<<ans[n][b]-ans[n][a-1]<<endl;
 
	}
	return 0;
}
