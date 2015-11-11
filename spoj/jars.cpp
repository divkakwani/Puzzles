#include <bits/stdc++.h>

using namespace std;

int main() {

    long n, q, x;
    cin >> n >> q;
   
    if (n == 0 and q == 0) return 0;

    map<long, bitset<61>> no_of_pieces;
    
    bitset<61> b;
    b.set(0);
    no_of_pieces[0] = b;

    for (long i = 0; i < n; i++) {
        cin >> x;
        map<long, bitset<61>> next = no_of_pieces;
        for (auto it = no_of_pieces.begin(); it != no_of_pieces.end(); it++) {

            bitset<61> b;
            if (no_of_pieces.find(it->first + x) != no_of_pieces.end())
                b = no_of_pieces[it->first + x];
            
            next[it->first + x] = (it->second) << 1;
            next[it->first + x] |= b;

        }
        no_of_pieces = std::move(next);
    
    }
    for (long i = 0; i < q; i++) {
        cin >> x;
        map<long, bitset<61>>::const_iterator cit;

        if (x <= 0 or (cit = no_of_pieces.find(x)) == no_of_pieces.end())
            cout << "That's impossible!\n";
        else {
            bitset<61> b = cit->second;
            for (int i = 1; i < 61; i++)
                if (b.test(i))
                    cout << i << " ";
            cout << endl;
        }
    }

    main();
    
}
