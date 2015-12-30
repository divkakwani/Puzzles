
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ll n, k;
    cin >> n >> k;

    vector<ll> a;
    ll want;
    a.push_back(0);

    for (ll i = 0; i < n; i++) {
        cin >> want;
        a.push_back(want);
    } 

    vector<ll> orig(a);
    sort (a.begin(), a.end());

    ll aggr = 0;
    ll left = n; 
    ll b = 0;

    while (left and aggr + left * (a[n-left+1] - a[n-left]) <= k) {
        aggr +=  left * (a[n-left+1] - a[n-left]);
        b = a[n-left];
        left--;
    }

    if(left == 0) {
        cout << -1 << endl;
        return 0;
    }


    b += (k - aggr)/left;

    for (auto& i : orig)
        i -= b;

    ll remnant = (k-aggr) % left;

    ll start = 0;
    for (; start < orig.size(); start++) {
        if (remnant <= 0)
            break;
        if (remnant > 0 and orig[start] > 0) {
            orig[start]--;
            remnant--;

        }
    }

    /* cout << "original array\n"; */
    /* for (int i = 0; i <= n; i++) */
    /*     cout << "i: " << orig[i] << endl; */


    bool flag = false;
    for (ll i = 0; i <= n; i++) {
        if (orig[(i+start)%(n+1)] > 0) {
            flag = true;
            cout << (i+start)%(n+1) << " ";
        }
    }
    if (!flag)  cout << -1;

    cout << endl;


    
}



