
#include <bits/stdc++.h>

using namespace std;


int main() {


    long long x, y, z, a, b, c;
    cin >> a >> b >> c >> x >> y >> z;

    int excess = 0;
    int borrow = 0;
    
    if (a > x) {
        excess += (a-x)/2;
    } else {
        borrow += x-a;
    }

    if (b > y) {
        excess += (b-y)/2;
    } else {
        borrow += (y-b);
    }

    if (c > z) {
        excess += (c-z)/2;
    } else {
        borrow += (z-c);
    }

    if (excess >= borrow)
        cout << "Yes";
    else
        cout << "No";
    
}
