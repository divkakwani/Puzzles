
#include <bits/stdc++.h>

using namespace std;

/* Author: Divyanshu Kakwani */

/** Boilerplate */

// type aliases
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;	// for unweighted graph
typedef vector< vector< ii > > vvii;	// for weighted graph

// Constants
#define INF 1e9


// Shorthands for frequently occuring code
#define rep(i, a, b) 	for(int i = (a); i < (b); i++)
#define inpN(a, n)	rep(hZxWQ, 0, n) cin >> a[hZxWQ]; 
#define fill(a, v) 	(memset(a, v, sizeof a))
#define in(a, b) 	((b).find(a) != (b).end())
#define max(a, b)	((a) > (b) ? (a) : (b))
#define min(a, b)	((a) < (b) ? (a) : (b))
#define isInt(a)	int(a) == (a) ? true : false
#define el		cout << endl;
#define mp		make_pair

// Debugging macros
#define show(x)		cerr << #x << ": " << x << endl;

// Miscellaneous
#define nosync ios_base::sync_with_stdio(0);


int main() {

    int t;
    cin >> t;
    
    while(t--) {
    
        ll h, w, n;

        cin >> w >> h >> n;

        vector<ll> xs(n+2), ys(n+2);

        xs[0] = 0;
        ys[0] = 0;

        rep(i, 1, n+1)
            cin >> xs[i] >> ys[i];

        xs[n+1] = w+1;
        ys[n+1] = h+1;

        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());

        int maxdiff_x = 0;
        int maxdiff_y = 0;

        for(int j = 1; j < n+2; j++) {
            
            maxdiff_x = max(maxdiff_x, xs[j] - xs[j-1] - 1);
            maxdiff_y = max(maxdiff_y, ys[j] - ys[j-1] - 1);
        }
        cout << maxdiff_x * maxdiff_y << endl;
    }
}
