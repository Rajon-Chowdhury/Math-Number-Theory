#include<bits/stdc++.h>
using namespace std;
#define ll long long
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        int a[n+5];
        for(int i=1; i<=n; i++) cin>>a[i];
        int l[n+5],r[n+5];

        l[0]=0;
        for(int i=1; i<=n; i++)
        {
            l[i]=gcd(a[i],l[i-1]);
        }
        r[n+1]=0;
        for(int i=n; i>=1; i--)
        {
            r[i]=gcd(a[i],r[i+1]);
        }
        while(q--)
        {
            int x,y,ans;
            cin>>x>>y;

            ans=gcd(l[x-1],r[y+1]);

            cout<<ans<<endl;
        }

    }
}
