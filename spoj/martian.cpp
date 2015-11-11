/**
	Problem : 
**/
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sol_memo[500][500] = {-1};
int right_sum[500][500];
int bottom_sum[500][500];
int a[500][500];
int b[500][500];
int n, m;
int optimal_sol(int i, int j) {
	if( sol_memo[i][j] != -1)
		return sol_memo[i][j];
	if( i == n-1 and j == m-1) {
		sol_memo[i][j] = max(a[i][j], b[i][j]);
		return sol_memo[i][j];
	}
	if(i >= 0 and j >= 0) {
		sol_memo[i][j] = max(optimal_sol(i+1, j) + right_sum[i][j], optimal_sol(i, j+1) + bottom_sum[i][j]);
		return sol_memo[i][j];
	}
	throw runtime_error("Invalid Input");
}

void calc_bottom_sum_a(int i, int j) {
	i -= 1; // index of the last row
	// set the bottom row
	for(int x = 0; x < j; x++)
		bottom_sum[i][x] = a[i][x];
	i -= 1; // last row has been processed
	while(i >= 0) {
		for(int y = 0; y < j; y++)
			bottom_sum[i][y] = bottom_sum[i+1][y] + a[i][y];
		i -= 1; // one more row processed
	}
}

void calc_right_sum_b(int i, int j) {
	j -= 1; // index of the rightmost column
	// set the rightmost column
	int x, y;
	for(x = 0; x < i; x++)
		right_sum[x][j] = b[x][j];
	j -= 1; // rightmost col processed
	while(j >= 0) {
		for(x = 0; x < i; x++)
			right_sum[x][j] = right_sum[x][j+1] + b[x][j];
		j -= 1; 
	}
}

int main() {
	while(1) {
	cin >> n >> m;
	if(n == 0 and m == 0)
		break;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			sol_memo[i][j] = -1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> b[i][j];
	calc_right_sum_b(n, m);
	calc_bottom_sum_a(n, m);
	cout << optimal_sol(0, 0) << endl;
	}




	return 0;
}
