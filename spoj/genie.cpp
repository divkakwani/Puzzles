
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

// Debugging macros
#define show(x)         cerr << #x << ": " << x << endl;
#define showCont(C)     cerr << "Contents of " #C; \
                        for(auto& elt : C) { cerr << elt << "\t";} el

// Miscellaneous
#define nosync ios_base::sync_with_stdio(0);


int main() {

    int t;
    cin >> t;

    while(t--) {
        int n, x; 
        cin >> n;
        
        vi counters(1001);
       
        rep(i, 0, n) {
            cin >> x;
            counters[x]++;
        }
        bool valid = true;

        for(int i = 0; i < (n+1)/2; i++) {
            if(counters[i] + counters[n-i-1] != 2) {
                valid = false;
                break;
            }
        }

        if(valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }

}
