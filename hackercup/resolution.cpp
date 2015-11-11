/**
	Problem : 
**/
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class tpl {
	public:
		int a;
		int b;
		int c;
	tpl() {
		a = b = c = 0;
	}
	tpl(int aa, int bb, int cc) {
		a = aa;
		b = bb;
		c = cc;
	}
	/*
	tpl(const tpl& t) {
		a = t.a;
		b = t.b;
		c = t.c;
	}
	tpl& operator=(tpl& t) {
		if(this == &t)
			return *this;
		this->a = t.a;
		this->b = t.b;
		this->c = t.c;
		return *this;
	}
	*/
	bool operator==(const tpl& t) const {
		if(this->a == t.a and this->b == t.b and this->c == t.c)
			return true;
		return false;
	}
	/*
	bool operator>(const tpl& t) const {
		return this->a + this->b + this->c > t.a +  t.b + t.c;
	*/
	bool operator<(const tpl& t) const {
		if(this->a == t.a and this->b == t.b and this->c == t.c)
			return false;
		if(this->a < t.a)	return true;
		else if(this->a > t.a)	return false;
		if(this->b < t.b)	return true;
		else if(this->b > t.b)	return false;
		if(this->c < t.c)	return true;
		else if(this->c > t.c)	return false;
	}
};

int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int p, c, f, n;
		cin >> p >> c >> f >> n;
		vector<tpl> foods;
		tpl t;
		for(int j = 0; j < n; j++) {
			cin >> t.a >> t.b >> t.c;
			foods.push_back(t);
		}
		set<tpl> seq_sum, aux_set;
		seq_sum.insert(tpl(0, 0, 0));	// nutritional value of 0 number of foods
		int count = 0;
		for(auto& food : foods) {
			
			aux_set = seq_sum;
			for(auto it = seq_sum.begin(); it != seq_sum.end(); it++) 
				aux_set.insert(tpl(it->a + food.a, it->b + food.b, it->c + food.c));
			seq_sum = aux_set;
			//if(count++ < 3)
			 // for_each(seq_sum.begin(), seq_sum.end(), [](const tpl& t){ cout << t.a << " " << t.b << " " << t.c << endl;});
			//cout << endl;
		}
		t.a = p; t.b = c; t.c = f;
		bool possible = (seq_sum.find(t) != seq_sum.end());
		if(possible)
			cout << "Case #" << i << ": yes" << endl;
		else
			cout << "Case #" << i << ": no" << endl;
	}
	return 0;
}
