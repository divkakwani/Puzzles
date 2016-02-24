
#include <bits/stdc++.h>

using namespace std;


int main() {

    int t;
    cin >> t;


    for (int i = 1; i <= t; i++) {
    
        int n;
        cin >> n;

        string row1, row2;
        cin >> row1 >> row2;
        row1 += "X"; row2 += "X";   // sentinels

        int blockslen1[1002];
        for (int j = 0; j < row1.length(); j++) {
            if (row1[j] == '.') {
                int start = j;
                int end = start+1;
                while(row1[end] == '.') end++;

                for (int k = start; k < end; k++)
                    blockslen1[k] = end-start;
                
                j += blockslen1[start];
            }
        }
            
        int blockslen2[1002];
        for (int j = 0; j < row2.length(); j++) {
            if (row2[j] == '.') {
                int start = j;
                int end = start+1;
                while(row2[end] == '.') end++;

                for (int k = start; k < end; k++)
                    blockslen2[k] = end-start;

                j += blockslen2[start];
            }
        }

        int nblocks1 = 0;
        for(int j = 0; j < row1.length(); j++) {
            if (row1[j] == '.') {
                if (blockslen1[j] > 1)
                    nblocks1++;
                else if (blockslen1[j] == 1) {
                    if (row2[j] == 'X' or blockslen2[j] == 1)
                        nblocks1++;
                }
                j += blockslen1[j];
            }
        }

        int nblocks2 = 0;
        for(int j = 0; j < row2.length(); j++) {
            if (row2[j] == '.') {
                if (blockslen2[j] > 1)
                    nblocks2++;
                else if (blockslen2[j] == 1) {
                    if (row1[i] == 'X') nblocks2++;
                }
                j += blockslen2[j];
            }
        }

        cout << "Case #" << i << ": " << nblocks1+nblocks2 << endl;
    }
}
