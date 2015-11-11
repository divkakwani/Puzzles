/**
	Problem : 
**/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        s += 'X';   // sentinel
        int runsR = 0, runsB = 0, minR = INT_MAX , minB = INT_MAX;
        bool minR_mid = false, minB_mid = false;	// false for end, true for mid;
        int run = 1;
        char prev = s[0];
        int len = s.length();
        int merge_len = 0;
        for(int idx = 1; idx != len; idx++) {
            if(s[idx] == prev)
                run++;
            else {
                // run has ended
                merge_len++;
                if(prev == 'R') {
                    if(run <= minR) {
                    	// check if it lies in mid and change minR
                        if(idx > 1 and idx < len - 1)
                        	minR_mid = true;
                        else if(run < minR)
                        	minR_mid = false;
                        minR = run;
                    }
                    runsR++;
                }
                if(prev == 'B') {
                    if(run <= minB) {
                        if(idx > 1 and idx < len - 1)
                        	minB_mid = true;
                        else if(run < minB)
                        	minB_mid = false;
                        minB = run;
                    }
                    runsB++;
                }
                run = 1;
                prev = s[idx];
            }
           
        }
        if((minR == 1 and runsR > 1 and minR_mid) or (minB == 1 and runsB > 1 and minB_mid))
            	cout << merge_len - 2 << endl;
        else if((minR == 1 and (runsR > 1 or minR_mid)) or (minB == 1 and (runsB > 1 or minB_mid)))
        		cout << merge_len - 1 << endl;
        else
            cout << merge_len << endl;
    }
    return 0;
}
