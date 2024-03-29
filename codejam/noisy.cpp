
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

bool grid[10000][10000];

int solve(int n, int R, int C) {
	
	int safe = (R * C + 1) / 2;
	int two = (C-1)%2 + (R-1)%2 + (R+C)%2;
	int three = R + C - 2 - two;
	
	if(n<= safe)
		return 0;
	if(n <= safe+two)
		return 2 * (n-safe);
	if(n <= safe+two+three)
		return 2*two + 3*(n-safe-two);

	return 2*two + 3*three + 4 *(n-safe-two-three);

}
int main() {

	int t;
	cin >> t;
	rep(i, 1, t+1) {
		int r, c, n;
		cin >> r >> c >> n;
		cout << "Case #" << i << ": " << solve(n, r, c) << endl;
	}
}
