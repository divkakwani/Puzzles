
#include <bits/stdc++.h>

using namespace std;

/* Two operations:
 *  0 A B -> increment all the numbers between A and B (inclusive) by 1.
 *  1 A B -> print the number of numbers between index A and index B that are divisible by 3.
 */

using ll = long long;

// short segment tree implementation
long long st[1000];
long long a[1000];

void build(ll p, ll l, ll r) {
    if (l == r)
        st[p] = 1;
    else {
        build(2 * p, l, (l+r)/2);
        build(2 * p + 1, (l+r)/2 + 1, r);
        st[p] = st[2 * p] + st[2 * p + 1];
    }
}

void increment(ll i, ll j, ll c) {
    
}

void range_update(ll p, ll l, ll r, ll i, ll j, ll c) {

    if (r < i or j < l or i > j) 
        return;
    if (i == j) {
        a[i] +=    
    }
}



int main() {
    long long N, Q;
    cin >> N >> Q;


    while(Q--) {
    
    }
}
