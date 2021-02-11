#include<bits/stdc++.h>
using namespace std;
#include<iostream>
#include<stdio.h>
#define ll long long
using namespace std;

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

int main(){

string input;

vector<vector<int>> v; //Vector containing all integers of all lines scanned

int j=1;

while(getline(cin,input)) {

 stringstream x(input);

 vector<int> vt;    //Parsing integers scanned in current line

 int n;

 cout<<"\nLine "<<j<<" scanned: ";

 while(x>>n)
 {
cout<<n<<" ";

vt.push_back(n);

 }

 cout<<endl;

   v.push_back(vt);
j++; } }

}

