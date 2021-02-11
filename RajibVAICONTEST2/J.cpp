#include<bits/stdc++.h>
using namespace std;
int main()
{
   string a;
   int n,cnt=0;
   cin>>n;
   cin>>a;
   for(int i=1;i<n;i++){
     if(a[i]=='0'){
          cnt++;
     }
   }
   for(int i=0;i<=cnt;i++){
     if(i==0){
          cout<<a[0];
     }
     else{
          cout<<0;
     }
   }
}
