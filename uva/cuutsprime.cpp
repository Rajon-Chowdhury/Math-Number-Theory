#include<bits/stdc++.h>
using namespace std;

const int m = 2000000;
bool prime[m];
int p[1001];
void seive()
{
    prime[1]=false;
    for(int i = 2; i * i < m; i++)
    {
        for(int j = 2; i * j < m; j++)
            prime[i*j] = true;
    }
}

void print(int cnt,int C,int N){
     int a=(cnt/2)-(C-1),b,c,d;
     b=2*C,       c=((cnt/2)+1)-(C-1),    d=2*C-1;
     if(N==C){
            printf("%d %d:",N,C);
          for(int i=1;i<=cnt;i++){

          printf(" %d",p[i]);
          }
          printf("\n\n");
     }
     else if(C>cnt || 2*C>=cnt || 2*C-1>=cnt){
           printf("%d %d:",N,C);
           for(int i=1;i<=cnt;i++){
                printf(" %d",p[i]);
           }
           printf("\n\n");
     }
     else{
    if(cnt%2==0){
        printf("%d %d:",N,C);
     for(int k=a;k<a+b;k++){
        printf(" %d",p[k]);
     }
      printf("\n\n");
    }
    else{
      printf("%d %d:",N,C);
      for(int k=c;k<c+d;k++){
          printf(" %d",p[k]);
      }
      printf("\n\n");
    }
     }
}


int main(){
     int N,C,cnt,j,i;
     seive();
     while(scanf("%d %d",&N,&C)!=EOF){
            cnt=0,j=1;
       if(N==1){
           printf("%d %d:",N,C);
          printf(" %d\n\n",N);
       }
       else if(N==2){
           printf("%d %d:",N,C);
          printf(" %d %d\n\n",1,2);
       }
       else{
     for(i=1;i<=N;i++){
          if(prime[i]==false){
               p[j]=i;
               cnt++;
               j++;
          }
     }

           print(cnt,C,N);

     }
     }
}

