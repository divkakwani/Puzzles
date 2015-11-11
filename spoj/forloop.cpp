
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

typedef pair<ll, ll> range;

int main() {

        set<range> ranges;

        ll a;
        while(cin >> a) {
        
            auto it = ranges.lower_bound(range(a, 0));
            auto next = it;
            auto prev = it;
            if(next != ranges.begin()) --prev;
            range new_range = range(a, a);

            // check if previos can be merged
            if(next != ranges.begin() and prev->second == a-1) {
                new_range.first = (prev)->first;
                ranges.erase(prev);
            }

            // check if the following range can be merged
            if(next != ranges.end() and next->first == a+1) {
                new_range.second = next->second;
                ranges.erase(next);
            }
            ranges.insert(new_range);
        }
        for(auto it = ranges.begin(); it != ranges.end(); it++) 
            cout << "for (int i = " << it->first << "; i <= " << it->second << "; i++) cout << i << \" \";" << endl;
}
