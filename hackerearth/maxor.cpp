#include <bits/stdc++.h>

using namespace std;




int main() {

    vector<long long> subset_cnt(128);
    subset_cnt[0] = 1;

    long long n;
    cin >> n;

    int a;

    while(n--) {

        vector<long long> new_subset_cnt = subset_cnt;

        cin >> a;

        for(int i = 0; i < 128; i++)
            if(subset_cnt[i])   new_subset_cnt[i ^ a] += subset_cnt[i];

        subset_cnt = new_subset_cnt;
    }


    long long ans = 0;

    for(int i = 1; i < 128; i++) {
        if(subset_cnt[i] > 1)
            ans += (subset_cnt[i] * (subset_cnt[i] - 1)) / 2;
    }

    cout << ans << endl;
}
