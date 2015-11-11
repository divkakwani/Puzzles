/*
	Problem:
		
Problem Statement
    
A sequence of numbers is called a zig-zag sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a zig-zag sequence.
For example, 1,7,4,9,2,5 is a zig-zag sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, 1,4,7,2,5 and 1,7,4,5,5 are not zig-zag sequences, the first because its first two differences are positive and the second because its last difference is zero.
Given a sequence of integers, sequence, return the length of the longest subsequence of sequence that is a zig-zag sequence. A subsequence is obtained by deleting some number of elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
    
 eg    
{ 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 }
Returns: 8

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class ZigZag {
	public:
		int longestZigZag(vector<int> sequence) {
			int sz = sequence.size();
			vector<int> states(sz, 1);
			vector<int> last_trend(sz, 0);
			for(int i = 1; i < sz; i++) {
				for(int j = 0; j < i; j++) {
					if(last_trend[j] == -1 && sequence[j] < sequence[i] && states[j] + 1 > states[i]) {
						states[i] = states[j] + 1;
						last_trend[i] = 1;
					}
					else if(last_trend[j] == 1 && sequence[j] > sequence[i] && states[j] + 1 > states[i]) {
						states[i] = states[j] + 1;
						last_trend[i] = -1;
					}
					else if(last_trend[j] == 0 && states[j] + 1 > states[i]) {
						states[i] = states[j] + 1;
						last_trend[i] = sequence[i] > sequence[j] ? 1 : -1;
					}
				}
			}
			
			for(vector<int>::iterator it = states.begin(); it != states.end(); it++)
				cout << *it << "\t";
			cout << endl;
			for(vector<int>::iterator it = last_trend.begin(); it != last_trend.end(); it++)
				cout << *it << "\t";
				
			return *max_element(states.begin(), states.end());
				
		}
};
