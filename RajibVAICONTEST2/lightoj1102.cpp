#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
ll factorial[2000001];

  void factocalculate(){
    factorial[0] = 1;
    for(int i = 1; i <=2000000; i++){
        factorial[i] = factorial[i-1] * i;
        factorial[i] %= M;
    }
}

ll modInverse(ll a,ll m)
{
    int mo = m;
    int y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1){
        int q = a / m;
        int t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

     if (x < 0)
       x += mo;

    return x;
}

int main(){

    ll T,i,n,k,a,b,c,d,x,y;
    factocalculate();
    scanf("%lld",&T);
    for(i=1;i<=T;i++){
      scanf("%lld %lld",&n,&k);
      x=n+k-1, y=k-1;
      a=factorial[x];
      b=(factorial[y]*factorial[x-y])%M;
      c=modInverse(b,1000000007);
      d=(a*c)%M;
     // cout<<a<<b<<c<<d<<endl;
      printf("Case %lld: %lld\n",i,d);
    }
}
