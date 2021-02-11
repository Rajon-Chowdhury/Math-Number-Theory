#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli unsigned long long
#define endl '\n'
using namespace std;
const int mx = 3000005;
lli res[mx] , phi[mx];
void init()
{

	REP(i , mx)
	phi[i] = i;

	for(int i=2;i<mx;i++)
	if(phi[i] == i)
	{
		phi[i] /= i , phi[i] *= i-1;

		for(int j=2*i;j<mx;j+=i)
		phi[j] /= i , phi[j] *= i - 1;
	}

	REP(i , mx)
	{
		for(int j=i;j<mx;j+=i)
		res[j] += phi[i] * i;
	}
}
int main()
{
	lli t , n ;
	int cs=1;
	scanf("%llu",&t);
	init();
	while(t--)
	{
		scanf("%llu",&n);
		lli ans = (res[n] - 1)*n;
		ans /= 2;
		printf("%llu\n",ans+n);
	}
}
