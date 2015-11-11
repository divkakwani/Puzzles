
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


/* Binary Indexed Tree Impl */

struct BIT {

    BIT(ll sz) : bit(sz+1) { N = sz; } 

    inline ll LSOne(ll n) { return n & (-n); }
    vector<ll> bit;
    ll N;
    
    ll rsq(ll u) {
        ll sum = 0;
        for(; u; u = u - LSOne(u)) sum += bit[u];
        return sum;
    }
    ll rsq(ll u, ll v) {
        return rsq(v) - rsq(u-1);
    }
    void adjust(ll u, ll val) {
        for(; u <= N; u += LSOne(u))
            bit[u] += val;
    }
};


int main() {
    nosync;

    ll t;
    cin >> t;

    while(t--) {
    
        ll n, c;

        cin >> n;
        BIT b1(n), b2(n);

        cin >> c;

        ll cmd, p, q, v;
        
        while(c--) {
            
            cin >> cmd >> p >> q;
            if(cmd == 0) {
                cin >> v;
                b1.adjust(p, v);
                b1.adjust(q+1, -v);
                b2.adjust(p, v*(p-1));
                b2.adjust(q+1, -v*q);
            } else {
                cout << b1.rsq(q)*q - b2.rsq(q) - b1.rsq(p-1)*(p-1) + b2.rsq(p-1); el
            }
        }
    
    }

}
