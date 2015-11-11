
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
typedef vector< vector<pair<long, long> > > vvll;    // for weighted graph


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
        
    long n, m, u, v, w;
    cin >> n >> m;

    vvll g(n+1);

    rep(i, 0, m) {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    
    unordered_map<long, long> dist;
    
    const long inf = 1000000000;	// A constexpr - evaled at compile-time.
	
	// The set E stores our best estimate for the shortest path to each vertex.
	// The one with the least estimate is transferred to the set S and all the edges leaving it are relaxed
	set<pair<long, long>> E;	// ordered by distance
	
	rep(i, 1, n+1)
		dist[i] = inf;

    long s;
    cin >> s;
    long x;
    rep(i, 0, s) {
        cin >> x;
        dist[x] = 0;
        E.insert(make_pair(0, x));
    }


	
	while(!E.empty()) {
		pair<long, long> least = *E.begin();
		E.erase(*E.begin());
		
		long path_len = least.first;
		long u = least.second;
		
		// TODO : segregate relax procedure
		
		// relax all the outbound edges
		for(auto it = g[u].begin(); it != g[u].end(); it++) {
		
			long v = it->first;
			long wt = it->second;;
			
			// Improve estimate
			if(dist[u] + wt < dist[v]) {
				typename set<pair<long, long>>::iterator it;
				if((it = E.find(make_pair(dist[v], v))) != E.end())
					E.erase(it);
				dist[v] = dist[u] + wt;
				E.insert(make_pair(dist[v], v));
			}
		}
	}	
    
    
    

    rep(i, 1, n+1)
        cout << dist[i] << endl;

}
