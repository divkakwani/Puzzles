
#include <bits/stdc++.h>
#define DEBUG
using namespace std;


/** Boilerplate */
// Macros and typedefs

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

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
// Debugging macros
#ifdef DEBUG
#define show(x)		cerr << #x << ": " << x << endl;
#else
#define show(x) 
#endif

// Miscellaneous
#define nosync ios_base::sync_with_stdio(0);

int main() {
	int f, r;
	while(cin >> f && f && cin >> r) {
		vector<float> fs(f), rs(r);
		inpN(fs, f); inpN(rs, r);
		sort(fs.rbegin(), fs.rend());
		sort(rs.begin(), rs.end());
		
		float max = 0;
		int p1 = 0, p2 = 0;
		rep(i, 0, r) {
			rep(j, 0, f) {
				el el
				show(i);show(j);
				float d1 = rs[i] / fs[j];
				int adj_i = i, adj_j = j;
				if((i < r - 1) and ((rs[i + 1] / fs[j]) < (rs[i] / fs[j + 1])))
					adj_i++;	
				else if((j < f-1) and ((rs[i + 1] / fs[j]) >= (rs[i] / fs[j + 1])))
					adj_j++;
				show(rs[adj_i]/fs[adj_j] / d1);
				show(adj_i);show(adj_j);
				max = max(max, (rs[adj_i] / fs[adj_j]) / d1);
			}
		}
		printf("%.2f", roundf(max * 100) / 100.0); el
	}
}

