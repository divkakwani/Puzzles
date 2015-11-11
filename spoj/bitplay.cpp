
#include <bits/stdc++.h>

using namespace std;

// M(N, K) = G + M(N - G, K-1)


long long M(long long N, long long K) {
    
    if (K == 0) return 0;

    long long v = N;

    // From hacker's delight
    v--;
    for (int i = 0; i <= sizeof(long long); i++) 
        v |= v >> (1 << i);
    v++;
    v = v >> 1;
    
    return v + M(N - v, K-1);
}

int main() {

    long long t;
    cin >> t;

    while (t--) {
        
        long long N, K;
        cin >> N >> K;

        if (K == 0)
            cout << -1 << endl;
        else if (K == 1)
            cout << 1 << endl;
        else
            cout << ((M(N/2, K-1) << 1) | 1) << endl;
    }
}





