
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
#define inpN(a, n)	rep(xHwZ, 0, n) cin >> a[xHwZ]; 
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

int arr[100][100];

//
//				NOTE
//			WRONG LOGIC	!!!!!!!!
//
//

pair<int, int> solve(int i, int j, int n) {

	if(i < 0 or i > n-1 or j < 0 or j > n-1)
		return mp(-1000, 1000);

	if(i == n-1 and j == n-1)
		return mp(arr[i][j], arr[i][j]);
	
	pair<int, int> moves[4];

	moves[0] = solve(i-1, j, n); // top
	moves[1] = solve(i, j-1, n); // left
	moves[2] = solve(i, j+1, n); // right
	moves[3] = solve(i+1, j, n); // bottom

	return moves[1];//*min_element(moves, moves+4, [](ii a, ii b) { return (a.second - a.first) < (b.second - b.first); });

}

int main() {
	
	int n;
	cin >> n;
	rep(i, 0, n)
		inpN(arr[i], n);

	pair<int, int> sol = solve(0, 0, n);
	cout << sol.second - sol.first << endl;

}
