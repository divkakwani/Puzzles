/**
	Problem : 
**/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define min(a, b) a > b ? b : a

int main() {
	int t;
	cin >> t;
	while(t--) {
		int m, n, elt;
		cin >> m >> n;
		long long a[100][100], b[100][100], c[100][100];

		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				cin >> a[i][j];


		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				cin >> b[i][j];


		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++) {
				cin >> c[i][j];
				c[i][j] = (min(a[i][j], b[i][j])) * c[i][j];
			}

		long long sum = 0;
		for(int i = 0; i < m; i++) {
			long long max = 0;
			for(int j = 0; j < n; j++)
				if(c[i][j] > max)
					max = c[i][j];
			sum += max;
		}
		cout << sum << endl;
	}
	return 0;
}
