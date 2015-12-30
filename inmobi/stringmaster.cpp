
#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int repcost, inscost, delcost, swapcost;
int editdist[4010][4010];

// solution
//
//  editdist(i, j) = min(inscost + editdist(i, j+1),
//                       delcost + editdist(i+1, j)
//                       repcost + editdist(i+1, j+1))
//
//

int main() {

    cin >> inscost >> delcost >> repcost >> swapcost;
    cin >> s1 >> s2;
   
    int n = s1.length();
    int m = s2.length();
   

    for (int i = 0; i <= m; i++) 
        editdist[n][i] = (m-i) * inscost;
    for (int i = 0; i <= n; i++)
        editdist[i][m] = (n-i) * delcost;

    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if (s1[i] == s2[j])
                editdist[i][j] = editdist[i+1][j+1];
            else
                editdist[i][j] = min(inscost + editdist[i][j+1],
                                     min(delcost + editdist[i+1][j], repcost + editdist[i+1][j+1]));
        }
    }
    cout << editdist[0][0] << endl;
}

