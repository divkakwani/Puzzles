#include <bits/stdc++.h>
using namespace std;


int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	int cross = (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);
	if(cross == 0)
		return 0;
	return cross / abs(cross);
}


typedef pair<int, int> ii;

double angle_x(ii a, ii b) {

	if(a == b)
		return 0.0;
	
	if(b.first == a.first)
		return M_PI / 2.0;
		
	return atan(double(b.second - a.second) / double(b.first - a.first));
}

struct comp {
	int operator()(ii a, ii b) {	
		return a.second < b.second or (a.second == b.second and a.first < b.first);
	}
} c;

struct comp1 {
	int operator()(const pair<ii, double>& a, const pair<ii, double>& b) const {
		return a.second < b.second or (a.second == b.second and a.first < b.first);
	}
} c1;

int main() {
	int n;
	cin >> n;
	int x, y;

	vector<ii> points;
	while(n--) {
		cin >> x >> y;
		points.push_back(ii(x, y));
	}
	ii min = *min_element(points.begin(), points.end(), c);

	set<pair<ii, double>, comp1> S;

	for(auto& pt : points) {
//		cout << pt.first << ", " << pt.second << endl;
		double angle = angle_x(min, pt);
		S.insert(make_pair(pt, angle));
	}

//	for(auto vec : S)
//		cout << vec.first.first << ", " << vec.first.second << endl;
	
	stack<ii> hull;

	for(auto& vec : S) {
		hull.push(ii(vec.first.first, vec.first.second));
		while(1) {
			if(hull.size() < 3)
				break;
			auto pt1 = hull.top();
			hull.pop();
			auto pt2 = hull.top();
			hull.pop();
			auto pt3 = hull.top();
			hull.pop();
			int dir = ccw(pt3, pt2, pt1);
			if(dir >= 0) {
				hull.push(pt3);
				hull.push(pt2);
				hull.push(pt1);
				break;
			}
			else {
				hull.push(pt3);
				hull.push(pt1);
			}
		}

	}
	double len = 0;
	auto pt = hull.top();
	auto pt1 = pt;
	hull.pop();
	while(!hull.empty()) {
		auto pt2 = hull.top();
//		cout << pt2.first << ", " << pt2.second << endl;
		hull.pop();
		int dx = pt2.first - pt1.first;
		int dy = pt2.second - pt1.second;

		double dist =  sqrt(abs(dx * dx + dy * dy));
		len += dist;
		pt1 = pt2;
	}
	len += sqrt(abs((pt1.first - pt.first) * (pt1.first - pt.first) + (pt1.second - pt.second) * (pt1.second - pt.second)));
	cout << (long)len << endl;

}
