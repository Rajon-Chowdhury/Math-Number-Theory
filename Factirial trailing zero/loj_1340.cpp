#include<bits/stdc++.h>
using namespace std;
const int MOD=10000019;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpll vector<pll>
#define vpii vector<pii>
#define umap unordered_map
#define uset unordered_set
#define PQ priority_queue
///
/*
ll power(ll x, unsigned int y)
{
    ll temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}
*/
inline ll getFirstSetBitPos(int n) { return log2(n & -n) + 1; }
inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n|(1LL<<i); }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }

inline void normal(ll &a){a %= MOD;(a < 0) && (a += MOD);}
inline ll modMul(ll a, ll b){a %= MOD, b %= MOD;normal(a), normal(b);return (a*b)%MOD;}
inline ll modAdd(ll a, ll b){a %= MOD, b %= MOD;normal(a), normal(b);return (a+b)%MOD;}
inline ll modSub(ll a, ll b){a %= MOD, b %= MOD;normal(a), normal(b);a -= b;normal(a);return a;}
inline ll modPow(ll b, ll p){ll r = 1;while(p){if(p&1)r = modMul(r, b);b = modMul(b, b);p >>= 1;}return r;}
inline ll modInverse(ll a){return modPow(a, MOD-2);}
inline ll modDiv(ll a, ll b){return modMul(a, modInverse(b));}

#define mxx 1000006
bitset <mxx> mark;
vector <int> primes;
int ans[mxx];

void sieve() {
    mark[0] = mark[1] = 1;
    primes.push_back(2);
    int lim = sqrt(mxx * 1.0) + 2;
    for (int i = 4; i < mxx; i += 2) mark[i] = 1;
    for (int i = 3; i < mxx; i += 2) {
        if (!mark[i]) {
            primes.push_back(i);
            if (i <= lim)
                for (int j = i * i; j < mxx; j += i)
                    mark[j] = 1;
        }
    }
}
ll find_fre(ll n,ll p){
    ll cnt=0;
    while(n){
       cnt+=n/p;
       n/=p;
    }
    return cnt;
}
int main(){
     sieve();
     int sz=primes.size();
     int t;
     scanf("%d",&t);
     for(int i=1;i<=t;i++){
        ll n,k;
        scanf("%lld%lld",&n,&k);
        ll ans=1;
        for(int i=0;i<sz;i++){
            ll pr=primes[i];
            ll cur=find_fre(n,pr);
            if(cur<k) break;
            ans=modMul(ans,modPow(pr,cur/k));
        }
        if(ans==1) ans=-1;
        printf("Case %d: %lld\n",i,ans);
     }
}
