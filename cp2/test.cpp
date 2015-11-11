
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


/** Boilerplate */
// Macros and typedefs

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1e9

#define gcd __gcd

// Shorthands for frequently occuring code
#define rep(a) for(int i = 0; i < (a); i++)
#define fill(a, v) memset(a, v, sizeof a)


// 

vector<set<int>> generate_subsets(set<int>::iterator start, set<int>::iterator end) {
	if(start == end) {
		vector<set<int>> vs;
		set<int> s;
		vs.push_back(s);
		return vs;
	}
	vector<set<int>> res;
	vector<set<int>> subsets;
	auto next = start;
	subsets = generate_subsets(++next, end);
	for(auto it = subsets.begin(); it != subsets.end(); it++) {
		set<int> s(*it);
		res.push_back(s);
		s.insert(*start);
		res.push_back(s);
	}
	return res;	
}

int main() {
	set<int> s;
	int t, elt;
	cin >> t;
	rep(t) {
		cin >> elt;
		s.insert(elt);
	}
	vector<set<int>> subsets = generate_subsets(s.begin(), s.end());
	for(auto aset : subsets) {
		for(auto elt : aset) {
			cout << elt << "\t";
		}
		cout << endl;
	}
	
		
		
	return 0;
}
