
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

vector<int> primes;

bool sieve[31624];

void calc_sieve() {
    // runs in around ~10^4
    const ll sz = 31623;
    const ll sqrtsz = 178;
    
    for(ll i = 2; i <= sqrtsz; i++) {
        ll div = i+i;
        while(div <= sz) {
            sieve[div] = true;
            div += i;
        }
    }
    for(ll i = 2; i < sz+1; i++)
        if(!sieve[i])
            primes.push_back(i);
}

// returns the no of divisors of n;
ll tau(ll n) {

    vector<int> count;

    for(int i = 0; i < primes.size() and n > 1 and primes[i]*primes[i] <= n; i++) {
        int times = 0;
        while(n % primes[i] == 0) {
            times++;
            n /= primes[i];
        }
        if(times)   count.push_back(times); 
    }
    if(n > 1)   count.push_back(1);

    ll prod = 1;
    for(int cnt : count) {
        prod *= cnt+1;
    }
    return prod;
}

int main() {
    nosync;
    
    calc_sieve();
    
    ll a, b, n;

    cin >> a >> b >> n;

    ll ans = 0;
    for(ll i = a; i <= b; i++)
        if(tau(i) == n) ans++;

    cout << ans << endl;
        
}
