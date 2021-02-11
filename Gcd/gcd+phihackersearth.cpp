#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll phi(ll n)
{
    ll res=n;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            res/=i;
            res*=(i-1);
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1)
        res/=n,res*=(n-1);
    return (res/2)%mod;

}
int main()
{
    ll n;
    cin>>n;
    ll res;
    if(n<=2) res=n-1;
    else res=((n%mod)*phi(n))%mod;
    cout<<res<<endl;
}
