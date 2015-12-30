
#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (int cas = 1; cas <= t; cas++) {
        int num_nodes;
        cin >> num_nodes;

        int parent[1000];
        int ancestor_a[1000];

        // intialize all the three arrays with -1
        for (int i = 0; i < num_nodes; i++) 
            parent[i] = ancestor_a[i] = -1;

        // User input
        for (int nid = 0; nid < num_nodes; nid++) {
            /* input for nid'th node */
            int num_child, child;
            cin >> num_child;

            for (int cid = 0; cid < num_child; cid++) {
                cin >> child;
                --child;
                parent[child] = nid;
            }
        }

        int queries;
        cin >> queries;

        cout << "Case " << cas << ":\n";

        for (int q = 0; q < queries; q++) {
            int u, v;
            cin >> u >> v;
            --u; --v;

            int lca = -1;

            // first mark-off u's ancestors...
            // we use q as a marker to distinguish it from previous markings
            int node = u;
            while (parent[node] != -1) {
                ancestor_a[node] = q;
                node = parent[node];
            }
            ancestor_a[node] = q;

            // now mark-off v's ancestors
            node = v;
            while (ancestor_a[node] != q) {
                node = parent[node];
            }
            cout << node + 1 << endl;
        }



    }

}
