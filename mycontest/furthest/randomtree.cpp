
/* (c) Divyanshu Kakwani <divkakwani@gmail.com>
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {

    if (argc != 2)  { cerr << "wrong number of arguments"; exit (-1); }

    long long n = stoll(argv[1]);
    const long long D = 10e9;

    vector<long long> nodes;
    for (long long i = 0; i < n; i++)   nodes.push_back(i);

    random_shuffle(nodes.begin(), nodes.end());

    // seed rng with time
    srand(time(NULL));

    vector<long long> tree(n);
    for(long long i = 1; i < n; i++)
        tree[i] = (rand() % i);

    // print tree
    cout << n << " " << (rand() % n) << endl; // total nodes, house location
    for (long long i = 1; i < n; i++)
        cout << tree[i] << " " << i << " " << (rand() % D) << endl;




    return 0;
}
