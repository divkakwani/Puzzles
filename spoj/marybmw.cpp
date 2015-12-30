#include <bits/stdc++.h>

using namespace std;

template<typename BaseTp, long long sz>
class UnionFind {
    
    BaseTp leader[sz];

 public: 

    UnionFind(long long size) {
        for (BaseTp i = 0; i < size; i++) {
            leader[i] = i;
        }
    }

    BaseTp getleader(BaseTp x) {
        BaseTp root = x;
        while (root != leader[root])
            root = leader[root];

        /* Do path compression */
        BaseTp curr = x;
        while (curr != root) {
            BaseTp parent = leader[curr];
            leader[curr] = root;
            curr = parent;
        }
        return root;
    }

    void setunion(BaseTp x, BaseTp y) {
        BaseTp l1 = getleader(x);
        BaseTp l2 = getleader(y);
   
        leader[l1] = l2;
    }

    bool sameset(BaseTp x, BaseTp y) {
        return getleader(x) == getleader(y);
    }
};

int main() {
    
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--) {

        long long n, m;
        cin >> n >> m;

        vector<tuple<long long, long long, long long>> edges;

        long long u, v, cost; 
        for (long long i = 0; i < m; i++) {
            cin >> u >> v >> cost;
            edges.push_back(make_tuple(u, v, cost));
        }

        sort(edges.begin(), 
             edges.end(), 
             [](auto a, auto b) {
                return get<2>(a) < get<2>(b);    
        });

        UnionFind<long long, 50010> uf(n+2);

        long long least_wt = -1;
        for (auto it = edges.rbegin(); it != edges.rend(); it++) {
            uf.setunion(get<0>(*it), get<1>(*it));
            if (uf.sameset(1, n)) {
                least_wt = get<2>(*it);
                break;
            }
        }
        cout << least_wt << endl;
    }
}
