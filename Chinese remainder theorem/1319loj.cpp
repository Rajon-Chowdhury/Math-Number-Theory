
// A C++ program to demonstrate working of Chinise remainder
// Theorem
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Returns modulo inverse of a with respect to m using extended
// Euclid Algorithm. Refer below post for details:
// https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
ll inv(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    // Apply extended Euclid Algorithm
    while (a > 1)
    {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}


ll findMinX(ll num[], ll rem[], ll k)
{
    // Compute product of all numbers
    ll prod = 1;
    for (ll i = 0; i < k; i++)
        prod *= num[i];

    // Initialize result
    ll result = 0;

    // Apply above formula
    for (ll i = 0; i < k; i++)
    {
        ll pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }

    return result % prod;
}


int main()
{
    ll t,cs=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll num[15],rem[15];
        for(ll i=0; i<n; i++)
            cin>>num[i]>>rem[i];
        ll ans=findMinX(num, rem, n);
        cout<<"Case "<<cs++<<": "<<ans<<endl;
    }

}
