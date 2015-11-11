
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
#define showCont(x) for(auto elt : x) cerr << elt << "\t"; el

// Miscellaneous
#define nosync ios_base::sync_with_stdio(0);

ll Work(vector<ll>& A, ll n) {

    ll tot = 0;

    // Solve: x^2 + x - (2n)/elt = 0;

    for(ll elt : A) { 
        ll x = (sqrt(1 + (8.0 * n) / elt) - 1) / 2.0;
        tot += x;
    }
    return tot;
}

ll find_n(vector<ll>& A, vector<ll>& B, ll lo, ll hi, ll p) {

    ll mid = (hi + lo + 1) / 2;
    
    if(hi == lo)
        return hi;

    if(Work(A, mid) < Work(B, p-mid))
        return find_n(A, B, mid, hi, p);

    else if(Work(A, mid) > Work(B, p-mid))
        return find_n(A, B, lo, mid-1, p);

    else return mid;

}


int main() {

    int t;
    cin >> t;
    
    while(t--) {
    
        ll p;
        cin >> p;

        int n, m;
        cin >> n >> m;

        vector<ll> A(n), B(m);

        inpN(A, n);
        inpN(B, m);

        cout << Work(A, find_n(A, B, 0, p, p)); el

    }

}
