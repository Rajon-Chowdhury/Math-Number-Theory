#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000003
ll factorial[M];

  void factocalculate(){
    factorial[0] = 1;
    for(int i = 1; i <=1000000; i++){
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

int main()
{
    ll T,n,k,a,b,c,d;
    factocalculate();
    scanf("%lld",&T);

    for(ll i=1;i<=T;i++){
     scanf("%lld %lld",&n,&k);
       a=factorial[n];
       b=(factorial[k]%M*factorial[n-k]%M)%M;
       c=modInverse(b,1000003);
       d=(a%M*c%M)%M;
       printf("Case %lld: %lld\n",i,d);
}
}
