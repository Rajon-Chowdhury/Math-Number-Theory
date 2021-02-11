#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>primediv;
int a[150000],b[150000];
void findprimedivisor(int n)
{

    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }
        }
        primediv.push_back(i);
    }
    if(n>1) primediv.push_back(n);

}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i]>>b[i];
    findprimedivisor(a[1]);
    findprimedivisor(b[1]);
    int ans=-1;
    for(auto d:primediv)
    {
        bool f=true;
        for(int i=2; i<=n; i++)
        {
            if((a[i]%d!=0)&&(b[i]%d!=0))
            {
                f=false;
                break;
            }
        }
        if(f==true)
        {
            cout<<d<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;

}
