
#include <bits/stdc++.h>

using namespace std;


/** Boilerplate */
// Macros and typedefs

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

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
// Debugging macros
#define show(x)		cout << #x << ": " << x << endl;

// Miscellaneous
#define nosync ios_base::sync_with_stdio(0);


// k(x + y) = xy; 

int main() {
	nosync;
	int k;
	while(cin >> k) {
		int counter = 0;
		for(int i = k + 1; ; i++) {
			if(isInt((k * i)/(i - k)))
				cout << "1/" << i << " + " << "1/" << (k*i)/(i-k) << endl;
			if((k*i)/(i-k) <= k)
				break;
		}
	}
}
