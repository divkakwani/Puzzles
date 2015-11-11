
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

/****

Objective: To finish all the pies in the least amount of time.

Strategy: Break the maximum pies in one plate to two halves.
The time is 

Deciding whether to interrupt or not

Interruption: 
1. Causes the rate to go up by 1.
2. Penalty of -D for interrupting everybody.

Non-interruption
1. Doesn't change the rate.

****/
int pies[1000] = {0};
int k = 0;

int finish_time(vector<int> pies, int t) {
	if(pies.size() == 0)
		return t;

	vector<int> B;
	vvi Aset;

	for(int pie : pies) {
		if(pie > 1)
			B.push_back(pie-1);
	}
	
	int max = *(pies.end() - 1);
	if(max < 3)
		return finish_time(B, t+1);
	cout << "Pies ";el
	for(int x : pies)
			cout << x << "\t";el

	for(int split = 1; split <= max/2; split++) { 
		vi A;
		bool inserted1 = false;
		bool inserted2 = false;
		for(int i = 0; i < pies.size() - 1; i++) {
			if(!inserted1 and pies[i] > split) {
				A.push_back(split);
				inserted1 = true;
			}
			if(!inserted2 and pies[i] > max - split) {
				A.push_back(max-split);
				inserted2 = true;
			}
			A.push_back(pies[i]);
		}
		if(!inserted1)
			A.push_back(split);
		if(!inserted2)
			A.push_back(max-split);
		Aset.push_back(A);
		
		if(1) {
		for(int x : A)
			cout << x << "\t";el
		}
		
	}
	k++;
	
	int min = finish_time(B, t+1);
	for(vi& a : Aset) {
		int t = finish_time(a, t+1);
		if(t < min) {
			min = t;
		}
	}

	return min;
}

int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int d, p;
		cin >> d;
		vector<int> pies(d);
		inpN(pies, d);
		sort(pies.begin(), pies.end());
		cout << "Case #" << i << ": " << finish_time(pies, 0) << endl;	
	}

}


















