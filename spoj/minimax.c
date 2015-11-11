
#include <stdio.h>

/* Author: Divyanshu Kakwani */

/** Boilerplate */

// Constants
#define INF 1e9

typedef long long ll;

// Shorthands for frequently occuring code
#define rep(i, a, b) 	for(i = (a); i < (b); i++)
#define fill(a, v) 	(memset(a, v, sizeof a))
#define max(a, b)	((a) > (b) ? (a) : (b))
#define min(a, b)	((a) < (b) ? (a) : (b))
#define isInt(a)	int(a) == (a) ? true : false

ll low[500000];
ll high[500000];	 
ll num[500000];
ll donetill[500000];

int main() {

	int t;
	scanf("%d", &t);
	while(t--) {
		ll i, j;
		ll tot, sorters;
		scanf("%lld %lld", &tot, &sorters);
		rep(i, 0, sorters)
			scanf("%lld %lld", &low[i], &high[i]);
		
		rep(i, 0, sorters)
			num[i] = 1000000;

		rep(i, 0, sorters) {
			if(low[i] == 1) {
				donetill[i] = high[i];
				num[i] = 1;
				continue;
			}
			rep(j, 0, i) {
				if(donetill[j] >= low[i]) {
					num[i] = min(num[i], num[j] + 1);
					donetill[i] = high[i];
					if(num[i] == 2)	break;
				}
			}
		}
		
		ll ans = 100000;
		rep(i, 0, sorters)
			if(donetill[i] == tot)
				ans = min(ans, num[i]);

		printf("%lld\n", ans);

	}

}
