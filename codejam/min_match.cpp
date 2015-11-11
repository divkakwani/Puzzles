/**
	Problem : 
**/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for(int cas = 1; cas <= t; cas++) {
		int n;
		cin >> n;
		vector<long long> a(n), b(n);
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < n; i++)
			cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.rbegin(), b.rend());
		long long product = 0;
		for(int i = 0; i < n; i++) {
			product += a[i] * b[i];
		}
		cout << "Case #" << cas << ": " << product << endl;
	}
	return 0;
}
