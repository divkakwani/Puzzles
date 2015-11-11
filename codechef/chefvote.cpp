
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

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        inpN(arr, n);
        
        ll sum = 0;
        bool cond = true;
        for(int elt : arr) {
            sum += elt;
            if(elt >= n) { cond = false; break;}
        }

        if(!cond or sum != n) {
            cout << -1 << endl;
        }
        else {
            // create a graph
            vector<int> graph(n);
            for(int i = 0; i < n; i++) {
                ll max = 0;
                int max_idx = 0;
                for(int j = 0; j < n-1; j++) {
                    if(arr[(j+i+1) % n] > max) {
                        max_idx = (j+i+1) % n;
                        max = arr[max_idx];
                    }
                }
                graph[i] = max_idx;
                arr[max_idx]--;
            }
        
            // print the graph
            for(int elt : graph)
                cout << elt+1 << " ";
            cout << endl;
        }
    
    }
}
