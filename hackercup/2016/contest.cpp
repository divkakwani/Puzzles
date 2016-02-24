
#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (int cas = 1; cas <= t; cas++) {
    
        long long n;
        cin >> n;

        int ds[100];
        for (int i = 0; i < 100; i++)   ds[i] = 0;

        int d;
        for (long long i = 0; i < n; i++) {
            cin >> d;
            ds[d-1]++;
        }

        int it = 0;
        while (ds[it] == 0) it++;
        int last = 99;
        while(ds[last] == 0)    last--;

        int additions = 0;

        while(it != last) {
            bool flag=true;
            for (int i = 1; i <= 10; i++) {
                if (ds[it+i] != 0) {
                    it = it+i;
                    flag=false;
                    break;
                }
            }
            if (flag) {
                cout << it;
                ds[it+10] = 1;
                additions++;
                n++;
            }
        }
        additions += ((n%4) ? (4-(n%4)): 0);

        cout << "Case #" << cas << ": " << additions << endl;
    
    }

}
