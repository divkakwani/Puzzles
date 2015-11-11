
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

void flyods(vector<vector<long double>>& graph) {
    
    int n = graph.size();
    
    for(int p = 0; p < n; p++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                    graph[j][k] = max(graph[j][k], graph[j][p] * graph[p][k]);
}

int main() {
    nosync;

    int n;

    int cs = 1;
    
    while(true) {
            
        cin >> n; 
        if(n == 0) break;

        vector<string> currencies(n);
        inpN(currencies, n);
    
        map<string, int> index;

        rep(i, 0, n) index[currencies[i]] = i;
        

        int m;
        cin >> m;

        string a, b;
        long double conv;

        // setup graph structure
        vector<vector<long double>> graph(n);
        rep(i, 0, n) graph[i].assign(n, 0);

        rep(i, 0, m) {
            cin >> a >> conv >> b;
            graph[index[a]][index[b]] = conv;
        }

        flyods(graph);
    
        bool possible = false;

        rep(i, 0, n) if(graph[i][i] > 1.0) { possible = true; break; }

        cout << "Case " << cs++ << ": ";
        if(possible)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}



