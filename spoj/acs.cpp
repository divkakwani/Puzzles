
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

int row[1235];
int col[5679];
int irow[1235];
int icol[5679];

int main() {

	//init
	rep(i, 0, 1235) {
		row[i] = i;
		irow[i] = i;
	}
	rep(i, 0, 5679) {
		col[i] = i;
		icol[i] = i;
	}

	char command;
	int x, y;
	while(cin >> command) {

		switch(command) {
			case 'R':
				cin >> x >> y;
				// update index
				swap(row[x], row[y]);
				// update inverted index
				swap(irow[row[x]], irow[row[y]]);
				break;
			case 'C':
				cin >> x >> y;
				swap(col[x], col[y]);
				swap(icol[col[x]], icol[col[y]]);
				break;
			case 'Q':
				cin >> x >> y;
				cout << 5678 * (row[x]-1) + col[y];el
				break;
			case 'W':
				cin >> x;
				int r = ((x-1) / 5678) + 1;
				int c = x - (r-1) * 5678;
				cout << irow[r] << " " << icol[c] << endl;
				break;
		}

				

	}

}
