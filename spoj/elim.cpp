#include <bits/stdc++.h>

using namespace std;

int main () {

	while(1) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		int i;
		vector<int> candidates;
		while(ss >> i) {
			if(i == 0)
				return 0;
			candidates.push_back(i);
		}
		int n = candidates.size();
		getline(cin, s);
		ss.str("");
		ss.clear();
		ss << s;
		int cnt = 0;
		n >>= 1;
		vector<int> next_cand;
		while(ss >> i) {
			next_cand.push_back(candidates[i-1]);
			cnt++;
			if(cnt == n) {
				candidates = next_cand;
				next_cand.clear();
				n >>= 1;
				cnt = 0;
			}
		}
		cout << candidates[0] << endl;
	
	}
}






