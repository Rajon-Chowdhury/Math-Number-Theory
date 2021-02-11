#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans[1000010];
int phi[1000010];

void precal(int n)
{
    for(int i=1; i<=n; i++) phi[i]=i;
    for(int i=2; i<=n; i++)
    {
        if(phi[i]==i)
        {
            for(int j=i; j<=n; j+=i)
            {
                phi[j]/=i;
                phi[j]*=i-1;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i)
        {
            ans[j]+=(i*phi[i]);
        }
    }
}

main()
{
    precal(1000000);
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        int res=(ans[n]+1)*n;
        res/=2;
        cout<<res<<endl;
    }

}
