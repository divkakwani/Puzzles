
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

long long reverse_of(long long n) {
	long long ans = 0;
	while(n) {
		ans = ans * 10 + (n % 10);
		n /= 10;
	}
	return ans;
}
long long change(long long n, int pos, int to) {

	long long ans = all before first 9
	long long mod = n % pow(10, i-1);

}

int main() {

	long long reverse_at[] = {19, 109, 1099, 10099, 100999, 1000999, 
					  10009999, 100009999, 1000099999, 10000099999, 
					  100000999999, 1000000999999, 10000009999999};

	int t;
	cin >> t;

	for(int c = 1; c <= t; c++) {
		long long N;
		cin >> N;
		long long i = 0;
		long long steps = 0;
		int pos = 0;
		bool reached = false;
		while(i != N) {
			show(i);
			if(reverse_of(reverse_at[pos]) <= N) {
				i = reverse_of(reverse_at[pos++]);
				steps += 1;
				continue;
			}
			if( N <= reverse_at[pos]) {
				steps += N - i;
				i = N;
			} else {
				int i = pos + 2 - (pos/2 + 1)
		}

		cout << "Case #" << c << ": "<< steps << endl;
	}

}
