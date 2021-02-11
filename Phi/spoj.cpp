#include<bits/stdc++.h>
using namespace std;
#define ll long long
int phi(int n)
{
    int res=n;
    for(int i=2; i*i<=n; i++)
    {
        if(n%2==0)
        {
            res/=i;
            res*=(i-1);
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1)
        res/=n,res*=(n-1);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=phi(n);
        cout<<ans<<endl;
    }
}
