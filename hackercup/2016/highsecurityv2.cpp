
#include <bits/stdc++.h>

using namespace std;

struct block_t {
    int start;
    int end;
    bool taken;
    
    int len() const { return end-start+1; }
};



block_t blockslist1[1000];
int inv_map1[1001];

block_t blockslist2[1000];
int inv_map2[1001];


// row must be demarcated by a X.
int find_blocks(block_t* blockslist, int* inv_map, const string& row) {

    int bid = 0;
    for (int i = 0; i < row.length(); i++) {
        if (row[i] == '.') {
            blockslist[bid].start = i;
            blockslist[bid].taken = false;
            while (row[i] == '.') {
                inv_map[i] = bid;
                i++;
            }
            blockslist[bid].end = i-1;
            bid++;
        }
    }
    return bid;
}


int main() {

    int t;
    cin >> t;

    for (int cas = 1; cas <= t; cas++) {
    
        int n;
        cin >> n;

        string row1, row2;
        cin >> row1 >> row2;
        row1 += 'X';
        row2 += 'X';

        int nblks1 = find_blocks(blockslist1, inv_map1, row1);
        int nblks2 = find_blocks(blockslist2, inv_map2, row2);


        /* for (int i = 0; i < nblks2; i++) { */
        /*     cout << blockslist2[i].start << "\t" << blockslist2[i].end << endl; */
        /* } */


        int ans = 0;

        for (int i = 0; i < nblks1; i++) {
            if (blockslist1[i].len() >= 2) {
                ans++;
            } else {
                int rowcol = blockslist1[i].start; 
                if (row2[rowcol] == 'X' or blockslist2[inv_map2[rowcol]].len() == 1)
                    ans++;
                else if (blockslist2[inv_map2[rowcol]].taken == true) 
                        ans++;
                else
                    blockslist2[inv_map2[rowcol]].taken = true;
            }
        }


        for (int i = 0; i < nblks2; i++) {
            if (blockslist2[i].len() >= 2) {
                ans++;
            } else {
                int rowcol = blockslist2[i].start; 
                if (row2[rowcol] == 'X')
                    ans++;
                else if (blockslist1[inv_map1[rowcol]].len() > 1) {
                    if (blockslist1[inv_map1[rowcol]].taken == true) 
                        ans++;
                    else
                        blockslist1[inv_map1[rowcol]].taken = true;
                }
            }
        }

        cout << "Case #" << cas << ": " << ans << endl;
       
    }

}





