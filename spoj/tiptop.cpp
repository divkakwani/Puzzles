/**
	Problem : 
**/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	long long t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		long long n;
		cin >> n;
		long long rt_n = sqrt(n);
		if(rt_n * rt_n == n)
			cout << "Case " << i << ": Yes\n";
		else
			cout << "Case " << i << ": No\n";
	}
	return 0;
}
