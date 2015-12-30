#include <bits/stdc++.h>

using namespace std;

int num_moves (string rows[], int x, int y) {
    
    int num = 0;

    if (rows[x][y] != 'o')
        return 0;

    if (x > 1 and rows[x-1][y] == 'o' and rows[x-2][y] == '.')
        num += 1;

    if (x < 5 and rows[x+1][y] == 'o' and rows[x+2][y] == '.')
        num += 1;

    if (y > 1 and rows[x][y-1] == 'o' and rows[x][y-2] == '.')
        num += 1;

    if (y < 5 and rows[x][y+1] == 'o' and rows[x][y+2] == '.')
        num += 1;

    return num;
}


int main() {

    string rows[7];

    for (int i = 0; i < 7; i++) {
        std::getline(std::cin, rows[i]);
    }

    int moves = 0;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            moves += num_moves(rows, i, j); 
        }
    }
    cout << moves << endl;
}
