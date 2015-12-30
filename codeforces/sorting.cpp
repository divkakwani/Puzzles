
#include <bits/stdc++.h>

using namespace std;

long long arr[100002];
long long dp[100002];
long long loc[100002];

int main() {
    
    long long n;
    cin >> n;

    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        loc[arr[i]] = i;
    }
    loc[n+1] = -1;
    long long longest_streak = 1, curr_streak = 1;
    for (long long i = 2; i <= n; i++) {
        if (loc[i] > loc[i-1])
            curr_streak += 1;
        else {
            longest_streak = max(longest_streak, curr_streak);
            curr_streak = 1;
        }
    }
    cout << n - longest_streak;

}
