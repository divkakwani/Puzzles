/**
	Problem : 
**/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long int memo[2001][2001] = {0};

long long int solve(int i, int j) {
	if(j < 0)
		return 0L;
	if( i <= j)
		return 0L;
	if(memo[i][j] != 0)
		return memo[i][j];
	memo[i][j] =  (solve(i, j-1) + solve(i-1, j)) % 1000000007;
	return memo[i][j];
	
}
long long int another_memo[2001][2001] = {0};

long long int stressful(int i, int j, int max_j) {
	if(i < 0)
		return 0;
	if(i > max_j)
		return stressful(i-1, j, max_j);
	if(i > j)
		return 0L;
	if(another_memo[i][j] != 0)
		return another_memo[i][j];
	another_memo[i][j] = (stressful(i-1, j, max_j) + stressful(i, j-1, max_j))%1000000007;
	return another_memo[i][j];
}

int main() {
	memo[0][0] = 1;
	another_memo[0][0] = 1;
	memo[1][0] = 1;
	another_memo[0][1] = 1;
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int a, b;
		char sep;
		cin >> a >> sep >> b;
		cout << "Case #" << i << ": ";
		cout << solve(a, b) << " " << stressful(a, b, b) << endl;
	}
	return 0;
}
