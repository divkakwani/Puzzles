
#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
    
        long long n;
        cin >> n;

        vector<long long> amps(n);
        for (long long i = 0; i < n; i++)
            cin >> amps[i];
    
        sort(amps.begin(), amps.end());

        long long start = 0;
        while(amps[start] == 1) {
            cout << "1 ";
            start++;
        }
        if(n == start + 2 and amps[start] == 2 and amps[start+1] == 3) {
            cout << "2 3\n";
            continue;
        }

        for (long long int i = n-1; i >= start; i--)
            cout << amps[i] << " ";
        
        cout << endl;

    }
}
