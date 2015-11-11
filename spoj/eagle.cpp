#include <bits/stdc++.h>

using namespace std;

using Tp = long long;

// the tuple stores the adjacent vertex, the cost of the edge leading to it and the longest
// path through it.
using adj_list = vector<tuple<Tp, Tp, Tp>>; 

Tp longest_path_len(adj_list* G, Tp vertex, Tp prev) {
    
    Tp longest_len = 0;
    
    for (auto it = G[vertex].begin(); it != G[vertex].end(); it++) {
       
        Tp u          = get<0>(*it);
        Tp edge_wt    = get<1>(*it);
        Tp len_thru_u = get<2>(*it);

        if(u != prev and len_thru_u == -1) {
            get<2>(*it) = edge_wt + longest_path_len(G, u, vertex);
        }

        if(u != prev)
            longest_len = max(longest_len, get<2>(*it));
    }

    return longest_len;
}

adj_list G[100000];

int main() {
   
    int T;
    cin >> T;
    while(T--) {

        Tp n;
        cin >> n;

        /* wted_graph G(n); */

        Tp u, v, wt;
        for (Tp i = 0; i < n-1; i++) {
            cin >> u >> v >> wt;
            G[u-1].emplace_back(v-1, wt, -1);
            G[v-1].emplace_back(u-1, wt, -1);
        }

        for (Tp u = 0; u < n; u++) {
            cout << longest_path_len(G, u, -1) << " ";
        }
        cout << endl;
    }


}
