
#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
    
        long long n, k;
        cin >> n >> k;

        vector<long long> nums(n+1), prefix_sums(n+1);

        nums[0] = 0;    // sentinel
        prefix_sums[0] = 0;
        for(long long i = 1; i <= n; i++) {
            cin >> nums[i];
            prefix_sums[i] = prefix_sums[i-1] + nums[i];
        }
        
        long long ans = 0;
        for (long long i = 1; i <= n; i++) {
            long long diff = prefix_sums[i] - k;
            // only those prefixes with prefix sums >= diff can be taken
            auto it = lower_bound(prefix_sums.begin(), prefix_sums.begin() + i, diff);
            ans += (i - (it-prefix_sums.begin()));
        }
        cout << "Case #" << i << ": " << ans << endl;
    }

}
