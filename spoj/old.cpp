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
                        for(auto& elt : x) { cerr << x << "\t";} el

// Miscellaneous
#define nosync ios_base::sync_with_stdio(0);

/* Modular exponentiation
 */

ll mod_exp(ll A, ll B, ll M) {
    // return (A ^ B) mod M
    if(B == 0)  return 1 % M;

    if(B & 1)   return ((A % M) * (mod_exp(A, B-1, M) % M)) % M;

    ll half_mod = mod_exp(A, B/2, M);
    return ((half_mod % M) * (half_mod % M)) % M;
        
}

int main() {

    const ll M = 1000000007;
    ll a, b, c;
    while(cin >> a >> b >> c) {

        if(a == -1 and b == -1 and c == -1)
            break;

        cout << mod_exp(a, mod_exp(b, c, M-1), M) << endl;
    }
}

