/**
	Problem : 
**/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		map<int, int> tree;
		int gift[200001] = {0};
		set<int> leaves;
		int n, j;
		int manager;
		cin >> n;
		for(j = 1; j <= n; j++) {
			cin >> manager;
			tree[i] = manager;
			leaves.insert(i);
			leaves.erase(manager);
		}
		for(auto it = leaves.begin(); it != leaves.end(); it++) {
			gift[*it] = 1;
			int parent = tree[*it];
			int child = *it;
			while(parent != 0) {
				if(child > 1)
					parent[gift] = 1;
				else
					parent[gift] = child + 1;
				child = parent;
				parent = tree[parent];

			}
		}
		int sum = 0;
		for(int k = 0; k <= 200000; k++)
			sum += gift[i];
		cout << "Case #" << i <<": " << sum << endl;
	}
	return 0;
}
