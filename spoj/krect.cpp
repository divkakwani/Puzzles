
#include <bits/stdc++.h>

using namespace std;

int dp[101][101][101][101];

int main() {

    int m, n, k;
    cin >> m >> n >> k;

    vector<string> grid;

    string s;
    for(int i = 0; i < m; i++) {
        cin >> s;
        grid.emplace_back(s);
    }
    long long count = 0;
    // enumerate each of the sub-rectangle
    for (int height = 1; height <= m; height++) {
        for (int width = 1; width <= n; width++) {
            for (int x = 0; x <= n-width; x++) {
                for (int y = 0; y <= m-height; y++) {
                    //cout << "[(" << x << ", " << y << "), (" << x+width-1 << ", "<< y+height-1<<"]\n";
                    if (height == 1 and width == 1) {
                        dp[height][width][y][x] = (1 << (grid[y][x]-'A'));
                    }
                    else if (height == 1) {
                        dp[height][width][y][x] = dp[height][width-1][y][x] | (1 << (grid[y][x+width-1] - 'A'));
                    }
                    else {
                        dp[height][width][y][x] = dp[height-1][width][y][x] | dp[1][width][y+height-1][x];
                    }
                    if (__builtin_popcount(dp[height][width][y][x]) == k)
                        count++;
                }
            }
        
        }
    }
    cout << count << endl;

}
