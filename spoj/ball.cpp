#include <bits/stdc++.h>

using namespace std;

map<long long, set<pair<long long, long long>>> belts;

pair<long long, pair<long long, long long>>
intercept(long long x, long long y) {
	// return y coordinate of the point of interception

	auto nil = make_pair(0, make_pair(0, 0));

	auto it = belts.lower_bound(y);
	if(it == belts.begin())
		return nil;
	it--;

	set<pair<long long, long long>>::iterator range;
	while(1) {;
		range = (it->second).upper_bound(make_pair(x, 1000000000LL));	// 3 is dummy; just concerned with the first value
		if(range == (it->second).begin())
			return nil;
		range--;
		if(x <= range->second)
				break;
		if(it == belts.begin())
			return nil;
		it--;
	}
	return make_pair(it->first, *range);
}

map<pair<long long, pair<long long, long long>>, long long> memo;

long long max_belts(long long x, long long y) {

	if(y == 0)
		return 0;
	pair<long long, pair<long long, long long>> b = intercept(x, y);
	if(b.first == 0)
		return 0;
	if(memo.find(b) != memo.end())
		return memo[b];
	memo[b] = 1 + max(max_belts(b.second.first - 1, b.first), max_belts(b.second.second + 1, b.first));
	return memo[b];
}

int main() {

	long long N, X1, X2, Y, Q, init_x;
	cin >> N;
	while(N--) {
		cin >> X1 >> X2 >> Y;
		belts[Y].insert(make_pair(X1, X2));
	}

	cin >> Q;
	while(Q--) {
		cin >> init_x;
		cout << max_belts(init_x, 1000000000LL) << endl;
	}
		
}
