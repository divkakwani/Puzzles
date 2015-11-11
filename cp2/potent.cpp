
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
#define rep(i, a)  for(int i = 0; i < (a); i++)
#define fill(a, v) memset(a, v, sizeof a)


// 

int main() {

	int dim;
	int corners, wt;
	while(cin >> dim) {
		vector<int> weights, pot;
		corners = 1 << dim;
		rep(i, corners) {
			cin >> wt;
			weights.push_back(wt);
		}
		rep(i, corners) {
			pot.push_back(0);
			rep(j, dim)
				pot[i] += weights[i ^ (1 << j)];
		}
		int max_sum = 0;
		rep(i, corners) {
			int max = 0;
			rep(j, dim)
				max = pot[i ^ (1 << j)] > max ? pot[i ^ (1 << j)] : max;
			int sum = pot[i] + max;
			max_sum = sum > max_sum ? sum : max_sum;
		}
		cout << max_sum << endl;
	}
}



