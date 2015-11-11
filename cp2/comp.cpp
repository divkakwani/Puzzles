
#include <bits/stdc++.h>

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
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define fill(a, v) memset(a, v, sizeof a)


// 
int main() {
	int n;
	cin >> n;
	unordered_map<string, pair<string, string>> fns;
	string name, inp, out;
	rep(i, 0, n) {
		cin >> name >> inp >> out;
		fns[out] = make_pair(name, inp);
	}
	inp = "opt";
	string res = "";
	while(inp != "inp") {
		res += fns[inp].first;
		res += ".";
		inp = fns[inp].second;
	}
	int sz = res.length() - 1;
	rep(i, 0, sz)
		cout << res[i];
	cout << endl;
}
