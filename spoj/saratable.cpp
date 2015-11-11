
#include <bits/stdc++.h>

using namespace std;

/* Author: Divyanshu Kakwani */

/** Boilerplate */

// type aliases
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;      // for unweighted graph
typedef vector< vector< ii > > vvii;    // for weighted graph


// Constants
#define INF(T) numeric_limits<T>::max()

// Shorthands for frequently occuring code
#define rep(i, a, b)    for(int i = (a); i < (b); i++)
#define inpN(a, n)      rep(hZxWQ, 0, n) cin >> a[hZxWQ]; 
#define fill(a, v)      (memset(a, v, sizeof a))
#define in(a, b)        ((b).find(a) != (b).end())
#define max(a, b)       ((a) > (b) ? (a) : (b))
#define min(a, b)       ((a) < (b) ? (a) : (b))
#define isInt(a)        int(a) == (a) ? true : false
#define el              cout << endl;
#define mp              make_pair

#define DEBUG

// Debugging macros
#ifdef DEBUG
#define show(x)         cerr << #x << ": " << x << endl;
#define showCont(C)     cerr << "Contents of " #C; el \
                        for(auto& elt : C) { cerr << elt << "\t";} el
#define stop            exit(-123);
#else
#define show(x) 
#define showCont(C)
#define stop
#endif

// Miscellaneous
#define nosync ios_base::sync_with_stdio(0);


int main() {
    nosync;


    ll t;
    cin >> t;

    while(t--) {

        ll a, b, n;
        cin >> a >> b >> n;

        ll gcd = __gcd(a, b);
/*        double lo = ((n-1.0)*a*b)/(a+b-gcd);

        ll ilo = std::ceil(lo);
        ll ihi = ilo + 3; 

        for(ll i = ilo; i <= ihi; i++)
            if(i/a + i/b - (i*gcd)/(a*b) == n) {
                cout << i << endl;
                break;
            }

*/
        ll lo = min(a, b);
        ll hi = max(a, b) * 1000000000;

        ll ans = 0;

        while(lo <= hi) {
            ll mid = (hi + lo) / 2;
            ll val = mid/a + mid/b - (mid*gcd)/(a*b); 
            if(val == n) {
                ans = mid;
                break;
            }
            else if(val > n)
                hi = mid-1;
            else
                lo = mid+1;
        }

        while(ans % a != 0 and ans % b != 0) ans--;
        cout << ans << endl;

    }

}
