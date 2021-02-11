#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long m = 2000000;
bool prime[m];
int p[10000],ps[10000];

void seive(){
        prime[1]=true;
        for(int i = 2; i * i < m; i++)
    {
        for(int j = 2; i * j < m; j++)
        prime[i*j] = true;
    }
       int k=1;
       ps[0]=2;
       for(int i=3;i<1000;i=i+2){
       if(prime[i]==false){
        ps[k]=i;
        k++;}
       }
}

void maximumpower(int m){
               int cnt=0,power=10000000;
               while (m%2 == 0){
               m = m/2;
               cnt++;}
               if(cnt!=0){
               power=min(power,p[2]/cnt);}
               for (int k = 3; k <= sqrt(m); k = k+2){
               cnt=0;
               while (m%k == 0){

               m = m/k;
               cnt++;}
              if(cnt!=0){
              power=min(power,p[k]/cnt);}
               }
              if (m > 2)
              power=min(power,p[m]);
if(power==0){
     printf("Impossible to divide\n");
}
else{
cout<<power<<endl;
}

}

void calculation(int z,int n){

      for(int i=3;i<=10000;i=i+2){
          if(prime[i]==false){
               p[i]=0;
          }
     }
     p[2]=1;
     int d=2,m,num;
     for(int i=3;i<=n;i++){
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
    p[2]=p[2]+m;
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
     maximumpower(z);

   }




int main(){
      int T,i,m,n;
      seive();
       scanf("%d",&T);
       for(i=1;i<=T;i++){
      scanf("%d %d",&m,&n);{
        printf("Case %d:\n",i);
        calculation(m,n);
      }
       }

}

