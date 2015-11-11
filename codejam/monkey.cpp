
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/* Author: Divyanshu Kakwani */

/** Boilerplate */


// Constants
#define INF 1e9


// Shorthands for frequently occuring code
#define rep(i, a, b) 	for(int i = (a); i < (b); i++)
#define inpN(a, n)	rep(hZxWQ, 0, n) cin >> a[hZxWQ]; 
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

int count[101][101];
int chars[101][101];


int main() {
	nosync;
	int t;
	cin >> t;
	rep(i, 1, t+1) {
		memset(count, 0, 101*101*sizeof(int));
		memset(chars, 0, 101*101*sizeof(int));
		int k, l , s;
		cin >> k >> l >> s;
		string ks, ls;
		cin >> ks >> ls;

		// generate a table
		bool table[100] = {false};
		for(int i = 1; i < l; i++) {
			table[i] = true;
			for(int j = i; j < l; j++)
				if(ls[j] != ls[j-i])
					table[i] = false;
		}
		int max_overlap = l;
		for(int i = 0; i < l; i++)
			if(table[i]) {
				max_overlap = i;
				break;
			}

		int max_inst = ceil(double(s-l+1)/max_overlap);
		for(int i =0; i < l; i++)
			cout << table[i] << "\t";
		el
		show(max_inst);


		for(int i = l-1; i < s; i++) {
			count[1][i] = 1;
			chars[1][i] = l;
		}

		for(int inst = 2; inst <= max_inst; inst++) {
			for(int idx = 0; idx < s; idx++) {
				for(int idx2 = idx + 1; idx < s; idx2++) {
					if(idx2 < idx + l and table[idx2-idx]) {
						count[inst+1][idx2] += count[inst][idx];
						chars[inst+1][idx2] += chars[inst][idx] + (idx2-idx);
					}
					else if(idx2 >= idx + l) {
						count[inst+1][idx2] += count[inst][idx];
						chars[inst+1][idx2] += chars[inst][idx] + l;
					}
				}
			
			}
		
		}

		long double ans = 0;

		for(int i = 0; i <= max_inst; i++) {
		
			for(int j = 0; j < s; j++) {
				
				ans += (max_inst - i) * pow(k, -chars[i][j]);
			}	
		}
		cout << ans;

		
	
	}
}
