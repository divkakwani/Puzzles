
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

int main() {

	long long powers[30];
	long long cumulative[30];
	powers[0] = 1;
	cumulative[0] = 0;
	for(int i = 1; i < 30; i++) {
		powers[i] = 5 * powers[i-1];
		cumulative[i] = cumulative[i-1] + powers[i];
	}

	char subs[] = {'m', 'a', 'n', 'k', 'u'};

	int t;
	cin >> t;
	while(t--) {

		long long q;
		cin >> q;
		
		int idx = 0;
		while(cumulative[idx] < q)
			idx++;

		q = q - cumulative[idx - 1] - 1;
		
		char ans[30];
		int i = 0;

		while(idx > 0) {
			ans[i++] = subs[q / powers[idx - 1]];
			q = q % powers[idx-1];
			idx--;
		}
		ans[i] = '\0';
		cout << ans << endl;


	}


}
