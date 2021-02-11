#include<bits/stdc++.h>
using namespace std;
#define MAX 1000010
vector<int>ans[MAX];
const long long MAX_SIZE = 1000001;
#define ll long long
ll maxi=1;

vector<long long >isprime(MAX_SIZE, true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);

bool vs[MAX],vis[MAX];
void manipulated_seive(int N)
{

    isprime[0] = isprime[1] = false ;
    memset(vs,0,sizeof vs);
    memset(vis,0,sizeof vis);
    ans[1].clear();
    vs[1]=true;
    ans[1].push_back(1);

    for (long long int i=2; i<=N ; i++)
    {

        if (isprime[i])
        {
            prime.push_back(i);
            ans[1].push_back(i);
            SPF[i] = i;
        }

        ll c=2;
        for (long long int j=0;
                j < (int)prime.size() &&
                i*prime[j] <= N && prime[j] <= SPF[i];
                j++)
        {



            isprime[i*prime[j]]=false;

            if(vs[c]==false) ans[c].clear();
            if(vis[i*prime[j]]==false)
            {
                vis[i*prime[j]]=true;
                ans[c].push_back(i*prime[j]);
                maxi=max(maxi,c);
                vs[c]=true;
                c++;
            }
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        manipulated_seive(n);
        for(int i=1; i<=maxi; i++)
        {
            cout<<ans[i].size()<<" ";
            for(int j=0; j<ans[i].size(); j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        maxi=1;
    }




    return 0;
}

