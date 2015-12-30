
#include <bits/stdc++.h>


using namespace std;

    
int32_t n;
int32_t max_wt;
int32_t memo[500][2000001];

vector<pair<int32_t, int32_t>> items(500);

int32_t knapsack01 (int32_t item_no, int32_t wt_left) {
    
    if (item_no >= n)
        return 0;
    if (items[item_no].second > wt_left)
        return knapsack01 (item_no + 1, wt_left);
    if (memo[item_no][wt_left] != 0)
        return memo[item_no][wt_left];
    memo[item_no][wt_left] = max(knapsack01(item_no + 1, wt_left), items[item_no].first + knapsack01(item_no + 1, wt_left - items[item_no].second));
    return memo[item_no][wt_left];   
}


int main() {
    
    std::ios::sync_with_stdio(false);

    cin >> max_wt >> n;

    for (int32_t i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }
    cout << knapsack01(0, max_wt);
}
