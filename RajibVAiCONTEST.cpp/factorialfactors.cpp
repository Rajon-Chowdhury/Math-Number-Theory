#include<bits/stdc++.h>
using namespace std;
int p[1000001];

const long m = 2000000;
bool prime[m];

  void seive()
    {
    prime[1]=true;
    for(int i = 2; i * i < m; i++)
    {
        for(int j = 2; i * j < m; j++)
            prime[i*j] = true;
    }
    }
int div(int num){
     int j=0;
    while (num%2 == 0)
    {
        num = num/2;
        j++;
    }
    for (int i = 3; i <= sqrt(num); i = i+2)
    {
        while (num%i == 0)
        {
            num = num/i;
            j++;
        }
    }
         if (num > 2)
               j++;
    return j;
}

void precalculate(){
     int d;
     p[2]=1;
    for(int i=3;i<=1000000;i++){
     if(prime[i]==false)
          p[i]=p[i-1]+1;
     else
     p[i]=p[i-1]+div(i);

    }
}
int main()
{
     seive();
     precalculate();
     int n;
     while(scanf("%d",&n)!=EOF){
          printf("%d\n",p[n]);

     }

}
