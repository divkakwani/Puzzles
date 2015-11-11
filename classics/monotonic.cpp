/**
	Problem : Find the longest increasing subsequence in a given array.
**/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int A[1000];	// The input array

int L[1000];	// Length of the longest increasing subsequence
		// ending in A[i]

int rev_ptr[1000] = {-1};

int main() {
	int n, i, j;
	cin >> n;
	for(i = 0; i < n; i++)
		cin >> A[i];
	for(i = 0; i < n; i++)
		L[i] = 1;	// Initially set all to 1 - the subsequence containing only the ith element

	for(i = 0; i < n; i++) {
		for(j = 0; j < i; j++) {
			if(A[j] < A[i] && L[j] + 1 > L[i]) {
				L[i] = L[j] + 1;
				rev_ptr[i] = j;
			}
		}
	}
	cout << endl;
	int last_ele = max_element(L, L + n) - L;
	for(int index = last_ele; index >= 0; index = rev_ptr[index])
		cout << A[index] << "\t";
	cout << endl;
	return 0;
}
