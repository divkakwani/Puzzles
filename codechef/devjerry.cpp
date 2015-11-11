
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
        int n, sx, sy, ex, ey, bx, by;
        cin >> n >> sx >> sy >> ex >> ey >> bx >> by;

        int ans = 0;

        if(sx > ex) {
            swap(sx, ex);
            swap(sy, ey);
        }
        if(sx == ex and bx == ex and sy < by and by < ey) {
            ans = abs(sy - ey) + 2;
            cout << ans << endl;
            continue;
        }

        if(sy > ey) {
            swap(sy, ey);
            swap(sx, ex);
        }

        if(sy == ey and by == ey and sx < bx and bx < ex) {
            ans = abs(sx-ex) + 2;
            cout << ans << endl;
            continue;
        }

        ans = abs(sy - ey) + abs(ex - sx);
        cout << ans << endl;
    }
}
