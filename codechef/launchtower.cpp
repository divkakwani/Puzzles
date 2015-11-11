
#include <bits/stdc++.h>

using namespace std;

short table[20000][20000];

int main() {

    string s;
    cin >> s;

    long long int len = s.length();

    int q;
    cin >> q;

    while (q--) {
        int m, l;
        cin >> m >> l;

        long long ans = 0;

        for (long long int i = 0; i < len; i++) {
            table[i][i] = (s[i] - '0') % m;
            if (table[i][i] == l)   ans++;
            for (long long int j = i + 1; j < len; j++) {
                table[i][j] = (table[i][j-1] * 10 + (s[j] - '0')) % m;
                if (table[i][j] == l)   ans++;
            }
        }
        cout << ans << endl;
    }
}
