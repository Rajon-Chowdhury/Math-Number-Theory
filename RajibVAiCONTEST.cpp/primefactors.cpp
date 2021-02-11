#include<bits/stdc++.h>
using namespace std;
int pf[10000];

int main(){
         int n,j;
         while(scanf("%d",&n)==1){
           if(n==0)
           break;
          j=0;
         int p,num=abs(n);
           while (num%2 == 0)
    {
        pf[j]=2;
        num = num/2;
        j++;
    }
    for (int i = 3; i <= sqrt(num); i = i+2)
    {
        while (num%i == 0)
        {
            pf[j]=i;
            num = num/i;
            j++;
        }
    }
         if (num > 2){pf[j]=num,j++;
         }

         if(n<0){
          printf("%d = -1 x %d",n,pf[0]);
           for(int k=1;k<j;k++){
          printf(" x %d",pf[k]);
         }
         }
         else{
         printf("%d = %d",n,pf[0]);
         for(int k=1;k<j;k++){
          printf(" x %d",pf[k]);
         }
         }
         printf("\n");
         }
}
