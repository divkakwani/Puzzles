
#include <bits/stdc++.h>

using namespace std;

// if num_a(s) < K, then delete all the non-as first and then start deleting as.
// If num_a(s) > K, then try to move non-as as further to the right as you can.
//

int main(void) {

    int k;
    string s;

    while(true) {

        string res;
        cin >> k >> s;

        if (k == -1) break;

        int nacount = 0;
        for (char c : s)  if (c != 'a') nacount++;
        
        if (s.length() <= k) {
            cout << endl;
        }
        else if (nacount <= k) {
            cout << string(s.length() - k, 'a') << endl;
        }
        else if (k == 0) {
            cout << s << endl;
        }
        else {
            string r;
            
            int lnacnt = 0, nacnt = 0, i = 0, li = -1;
            for (i = 0; i < s.length(); i++) {
                if (s[i] != 'a')    nacnt++;
                else {
                    if (nacnt > k) break;
                    else { lnacnt = nacnt; li = i; }
                }
            }
            r += string(li + 1 + k - lnacnt, 'a');
            int res = std::strcmp(&s[li + 1], &s[li + 1 + k - lnacnt]);
            r += s.substr(res > 0 ? (li + 1 + k - lnacnt) : (li + 1));

            cout << r << endl;

        }
    }
}
