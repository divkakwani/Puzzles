
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
        
        string s;
        cin >> s;

        ll from0 = 0;
        ll from9 = 0;
        ll sum = 0;

        int digit = s[0] - '0';
        sum += digit;

        from0 += s.length() > 1 ? digit-1 : digit;

        for(ll i = 1; i < s.length(); i++) {
            digit = s[i] - '0';
            from0 += digit;
            from9 += (9-digit);
            sum += digit;
        }

        if(sum % 9 == 0)
            cout << 0 << endl;
        else {
        
            ll floor = (sum/9) * 9;
            ll ciel = floor + 9;

            int diffF = sum - floor;
            int diffC = ciel - sum;

            if(diffF < diffC and from0 >= diffF)
                cout << diffF << endl;
            else
                cout << diffC << endl;
        }
    
    
    }

}
