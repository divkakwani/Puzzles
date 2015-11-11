
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

// Recurrence
// max(V[i] + solution(Capacity - W[i], Include[i])

// memo[item][capacity]: stores importance which can be 5 * 60 at the most
long long memo[61][32001];
int Dep[61], W[61], V[61];

long long solution(int i, int capacity, set<int> include) {

	cout << "Call: " << i << ", " << capacity << "\tinclude: "; for(int elt:include) cout << elt << "\t";el
	
	//if(*include.begin() > i)
		//return -100000000LL;
	
	if(include.find(i) != include.end()) {
		cout << "caught here : Call: " << i << ", " << capacity << "\tinclude: "; for(int elt:include) cout << elt << "\t";el
		if(W[i] > capacity)
			return -10000LL;
		else
		 	return V[i] * W[i] + solution(i-1, capacity - W[i], include);
		 	
	}

	if(i <= 0 or capacity <= 0)
		return 0;
	if(memo[i][capacity] != -1)
		return memo[i][capacity];


	set<int> new_include = include;
	if(Dep[i] != 0)
		new_include.insert(Dep[i]);

	memo[i][capacity] = 0;

	ll a, b;
	if(W[i] <= capacity)
		a = solution(i-1, capacity-W[i], new_include);
	
	b = solution(i-1, capacity, include);
	
	memo[i][capacity] = max(V[i] * W[i] + a, b);		

	cout << "mem val: (" << i << ", " << capacity << "): " << memo[i][capacity];el
	return memo[i][capacity];

}


int main() {
	
	int t;
	cin >> t;
	while(t--) {
		memset(memo, 0xFF, 61 * 32001 * sizeof(int));
		int Wmax, n;
		cin >> Wmax >> n;
		rep(i, 1, n+1)
			cin >> W[i] >> V[i] >> Dep[i];

		cout << solution(n, Wmax, set<int>()) << endl;
		
	}

}
