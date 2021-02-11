#include<bits/stdc++.h>
using namespace std;
int len;
int calmod(char num[],int mod){

    int res = 0;

    for (int i=0;i<len;i++)
         res = (res*10 + (int)num[i] - '0')%mod;

    return res;


}
int main(){
     int f,h,a,b,c,d,e,p=0;
     char year[200000];
          while(scanf("%s",year)!=EOF){
            f=0,h=0;
              if ( p!= 0 )
            printf("\n");
              p = 1;
            len=strlen(year);
           a=calmod(year,4),b=calmod(year,100),c=calmod(year,400),d=calmod(year,15),e=calmod(year,55);
           //cout<<a<<b<<c<<d<<e<<endl;
         if((a==0&&b!=0)||c==0){
           printf("This is leap year.\n");
              f=1, h=1;
         }
          if(d==0){
            printf("This is huluculu festival year.\n");
              f=1;
          }
          if(e==0&&h==1)
            printf("This is bulukulu festival year.\n");
          if(f==0)
              printf("This is an ordinary year.\n");


}
return 0;
}

