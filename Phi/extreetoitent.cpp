#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll phi[10001];
void func()
{
    int mx=10000;
    for(int i=1; i<=mx; i++)
        phi[i]=i;
    for(int i=2; i<=mx; i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<=mx; j+=i)
            {
                phi[j]/=i,phi[j]*=(i-1);
            }
        }
    }
    for(int i=1; i<=mx; i++)
    {
        phi[i]+=phi[i-1];
    }
}
int main()
{
    int t,n;
    cin>>t;
    func();
    while(t--)
    {
        cin>>n;
        ll ans=phi[n]*phi[n];
        cout<<ans<<endl;
    }
}
