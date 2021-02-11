#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const long m = 2000000;
bool prime[m];
ull pr,in=1000000000000000000;

void calculation(int n,int o){
      int u,j,p[10000] = {};
      pr=1;
     for(int i=n;i>=0;i=i-o){
          u = i;
            for(j = 2; j <= u; j++) {
                while(u%j == 0){
                    u =u/j;
                    p[j]=p[j]+1;}
            }
     }
     double s=0;
     for(int z=1;z<=n;z++){
         pr=pr*(p[z]+1);
         s+= log10(p[z]+1);
         }
      if(ceil(s)>18)
       cout<<"Infinity"<<endl;
      else
          printf("%lld\n",pr);
     }



int main(){
      int n,d,T,i;
      string s;
      cin>>T;
      for(i=1;i<=T;i++){
        cin>>n>>s;
        d=s.size();
       printf("Case %d: ",i);
       calculation(n,d);

}
}
