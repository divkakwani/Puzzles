
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
	nosync;
	int t;
	cin >> t;
	while(t--) {
		long long n;
		cin >> n;
		map<long long, string> candidates;
		map<string, string> transform;
		long long pesel; string mro;
		while(n--) {
			cin >> pesel >> mro;
			candidates[pesel] = mro;
			transform[mro] = mro;
		}
		long long changes;
		cin >> changes;
		string old, neww;
		while(changes--) {
			cin >> old >> neww;
			transform[old] = neww;
		}

		// compress transform

		for(auto it = transform.begin(); it != transform.end(); it++) {
			string to = it->second;
			stack<map<string, string>::iterator> middle;
			middle.push(it);
			while(1) {
				auto it1 = transform.find(to);
				if(to == it1->second)
					break;
				middle.push(it1);
				to = it1->second;

			}
			while(!middle.empty()) {
				auto it2 = middle.top();
				it2->second = to;
				middle.pop();
			}
		}

		long long recruits;
		cin >> recruits;
		long long id;
		while(recruits--) {
			cin >> id;
			cout << id << " " << transform[candidates[id]] << endl;
		}
	}
}

