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
		int n;
		cin >> n;
		string num_str = to_string(n);
		string num = num_str, num1 = num_str;
		int len = num.length();

		vector<char> smallest_elt(len);
		vector<char> smallest_elt_idx(len);
		smallest_elt[len - 1] = num1[len - 1];
		smallest_elt_idx[len - 1] = len - 1;
		for(int it = len - 2; it != -1; it--) {
			smallest_elt[it] = smallest_elt[it + 1] <= num1[it] ? smallest_elt[it + 1] : num1[it];
			smallest_elt_idx[it] = smallest_elt[it + 1] <= num1[it] ? smallest_elt_idx[it + 1] : it;
		}
		for(int it = 0; it != len - 1; it++)
			if(it == 0) {
				int min_idx = 0;
				for(int it1 = 1; it1 != len; it1++)
					if(num1[it1] <= num1[min_idx] and num1[it1] != '0')
						min_idx = it1;
				if(min_idx != 0 and num1[min_idx] < num1[0]) {
					swap(num1[0], num1[min_idx]);
					break;
				}
			}
			else
				if(num1[it] > smallest_elt[it + 1]) {
					swap(num1[it], num1[smallest_elt_idx[it + 1]]);
					break;
				}
		cout << "Case #" << i << ": " << num1 << " ";
		
		vector<char> gr8est_elt(len);
		vector<char> gr8est_elt_idx(len);
		gr8est_elt[len - 1] = num[len - 1];
		gr8est_elt_idx[len - 1] = len - 1;
		for(int it = len - 2; it != -1; it--) {
			gr8est_elt[it] = gr8est_elt[it + 1] >= num[it] ? gr8est_elt[it + 1] : num[it];
			gr8est_elt_idx[it] = gr8est_elt[it + 1] >= num[it] ? gr8est_elt_idx[it + 1] : it;
		}
		for(int it = 0; it != len - 1; it++)
			if(num[it] < gr8est_elt[it + 1]) {
				swap(num[it], num[gr8est_elt_idx[it + 1]]);
				break;
			}
		cout << num << endl;
	}
	return 0;
}
