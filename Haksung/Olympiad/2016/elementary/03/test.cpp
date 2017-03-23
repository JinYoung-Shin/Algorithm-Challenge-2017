#include <iostream>
using namespace std;

int gcd(int x, int y)
{
    while( x % y > 0 )
    {
        int r = x % y;
        x = y;
        y = r;
    }
    return y;
}

int main() {
   int t;
   cin >> t;
   while( t-- )
   {
       int n,m;
       cin >> n >> m;
       int g = gcd(n,m);
       cout << (n/g)*(m/g) << endl;
   }
   return 0;
}
