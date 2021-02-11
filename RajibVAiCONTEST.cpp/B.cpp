#include<bits/stdc++.h>
using namespace std;
const long m = 2000000;
bool prime[m];
int p[10000],ps[10000];
void seive()
{
    prime[1]=true;
    for(int i = 2; i * i < m; i++)
    {
        for(int j = 2; i * j < m; j++)
            prime[i*j] = true;
    }
    int k=1;
    ps[0]=2;
    for(int i=3;i<10000;i=i+2){
     if(prime[i]==false){
          ps[k]=i;
          k++;}
    }
}
void calculation(int n){

 for(int i=3;i<=10000;i=i+2){
          if(prime[i]==false){
               p[i]=0;
          }
     }
     p[2]=0;
     int d=2,m,num;
     for(int i=n;i>2;i=i-2){
     if(prime[i]==false){
          p[i]=p[i]+1;
          d=max(d,i);
     }
     else{
          m=0,num=i;
    while (num%2 == 0)
    {
        num = num/2;
          m++;
    }
    p[2]=p[2]+m+1;
    for (int k = 3; k <= sqrt(num); k = k+2)
    {    m=0;
        while (num%k == 0)
        {
            num = num/k;
            m++;
        }
        p[k]=p[k]+m;
    }
         if (num > 2)
              p[num]=p[num]+1;
     }
     }
     int v=0;
    cout<<setw(3)<<n<<"! =";
     for(v=0;v<=10000;v++){
                if(ps[v]>d){
          break;
       }
       if(v%15==0 && v!=0){
          printf("\n      ");
       }
         cout<<setw(3)<<p[ps[v]];
     }
     printf("\n");
   }




int main(){
      int n;
      seive();

      while(scanf("%d",&n)==1){
        if(n==0){
        break;}
        calculation(n);
      }
}
