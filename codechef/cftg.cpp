/**
	Problem : 
**/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
 


int memo[10000][10000] = {0};
int gcd(int a, int b) {
	if(b == 0)
		{ memo[a][0] = a;return a;}
	if(memo[a][b] != 0)
		return memo[a][b];
	memo[a][b] = gcd(b, a%b);
	return memo[a][b];
}


int ans[10000];
int main() {
	ans[0] = 0;
	ans[1] = 3;
	memo[1][1] = 1;
	for(int i = 2; i < 10000; i++) {
		ans[i] = ans[i-1];
		// find phi - Euler's Toitent
		for(int j = 1; j < i;j++) {
			if(gcd(j, i) == 1)
				ans[i] += 2;
		}
	}
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << ans[n] << endl;
	}		
	return 0;
}
