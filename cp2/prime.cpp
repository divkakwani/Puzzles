
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


const int sz = 10000001;
bitset<sz> primes;
long int no[10000001];
	
int main() {
	long int pm = 0;
	no[1] = 1;
	rep(i, 2, sz) {
		if(primes[i] == 0) {
			pm += 1;
			int n = 2 * i;
			while(n < sz) {
				primes[n] = true;
				n += i;
			}
		}
		
		no[i] = pm;
	}
	
	int q;
	cin >> q;
	rep(i, 0, q) {
		int l, r;
		cin >> l >> r;
		cout << no[r] - no[l] - !primes[r] << endl;		
	}
}
