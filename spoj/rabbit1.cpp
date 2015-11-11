
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

typedef pair<pair<ll, ll>, pair<ll, ll>> Matrix;

Matrix multiply(Matrix A, Matrix B, ll mod) {

    Matrix res;
    res.first.first = (A.first.first * B.first.first + A.first.second * B.second.first) % mod;
    res.first.second = (A.first.first * B.second.first + A.first.second * B.second.second) % mod;
    res.second.first = (A.second.first * B.first.first + A.second.second * B.first.second) % mod;
    res.second.second = (A.second.first * B.second.first + A.second.second * B.second.second) % mod;

    return res;
}

Matrix base = {{1, 1}, {1, 0}};

Matrix exp_by_sq(ll n, ll mod){
    if(n == 1)
        return base;

    if(n % 2)
        return multiply(base, exp_by_sq(n-1, mod), mod);

    Matrix half_res = exp_by_sq(n/2, mod);
    return multiply(half_res, half_res, mod);
}

ll fib(ll n, ll mod) {
    if(n == 0)
        return 0;
    Matrix res = exp_by_sq(n, mod);
    return res.first.second;
}

int main() {

    int c;
    cin >> c;

    while(c--) {
        long long n, m;
        cin >> n >> m;
        long long a = 0, b = 1;
        long long mod = 1 << m;

        cout << (fib(n, mod) + fib(n-1, mod)) % mod << endl;
    }
}
