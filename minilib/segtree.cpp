
#include <bits/stdc++.h>

using namespace std;

/// code-start

template<typename assoc_Tp, typename combine_func>
class SegTree {

 private:
     vector<assoc_Tp> tree;    // flattened tree
     
     optional<assoc_Tp> range_query(int index, int lo, int hi, int i, int j) {
        // if (i, j) is outside (lo, hi)    return 
     }

 public:
     optional<assoc_Tp> range_query(int i, int j) {
     }

};



/// code-end



/// test-start


/// test-end
