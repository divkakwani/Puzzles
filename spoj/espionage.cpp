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
	for(int i = 1; i <= t; i++) {
		int n, r;
		cin >> n >> r;
		int stat[1000] = {0};
		int spy = 0;
		for(int j = 0; j < r; j++) {
			int a, b;
			cin >> a >> b;
			if(stat[b] == 1 or stat[a] == 2) {
				spy = 1;
			}
			stat[a] = 1;
			stat[b] = 2;
		}
		cout << "Scenario #" << i << ": ";
		if(spy)
			cout << "spied\n";
		else
			cout << "spying\n";
			
	}

	return 0;
}
