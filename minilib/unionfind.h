/* Contains implementation of union find */


template<typename BaseTp, long long sz>
class UnionFind {
    
    BaseTp leader[sz];
    BaseTp sizes[sz];

 public: 

    UnionFind() {
        for (BaseTp i = 0; i < sz; i++) {
            leader[i] = i;
            sizes[i] = 1;
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

    BaseTp getsize(BaseTp x) {
        return sizes[getleader(x)];
    }

    void setunion(BaseTp x, BaseTp y) {
        /* setunion by rank */
        BaseTp l1 = getleader(x);
        BaseTp l2 = getleader(y);
        BaseTp sz1 = getsize(l1);
        BaseTp sz2 = getsize(l2);
    
        if (l1 != l2) {
            if (sz1 < sz2) {
                leader[l1] = l2;
                sizes[l2] = sz1 + sz2;
            } else {
                leader[l2] = l1;
                sizes[l1] = sz1 + sz2;
            }
        }
    }

    bool sameset(BaseTp x, BaseTp y) {
        return getleader(x) == getleader(y);
    }

    bool diffset(BaseTp x, BaseTp y) {
        return !sameset(x, y);
    }
};

