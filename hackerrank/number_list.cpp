/**
	Problem : 
**/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long arr[200000];

int main() {
	long t;
	cin >> t;
	while(t--) {
		long n;
		long long k;
		cin >> n >> k;
		for(long i = 0; i < n; i++)
			cin >> arr[i];
		long run = 0;
		long long sum = 0;
		for(long i = 0; i < n; i++) {
			if(arr[i] > k) {
				sum += (run * (run + 1)) / 2;
				run = 0;
			}
			else
				run += 1;
		}
		sum += (run * (run + 1)) / 2;
		long long total_subarr = (n * (n + 1)) / 2;
		cout << total_subarr - sum << endl;
	}
	return 0;
}
