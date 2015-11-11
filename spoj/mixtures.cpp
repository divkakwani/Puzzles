/**
	Problem : http://www.spoj.com/problems/MIXTURES/
	Problem code: MIXTURES
	Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).
	He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the resulting mixture in their place.
	When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.
	Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.

	Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.

**/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

#define PR(x) cout << #x << " : " << x << endl;
using namespace std;

int optimal_mixtures[100][100];
int min_smokes[100][100];

int dp(int* mixture, int begin, int end) {
	// returns the resulting mixture which yields the minimal smoke
	if(begin == end) {
		optimal_mixtures[begin][end] = mixture[begin];
		min_smokes[begin][begin] = 0;
		return mixture[begin];
	}
	if(end == begin + 1) {

		optimal_mixtures[begin][end] = (mixture[begin] + mixture[end]) % 100;
		min_smokes[begin][end] = mixture[begin] * mixture[end];
		return optimal_mixtures[begin][end];
	}
	if(optimal_mixtures[begin][end] != -1)
		return optimal_mixtures[begin][end];
	
	int min_smoke = 10000;
	int optimal_mixture = 10000;
	int smoke;
	int split;
	int new_mixture;
	for(split = begin + 1; split < end; split++) {
		smoke = dp(mixture, begin, split) * dp(mixture, split + 1, end);
		new_mixture = (dp(mixture, begin, split) + dp(mixture, split + 1, end)) % 100;
		if(smoke < min_smoke) {
			min_smoke = smoke;
			optimal_mixture = new_mixture;
			min_smokes[begin][end] = min_smokes[begin][split] + min_smokes[split+1][end] + min_smoke;
		}
	}
	PR(begin) PR(split) PR(end)
	optimal_mixtures[begin][end] = optimal_mixture;
	return optimal_mixture;
}

int main() {

	int n;
	while(cin >> n) {
		int mixtures[100];
		for(int i = 0 ; i < n; i++)
			for(int j = 0; j < n; j++)
				optimal_mixtures[i][j] = -1;
		for(int i = 0 ; i < n; i++)
			for(int j = 0; j < n; j++)
				min_smokes[i][j] = -1;
		int mixture;
		for(int i = 0; i < n; i++) {
			cin >> mixture;
			mixtures[i] = mixture;
		}	
		dp(mixtures, 0, n-1);		
		cout << min_smokes[0][n-1] << endl;
	}
	return 0;
}
