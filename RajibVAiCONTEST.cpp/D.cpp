#include<bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;

const long m = 2000000;
bool prime[m];
vector<int> p;
void seive()
{
    prime[1]=true;
    for(int i = 2; i * i < m; i++)
    {
        for(int j = 2; i * j < m; j++)
            prime[i*j] = true;
    }
    for(int i = 2; i <= 1000000; ++i)
   {
         if(prime[i]==false)
         p.push_back(i);

   }
}
int main()
{
     seive();
     ll n;

   while(scanf("%lld",&n)==1)
   {
      if(n < 0)
         break;

      for(int i = 0; (i < p.size()) &&
         (p[i] <= n); ++i)
      {
         while(n % p[i]==0)
         {
            printf("    %d\n",p[i]);
            n /= p[i];
         }
      }

      if(n > 1000000)
      printf("    %lld\n",n);

      printf("\n");
   }

   return 0;
}
