#include<bits/stdc++.h>
using namespace std;


int main(){
        int B,P,M,res;

        while(scanf("%d %d %d",&B,&P,&M)!=EOF){
             res=1;
             B=B%M;
        while (P > 0)
        {

        if (P%2!=0)
          res = (res*B)%M;

         P = P/2;
         B = (B*B)%M;
       }
      cout<<res<<endl;
        }
}
