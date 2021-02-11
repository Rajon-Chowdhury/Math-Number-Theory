#include<bits/stdc++.h>
#define ll long long
#define MAX 2000010
int p[MAX],dphi[MAX];
using namespace std;

void phi(){
int i,j;
	for(i=1;i<MAX;i++)
		p[i]=i;
	for(i=2;i<MAX;i++)
	{
		if( p[i]==i )
		{
			for(j=i;j<MAX;j+=i)
			{
				p[j] =  (p[j]/i*(i-1));
			}
		}
	}
}

void depth(){
     int cnt,c;
     for(int i=2;i<=2000000;i++){
      cnt=1,c=i;
   while(p[c]!=1){
     cnt++;
     c=p[c];
   }
   dphi[i]=cnt;

}
}

int main()
{
	ll sum;
	int m,n,T,k;
	scanf("%d",&T);
	phi();
	depth();
	for(k=1;k<=T;k++)
	{
	     sum=0;
	     scanf("%d %d",&m,&n);
	  for(int c=m;c<=n;c++){
		sum=sum+dphi[c];
	  }
	  printf("%lld\n",sum);
	}
	return 0;
}

