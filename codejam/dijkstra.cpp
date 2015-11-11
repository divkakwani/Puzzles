
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


#define DEBUG
// Debugging macros
#ifdef DEBUG
#define show(x)		cerr << #x << ": " << x << endl;
#else
#define show(x)
#endif
// Miscellaneous
#define nosync ios_base::sync_with_stdio(0);


/*
	Proc
		Find shortest string that multiplies to i starting from 0. Need to check for only first 4 cycles.



*/


unordered_map<char, int> trans {{'i', 1}, {'j', 2}, {'k', 3}};

unordered_map<int, unordered_map<int, int>> lookup { {0, {{0, 0}, {1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6}, {7,7}}},
													 {1, {{0, 1}, {1,4}, {2,3}, {3,6}, {4,5}, {5,0}, {6,7}, {7,2}}},
													 {2, {{0, 2}, {1,7}, {2,4}, {3,1}, {4,6}, {5,3}, {6,0}, {7,5}}},
													 {3, {{0, 3}, {1,2}, {2,5}, {3,4}, {4,7}, {5,6}, {6,1}, {7,0}}},
													 {4, {{0, 4}, {1,5}, {2,6}, {3,7}, {4,0}, {5,1}, {6,2}, {7,3}}},
													 {5, {{0, 5}, {1,0}, {2,7}, {3,2}, {4,1}, {5,4}, {6,3}, {7,6}}},
													 {6, {{0, 6}, {1,3}, {2,0}, {3,5}, {4,2}, {5,7}, {6,4}, {7,1}}},
													 {7, {{0, 7}, {1,6}, {2,1}, {3,0}, {4,3}, {5,2}, {6,5}, {7,4}}}};


int solve(string s) {
	bool i = false, j = false, k = false;
	int prod = trans[s[0]];
	for(int p = 1; p < s.length(); p++) {
		if(prod == 1 and !i) {
			i = true;
			prod = 0;
		}
		else if(prod == 2 and i and !j) {
			j = true;
			prod = 0;
		}
		prod = lookup[prod][trans[s[p]]];
	}
	if(i and j and prod == 3)
		return true;
	return false;
		

}


int main() {
	int t;
	cin >> t;
	rep(i, 1, t+1) {
		long long l, x;
		cin >> l >> x;
		string s;
		cin >> s;
		string repstr;
		for(long long j = 0; j < x; j++)
			repstr += s;
		bool status = solve(repstr);
		if(status)
			cout << "Case #" << i << ": " << "YES" << endl;
		else
			cout << "Case #" << i << ": " << "NO" << endl;
			
	
	}
}
