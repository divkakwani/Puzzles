
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

int main() {
	long int m, n;
	while(cin >> n >> m) {
		long int vessels[1000];
		inpN(vessels, n);
		long int lo = 1, high = 1e9, mid = 0;
		while(1) {
			if(2 * mid == (lo + high)) {
				cout << mid; el
				break;
			}

			mid = (lo + high) / 2;
			// narrow_the search space
			long int ves = 0, cont = 0;
			while(ves < n and cont < m) {
				long int meter = 0;
				while(1) {
					if(meter + vessels[ves] <= mid) {
						meter += vessels[ves];
						ves++;
						if(ves == n)
							break;
					}
					else {
						if(meter == 0) {
							lo = mid + 1;
							goto end;
						}
						cont++;
						break;
					}
				}
			}
			if(ves >= n) {
				high = mid;
			}
			else
				lo = mid + 1;
			end:
			{}
		}
	}
}

