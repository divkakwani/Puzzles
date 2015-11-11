/**
	Problem : Check if one string is an anagram of another
**/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	string name1, name2;
	while(t--) {
		cin >> name1 >> name2;
		int chars1[26] = {0}, chars2[26] = {0};
		for(int i = 0; i < name1.length(); i++) {
			chars1[name1[i] - 'a']++;
			chars2[name2[i] - 'a']++;
		}
		bool cmp = 1;
		for(int i = 0; i < 26; i++)
			if(chars1[i] != chars2[i])
				cmp = 0;
		if(cmp)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
