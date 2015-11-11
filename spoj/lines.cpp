
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

ostream& operator<<(ostream& out, const ii& p) {
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

int main() {

while(true) {
    int t;
    cin >> t;
    if(t == 0)  break;

    int x, y;
    set<ii> slopes;
    vector<ii> points;
    while(t--) {
        cin >> x >> y;
        points.push_back(mp(x, y));

    }
    for(int i = 0; i < points.size(); i++) {
    
        for(int j = i+1; j < points.size(); j++) {
             
            int dely = (points[i].second - points[j].second);
            int delx = (points[i].first - points[j].first);
           
            int gcd = __gcd(delx, dely);

            delx /= gcd;
            dely /= gcd;
            
            if(delx < 0) {
                delx = -delx;
                dely = -dely;
            }

            slopes.insert(ii(delx, dely));
        }
    }
    cout << slopes.size() << endl;
}
}
