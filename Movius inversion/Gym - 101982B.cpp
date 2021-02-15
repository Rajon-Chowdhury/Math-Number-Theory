#include<bits/stdc++.h>
using namespace std;
const int mx=1e7+5;
long long mob[mx];
int v[mx];

void func(){
    for(int i=1;i<=mx;i++) mob[i]=1;
    for(int i=2;i<=mx;i++){
        if(v[i]) continue;
        mob[i]=-1;
        for(int j=2*i;j<=mx;j+=i){
          v[j]=1;
          if((j/i)%i==0) mob[j]=0;
          else mob[j]*=-1;
        }
    }
}
long long cal(int n,int m){
   int mn=min(n,m);
   long long  res=0;

   for(int i=1;i<=mn;i++)
    res+=(long long)mob[i]*(n/i)*(m/i);
   return res;
}
int main(){
       int a,b,c,d;
       scanf("%d%d%d%d",&a,&b,&c,&d);
       func();
       printf("%lld",cal(b,d)-cal(a-1,d)-cal(b,c-1)+cal(a-1,c-1));

}
