#include <iostream>
#include<vector>
using namespace std;
 
const int N=1e8;
 
vector<bool> isPrime(N+1,true);
 
vector<pair<int,int>> sieve()
{
	isPrime[0]=isPrime[1]=false;
	for(int i=0;i*i<=N;i++)
	{
		if(isPrime[i])
		{
			for(int j=i*i;j<=N;j+=i)
			{
				isPrime[j]=false;
			}
		}
	}
	
	vector<pair<int, int>> res(N+1);
    long row=1, col=1;
    res[2]=make_pair(row, col);
    col+=1;
    for(long i=3;i<=N;i+=2)
    {
        if(row<col)
        {
            row+=1;
            col=1;
        }
        if(isPrime[i])
        {
            res[i]=make_pair(row,col);
            col+=1;
        }
    }
    return res;
}
 
 
int main() {
	int t;
	cin>>t;
	vector<pair<int,int>> ans=sieve();
	while(t--)
	{
		int n;
		cin>>n;
		if(isPrime[n]==false)
		cout<<-1<<endl;
		else
		cout<<ans[n].first<<" "<<ans[n].second<<endl;
	}
	return 0;
} 
