
#include <bits/stdc++.h>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        string grid[101];
        int table[101][101];       
        bool path[101][101];

        int h, w;
        cin >> w >> h;

        for (int i = 0; i < h; i++) {
            cin >> grid[i];
        }

        table[h-1][w-1] = (grid[h-1][w-1] == '*') ? 1 : 0;


        // lower row
        for (int j = w-2; j >= 0; j--) {
            path[h-1][j] = 1;
            if (table[h-1][j+1] == -1)
                table[h-1][j] = -1;
            else if (grid[h-1][j] == '#') {
                table[h-1][j] == -1;
            }
            else {
                table[h-1][j] = table[h-1][j+1];
                if (grid[h-1][j] == '*')
                    table[h-1][j] += 1;
            }
        }
        for (int j = h-2; j >= 0; j--) {
            path[j][w-1] = 0;
            if (table[j+1][w-1] == -1)
                table[j][w-1] = -1;
            else if (grid[j][w-1] == '#') {
                table[j][w-1] == -1;
            }
            else {
                table[j][w-1] = table[j+1][w-1];
                if (grid[j][w-1] == '*')
                    table[j][w-1] += 1;
            }
        }
            

        for (int i = h-2; i >= 0; i--) {
            for (int j = w-2; j >= 0; j--) {
                if (grid[i][j] == '#')
                    table[i][j] = -1;
                else {
                    int down = table[i+1][j];
                    int right = table[i][j+1];
                    if (right > down) {
                        path[i][j] = 1;
                        table[i][j] = right;
                    } else {
                        path[i][j] = 0;
                        table[i][j] = down;
                    }
                    if (grid[i][j] == '*')
                        table[i][j] += 1;
                }
            }
        }

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++)
                cout << table[i][j] << " ";
            cout << endl;
        }

        cout << table[0][0] << endl;
    
    }
}
