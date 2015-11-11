
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

// stores primes till 10000 (inclusive).
vector<int> primes;

bool sieve[10001];

void calc_sieve() {
    // runs in around ~10^4
    const int sz = 10000;
    const int sqrtsz = 100;
    
    for(int i = 2; i <= sqrtsz; i++) {
        int div = i+i;
        while(div <= sz) {
            sieve[div] = true;
            div += i;
        }
    }
    for(int i = 2; i < sz; i++)
        if(!sieve[i])
            primes.push_back(i);
}

const int sz = 1300;  // little more than the no of primes under 10,000;
// stores exps of the prime factors 
long long exponents[sz];
long long no_of_primes = 0;

void accum(ll n) {

    vector<int> count;

    for(int i = 0; i < primes.size() and n > 1 and primes[i]*primes[i] <= n; i++) {
        int times = 0;
        while(n % primes[i] == 0) {
            times++;
            n /= primes[i];
        }
        exponents[i] += times;  // exponent of ith prime
    }
    if(n > 1)
        no_of_primes++;
}


int main() {
    nosync;
    
    calc_sieve();

    int t;
    cin >> t;

    while(t--) {
        ll n, m, ans = 1;
        cin >> n >> m;

        fill(exponents, exponents+sz, 0);
        no_of_primes = 0;

        for(ll i = 2; i <= n; i++)
            accum(i);
        
        for(int i = 0; i < 10; i++)
        {show(exponents[i]);}

        for(int i = 0; i < sz; i++)
            ans = (ans * (exponents[i] + 1)) % m;
        
        while(no_of_primes--)
            ans = (ans * 2) % m;

        ans -= 1;   // exclude 1 as a divisor

        cout << ans % m << endl;
    }

}
