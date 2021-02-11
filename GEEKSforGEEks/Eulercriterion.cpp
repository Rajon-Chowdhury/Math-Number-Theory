#include<iostream>
using namespace std;

int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;

    while (y >0) {
        if (y & 1)
            res = (res*x) % p;

        y = y>>1;
        cout<<y<<" ";
        x = (x*x) % p;
               cout<<x<<" ";
                       cout<<res<<" ";
    }
    return res;
}

bool squareRootExists(int n, int p)
{
    if (power(n, (p-1)/2, p) == 1)
       return true;

    return false;
}

int main()
{
   int p = 7;
   int n = 2;
   squareRootExists(n, p)? cout << "Yes": cout << "No";
   return 0;
}
