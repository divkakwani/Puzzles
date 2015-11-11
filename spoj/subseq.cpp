
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

    ll t;
    cin >> t;

    cin.get();

    rep(i, 1 , t+1) {
        
        string s;
        getline(cin, s);
        
        ll q;
        cin >> q;

        cin.get();

        // Preprocessing
        set<int> lists[26];

        rep(j, 0, s.length())
  
            lists[s[j]-'a'].insert(lists[s[j]-'a'].end(), j);



        cout << "Case " << i << ":\n";

        while(q--) {
        
            string p;
            getline(cin, p);

            bool valid = true;
            int idx = 0;
            for(int j = 0; j < p.length(); j++) {
                auto it = lists[p[j]-'a'].lower_bound(idx);
                if(it == lists[p[j]-'a'].end()) {
                    valid = false;
                    break;
                } else {
                    idx = (*it) + 1;
                }
            }
            if(valid)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    
    }
}
