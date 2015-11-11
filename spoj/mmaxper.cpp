
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

long long env_len[1000][2];
int main() {

	int n, a, b;
	cin >> n;
	vector<int> H(n), W(n);
	rep(i, 0, n)
		cin >> H[i] >> W[i];
		
	env_len[0][0] = W[0];
	env_len[0][1] = H[0];

	for(int i = 1; i < n; i++) {


		// if the last rect was laid on the x-axis along its width
		long long a1 = abs(H[i] - H[i-1]) + W[i] + env_len[i-1][0];	// the next rect laid on the x-axis along its width
		long long a2 = abs(W[i] - H[i-1]) + H[i] + env_len[i-1][0]; // the next rect laid on the x-axis along its height
		
		// if the last rect was laid on the x-axis along its height
		long long b1 = abs(H[i] - W[i-1]) + W[i] + env_len[i-1][1];	// the next rect laid on the x-axis along its width
		long long b2 = abs(W[i] - W[i-1]) + H[i] + env_len[i-1][1]; // the next rect laid on the x-axis along its height
		
		env_len[i][0] = max(a1, b1);
		env_len[i][1] = max(a2, b2);
	}

	//for(int i = 0; i < n; i++)
	//	cout << "length: " << length[i] << "\t height " << height[i] << endl;
	cout << max(env_len[n-1][0], env_len[n-1][1]) << endl;
		

}
