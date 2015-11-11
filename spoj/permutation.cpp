
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

int memo[15][26];

int count(int n, int letter) {
	
	if(letter > 25)
		return 0;
	if(n == 1)
		return letter + 1;

	if(memo[n][letter] != -1)
		return memo[n][letter];

	memo[n][letter] = 0;
	for(char x = 0; x < letter; x++) {
		memo[n][letter] += count(n-1, letter);
	}
	memo[n][letter] += count(n-1, letter+1);
	return memo[n][letter];
}

int main() {
	memset(memo, 0xFF, 15 * 26 * sizeof(int));
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << count(n, 0);el
	}

}
