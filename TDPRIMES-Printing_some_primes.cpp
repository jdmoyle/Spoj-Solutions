#include <bits/stdc++.h>
 
using namespace std;
#define mx 100000000
 
int a[(mx>>5)+2];
 
bool status(int n,int pos)
{
    return bool(n&1<<pos);
}
 
int sett(int n,int pos)
{
    return n=n|(1<<pos);
}
 
int main()
{
    int n= 100000000;
    vector <int> v;
    for(int i=3;i<=sqrt(n);i+=2)
    {
        if(status(a[i>>5],i&31)==false)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                a[j>>5]=sett(a[j>>5],j&31);
            }
        }
    }
    v.push_back(2);
    for(int i=3;i<=n;i+=2)
    {
        if(status(a[i>>5],i&31)==false)
            v.push_back(i);
    }
    for(int i=0;i<=v.size();i+=100)
        cout<<v[i]<<endl;
    return 0;
}
