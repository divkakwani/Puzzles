
#include <bits/stdc++.h>

using namespace std;


/** Boilerplate */
// Macros and typedefs

typedef long long ll;
typedef pair<int, int> ii;
typedef vector< ii > vii;
typedef vector<int> vi;
typedef vector< vector< ii > > vvii;

#define INF 1e9


// Shorthands for frequently occuring code
#define rep(i, a, b) 	for(int i = (a); i < (b); i++)
#define inpN(a, n)	rep(i, 0, n) cin >> a[i]; 
#define fill(a, v) 	(memset(a, v, sizeof a))
#define in(a, b) 	((b).find(a) != (b).end())
#define max(a, b)	((a) > (b) ? (a) : (b))
#define min(a, b)	((a) < (b) ? (a) : (b))
#define isInt(a)	int(a) == (a) ? true : false
#define el		cout << endl;
#define mp 		make_pair

// Debugging macros
#define show(x)		cout << #x << ": " << x << endl;

// Miscellaneous
#define nosync ios_base::sync_with_stdio(0);

int main() {
	nosync;
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vvii g(n+1);
		map<string, int> id;
		rep(i, 1, n + 1) {
			string name;
			cin >> name;
			id[name] = i;
			int adj;
			cin >> adj;
			rep(j, 0, adj) {
				int v, cost;
				cin >> v >> cost;
				g[i].push_back(make_pair(v, cost));
			}
		}

		int queries;
		cin >> queries;
		rep(r, 0, queries) {
			string src, dest;
			cin >> src >> dest;

			// Apply dijkstra's algorithm

			priority_queue< ii, vector< ii > , greater<ii> > pq;	// stores distance, id
		
			int src_id = id[src], dest_id = id[dest];

			vector<int> dist(n+1, INT_MAX);
			
			dist[src_id] = 0;

			pq.push(mp(0, src_id));

			while(!pq.empty()) {
				ii elt = pq.top();
				pq.pop();

				int vertex = elt.second;

				if(vertex == dest_id)
					break;
				
				vector<ii>::iterator end = g[vertex].end();

				for(vector< ii >::iterator it = g[vertex].begin(); it != end; it++) {
					int v2 = it->first, wt = it->second;
					if(dist[v2] > dist[vertex] + wt) {
						dist[v2] = dist[vertex] + wt;
						pq.push(mp(dist[v2], v2));
					}
				}

			}
			cout << dist[dest_id]; el
		}
	}

}
