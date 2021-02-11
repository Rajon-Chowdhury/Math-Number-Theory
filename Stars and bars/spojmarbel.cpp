#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll C(int n, int k)
{
    ll res = 1;
    for (ll i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;

    return res;
}
int main()
{
    ll t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ll ans=C(n-1,k-1);
        cout<<ans<<endl;
    }


}
