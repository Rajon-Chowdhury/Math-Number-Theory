#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll C(int n, int k)
{
    ll res = 1;
    for (ll i = 1; i <= k; ++i){
        res = res * (n - k + i) / i;
        res%=mod;
    }

    return res%mod;
}
int main()
{
    ll t=1,n,m;

    while(t--)
    {
        cin>>n>>m;
        ll ans=C(n+2*m-1,2*m);
        cout<<ans<<endl;
    }


}

