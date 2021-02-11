#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll power(ll a,ll n,ll p)
{
    ll res=1;
    while(n)
    {

        if(n%2)
        {
            res=(res*a)%p;
            n--;
        }
        else
        {
            a=(a*a)%p;
            n/=2;
        }

    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    cout<<power(8,n,10)<<endl;
}
