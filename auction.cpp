/**
	Problem : 
**/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const long int N = 10e3;
long int ans[1000];
int wrap_arounds[1000] = {0};
int main() {
	for(long int i = 0; i < 1000; i++) {
		ans[i] = i;
		wrap_arounds[i] = 0;
		for(long int j = 0; j < i; j++) {
			if(wrap_arounds[j] > wrap_arounds[i]) {
				ans[i] = (ans[j] * (i - j)) % (1000000000+7);
				if(ans[j] * (i-j) > (1000000000 + 7))
					wrap_arounds[i] = wrap_arounds[j] + 1;
				else
					wrap_arounds[i] = wrap_arounds[j];
			}
			else if(wrap_arounds[j] == wrap_arounds[i] ) {			
				if(ans[j] * (i-j) > ans[i])
					ans[i] = (ans[j] * (i-j)) % (1000000000 + 7);
				if(ans[j] * (i-j) > 1000000000 + 7)
					wrap_arounds[i] += 1;
			}
			else {
				int rounds = (ans[j] * (i-j)) / (1000000000+7);
				if(rounds + wrap_arounds[j] > wrap_arounds[i]) {
					ans[i] = (ans[j] * (i-j)) % (1000000000+7);
					wrap_arounds[i] = rounds + wrap_arounds[j];
				}
				else if(rounds + wrap_arounds[j] == wrap_arounds[i]) {
					if(ans[j] * (i-j) % (1000000000 + 7)  > ans[i]%(1000000000 + 7))
						ans[i] = (ans[j] * (i-j)) % (1000000000 + 7);
				}
			}
		}
	}
	for(int i = 0; i < 20; i++)
	cout << i << " : " << ans[i] << endl;
	cout << ans[998] << endl;
	cout << ans[999] << endl;
	return 0;
}
