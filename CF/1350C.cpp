#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>primediv;
int fs[200010][4];
map<int,int>cnt;
set<int>st;
long long Pow(int i, int u){
    long long y = 1, x = i;
    for (;u;u>>=1, x*=x) if (u&1) y*=x;
    return y;
}
void findprimedivisor(int n)
{

    for(int i=2; i*i<=n; i++)
    {

        if(n%i==0)
        {
            if(cnt[i]==0)
            {
                fs[i][1]=INT_MAX;
                fs[i][2]=INT_MAX;
            }
            int c=0;
            while(n%i==0)
            {
                c++;
                n/=i;
            }

            cnt[i]++;
            st.insert(i);


            if(c<fs[i][1])
            {
                fs[i][2]=fs[i][1];
                fs[i][1]=c;
            }
            else if(c<fs[i][2])
                fs[i][2]=c;

        }
    }
    if(n>1)
    {
        if(cnt[n]==0)
        {
            fs[n][1]=INT_MAX;
            fs[n][2]=INT_MAX;
        }
        cnt[n]++;
        st.insert(n);
        if(1<fs[n][1])
        {
            fs[n][2]=fs[n][1];
            fs[n][1]=1;
        }
        else if(1<fs[n][2])
            fs[n][2]=1;
    }

}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        findprimedivisor(x);
    }
    ll ans=1;
    for(auto it:st)
    {

        int x,y;
        x=fs[it][1];
        y=fs[it][2];

        if(cnt[it]==n-1)
        {
            ans*=Pow(it,x);

        }
        else if(cnt[it]==n)
        {
            ans*=Pow(it,y);
        }
    }
    cout<<ans<<endl;
}
