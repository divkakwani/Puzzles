
#include <bits/stdc++.h>

using namespace std;

int main () {

   long long n, t, div;

   cin >> t;

   while(t--) {
       cin >> n;
       div = 0;
       for (long long i = 1; i <= n; i++)
           if (n % i == 0) div++;
       cout << div << endl;
   }
}
