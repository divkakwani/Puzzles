
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
    
        ll n;
        cin >> n;
        
        ll vote;
        vector<ll> first(n-2), second(n-2);
        rep(i, 0, n-2) { cin >> vote; first[i] = vote-1;} 
        rep(i, 0, n-2) { cin >> vote; second[i] = vote-1;}

        vector<ll> total(n);
        rep(i, 0, n-2) { total[first[i]]++; total[second[i]]++; }


        if(n == 3) {
            total[0]++; total[2]++;
            total[0]++; total[1]++;
            
            if((total[1] < total[0] and total[2] < total[0]) or
               (total[1] > total[0] and total[2] > total[0]) )
                cout << "one" << endl;
            else
                cout << "none" << endl;

            cout << "1 3"; el
            cout << "1 2"; el

            continue;
        }


        ll lowest = 0, highest = 0, any = 0;
        
        rep(i, 0, n-2) {
            
            if(total[i] > total[highest]) {
                any = highest;
                highest = i;
            }

            if(total[i] < total[lowest]) {
                any = lowest;
                lowest = i;
            }
        
            if(i != highest and i != lowest)
                any = i;
        }

        if(n == 4)
            any = lowest;

        ll first_dev, first_amit, second_dev = highest, second_amit = highest;

        if(total[highest] < total[n-1]) {
            total[any]++;
            first_dev = any;
        }
        else {
            total[n-1]++;
            first_dev = n-1;
        }

        if(total[highest] < total[n-2]) {
            total[any]++;
            first_amit = any;
        }
        else {
            total[n-2]++;
            first_amit = n-2;
        }

        // second votes
        total[highest]++;  // devu's
        total[highest]++;  // amit's

        auto remains = [&](ll x) { return total[lowest] < total[x] and total[x] < total[highest]; };

        bool amit_remains = remains(n-1);
        bool devu_remains = remains(n-2);

        if(amit_remains and devu_remains)
            cout << "both" << endl;
        else if(amit_remains or devu_remains)
            cout << "one" << endl;
        else
            cout << "none" << endl;

        cout << first_dev+1 << " " << second_dev+1; el
        cout << first_amit+1 << " " << second_amit+1; el

    }

}
