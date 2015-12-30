
#include <bits/stdc++.h>

using namespace std;

long long hts[50001];

long long tree[500000];

long long query(long nid, long l, long r, long ql, long qr) {
    
    if (ql <= l and r <= qr) 
        return tree[nid];
    else if (l > qr or ql > r)
        return -1;
    else
        return max(query(2*nid, l, (l+r)/2, ql, qr), query(2*nid+1, (l+r)/2+1, r, ql, qr));
}

long long build(long nid, long l, long r) {

    if (l == r) {
        tree[nid] = hts[r];
        return hts[r];
    }
    tree[nid] = max(build(2*nid, l, (l+r)/2), build(2*nid+1, (l+r)/2 +1, r));
    return tree[nid];
}

int main() {

    long n, m;
    cin >> n >> m;

    for (long i = 0; i < n; i++)
        cin >> hts[i];

    build(1, 0, n-1);

    long a, b, ans = 0;

    for (long q = 0; q < m; q++) {
        cin >> a >> b;
        --a;--b;    // adjustments
        if (query(1, 0, n-1, a+1, b-1) <= hts[a])
            ans++;
    }
    cout << ans << endl;
}
