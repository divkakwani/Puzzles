
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
#define inpN(a, n)	rep(i, 0, n) cin >> a[i]; 
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

int A[100][100][1001];

// The recurrence relation is:   A[i, j][m] = true if A[i, k][p] and A[k+1, j][m-p]
int solve(int i, int j, int m) {

	if(i == j) {
		return

	if(A[i][j][m] != -1)
		return A[i][j][m];

	for(int k = 0; k < j; k++) {
		for(int p = -500; p <= 500; p++) {
			if(solve(i, k, p) - solve(k+1, j, m-p) == m) {
				A[i][j] = p;
				return p;
			}
		}
	}
}

int main() {
	
	int t;
	cin >> t;
	while(t--) {

		int n, m;
		cin >> n >> m;
		vi v(n);
		rep(i, 0, n)
			cin >> v[i];

		


}
