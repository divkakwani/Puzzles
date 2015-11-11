
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

    ll n;
    cin >> n;
    
    vector<int> counts(n);
    inpN(counts, n);

    ll sum = 0;
    bool valid = true;

    ll black = -1;
    ll white = -1;
    ll bcnt = 0;
    ll wcnt = 0;

    rep(i, 0, n) {

        if(black == -1) {
            black = counts[i];
            bcnt++;
            continue;
        }    
        if(black != counts[i] and white == -1) {
            white = counts[i];
            wcnt++;
            continue;
        }
        if(black == counts[i]) {
            bcnt++;
            continue;
        }

        if(white == counts[i]) {
            wcnt++;
            continue;
        }

        if(counts[i] != black and counts[i] != white)
            valid = false;
    }
    if(white > black) {
        swap(black, white);
        swap(bcnt, wcnt);
    }

    if(valid and white == -1) {
        
        if(black == n-1)
            cout << n << endl;
        else if(black == 0)
            cout << 0 << endl;
        else
            cout << -1 << endl;
        
    }

    else if(!valid or black != wcnt or black != (white+1))
        cout << -1 << endl;
    else
        cout << black << endl;

}
