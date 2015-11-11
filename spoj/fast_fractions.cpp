
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


struct num {
	
	int x;
	int y;

	bool operator<(const num& a) const {
		return x * a.y < y * a.x;
	}
	num(int a, int b) {
		x = a;
		y = b;
	}

};
	
int memo[5001][5001] = {0};

int gcd(int a, int b) {
	if(b == 0)
		return a;
	if(memo[a][b])
		return memo[a][b];
	memo[a][b] = gcd(b, a % b);
	return memo[a][b];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >>  m;
		vector<num> fractions;
		int x1, y1, x2, y2, x, y;
		x1=0,y1=1,x2=1,y2=n;
		fractions.push_back(num(x1, y1));
		fractions.push_back(num(x2, y2));
		x=1;y=n;
		while (y!=1.0)
		{
    		x=floor((y1+n)/(y2))*x2-x1;
    		y=floor((y1+n)/(y2))*y2-y1;
    		fractions.push_back(num(x, y));
   		 	x1=x2,x2=x,y1=y2,y2=y;
		}
		
		int q;
		while(m--) {
			cin >> q;
			cout << fractions[q-1].x << "/" << fractions[q-1].y << endl;
		}

	}

}
