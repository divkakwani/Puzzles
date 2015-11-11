
#include <bits/stdc++.h>

using namespace std;


/** Boilerplate */
// Macros and typedefs

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1e9

#define gcd __gcd

// Shorthands for frequently occuring code
#define rep(a) for(int i = 0; i < (a); i++)
#define fill(a, v) memset(a, v, sizeof a)


//

int main() {
	unordered_map<string, int> dict;
	vector<string> words;
	vector<string> ls_words;
	string word;
	while(cin >> word and word != "#") {
		words.push_back(word);

		transform(word.begin(), word.end(), word.begin(), ::tolower);
		sort(word.begin(), word.end());

		ls_words.push_back(word);

		if(dict.find(word) != dict.end())
			dict[word] += 1;
		else
			dict[word] = 1;
	}
	int sz = words.size();
	rep(sz) {
		if(dict[ls_words[i]] == 1)
			cout << words[i] << endl;
	}
	return 0;
	
}
