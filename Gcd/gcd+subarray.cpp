#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ar[100001] , fre[1000001], ans[1000001];
void func(){
  for(int i=1;i<=1000000;i++){
    for(int j=i;j<=1000000;j+=i)
        ans[j]+=fre[i];
  }
}
int main()
{
    int n,q,k;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>ar[i];
    map<ll,ll>mp;
    for(int i=1;i<=n;i++){
        map<ll,ll>tmp;
        tmp[ar[i]]++;
        if(ar[i]<=1000000)
                fre[ar[i]]++;
        for(auto it=mp.begin();it!=mp.end();it++){
            ll gcd=__gcd(ar[i],it->first);
            if(gcd<=1000000)
               fre[gcd]+=it->second;
            tmp[gcd]+=it->second;
        }
        mp=tmp;

    }
    func();
    cin>>q;
	while(q--)
	cin>>k , cout<<ans[k]<<endl;
}
