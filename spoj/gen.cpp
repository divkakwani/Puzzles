#include <bits/stdc++.h>
using namespace std;

int main() {


	ofstream of("out");
	of << 1 << " ";
	of << 5000 << " " ;
	of << 10000  << " ";
	for(int i = 1; i <= 10000; i++)
		of << rand() % 7600459 << " ";


}
