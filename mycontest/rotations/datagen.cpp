
#include <bits/stdc++.h>

using namespace std;


int main() {

    long long T = 1000;

    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";


    srand(time(NULL));

    for (long long i = 0; i < T; i++) {
    
        long long len = rand() % 999 + 1;

        string s;
        generate_n(back_inserter(s), len, [&]() { return alphabet[rand() % alphabet.length()];});

        long long l = rand() % 1000;
        long long r = rand() % 1000;
        long long Q = rand() % 1000;

        cout << s << " " << l << " " << r << " " << Q << endl;

        for (long long q = 0; q < Q; q++)
            cout << (rand() % len) << endl;

    }
}
