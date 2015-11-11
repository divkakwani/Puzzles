
#include <bits/stdc++.h>

using namespace std;

int main() {

    long long n;
    cin >> n;

    string s;
    cin >> s;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 2) {
        cout << 2 << endl;
        return 0;
    }

    vector<vector<bool>> is_pd(n);

    for (auto& bv : is_pd)
        for(long long i = 0; i < n; i++)
            bv.push_back(false);

    for (long long i = 0; i < n; i++) {
        is_pd[i][i] = true;
        is_pd[i][i+1] = true;
    }
    
    long long maxlen = 2;

    for (long long len = 3; len <= n; len++) { 
        for (long long i = 0; i < n - len + 1; i++) {
            if (is_pd[i+1][i+len-2] and s[i] == s[i+len-1]) {
                is_pd[i][i+len-1] = true;
                maxlen = len;
            }
            else
                is_pd[i][i+len-1] = false;
        }
    }
    cout << maxlen << endl;

}
