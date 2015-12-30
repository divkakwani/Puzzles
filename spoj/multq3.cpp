#include <cstdio>
#include <iostream>

using namespace std;

/* Two operations:
 *  0 A B -> increment all the numbers between A and B (inclusive) by 1.
 *  1 A B -> prlong the number of numbers between index A and index B that are divisible by 3.
 */

/* Implementation via segment tree
 *  Associated with every node is a triple: 
 *      <mod0, mod1, mod2> 
 */

 
/* The segment tree is linearized and stored in a 1-D array */
long tree[1000010][3];

/* Laziness */
long pending_rots[1000010] = {0};

/* build a segtree for A[0..N-1] = {0..0} */
void build(long nidx, long l, long r) {
    if (l == r) {
        tree[nidx][0] = 1;
        tree[nidx][1] = tree[nidx][2] = 0;
    }
    else {
        build(2*nidx, l, (r+l)/2);
        build(2*nidx+1, (r+l)/2+1, r);
        tree[nidx][0] = r-l+1;
        tree[nidx][1] = tree[nidx][2] = 0;
    }
}

long query(long nidx, long nl, long nr, long l, long r) {
    
    if (nr < l or nl > r)   // no overlap
        return 0;

    if (pending_rots[nidx] != 0) {
        long rots = pending_rots[nidx];
        long mod0 = tree[nidx][0];
        long mod1 = tree[nidx][1];
        long mod2 = tree[nidx][2];
        tree[nidx][rots%3] = mod0;
        tree[nidx][(1+rots)%3] = mod1;
        tree[nidx][(2+rots)%3] = mod2;
        
        pending_rots[2*nidx] += pending_rots[nidx];
        pending_rots[2*nidx+1] += pending_rots[nidx];
        pending_rots[nidx] = 0;
    }

    if (nr <= r and l <= nl)    // contained within
        return tree[nidx][0];

    long lch = query(2*nidx, nl, (nl+nr)/2, l, r);
    long rch = query(2*nidx+1, (nl+nr)/2+1, nr, l, r);
    return lch+rch;
}


void range_incr(long nidx, long nl, long nr, long l, long r) {

    bool flag = false;
    if (nr <= r and l <= nl) {   // contained within
        pending_rots[nidx] += 1;
        flag = true;
    }

    if (pending_rots[nidx] != 0) {
        long rots = pending_rots[nidx];
        long mod0 = tree[nidx][0];
        long mod1 = tree[nidx][1];
        long mod2 = tree[nidx][2];
        tree[nidx][rots%3] = mod0;
        tree[nidx][(1+rots)%3] = mod1;
        tree[nidx][(2+rots)%3] = mod2;
        
        pending_rots[2*nidx] += pending_rots[nidx];
        pending_rots[2*nidx+1] += pending_rots[nidx];
        pending_rots[nidx] = 0;
    }

    if (nr < l or nl > r)   // no overlap
        return;

     if (!flag) {
        range_incr(2*nidx, nl, (nl+nr)/2, l, r);
        range_incr(2*nidx+1, (nl+nr)/2+1, nr, l, r);

        tree[nidx][0] = tree[2*nidx][0] + tree[2*nidx+1][0];
        tree[nidx][1] = tree[2*nidx][1] + tree[2*nidx+1][1];
        tree[nidx][2] = tree[2*nidx][2] + tree[2*nidx+1][2];
    }
}


int main() {
    long N, Q;
    scanf("%ld %ld", &N, &Q);
    build(1, 0, N-1);

    long type, a, b;

    while(Q--) {
        scanf("%ld %ld %ld", &type, &a, &b);
        
        if (type == 0)
            range_incr(1, 0, N-1, a, b);
        else
            printf("%ld\n", query(1, 0, N-1, a, b));

        /* for (long i = 1; i < 32; i++) { */
        /*     cout << i << ": " << tree[i][0] << "\t" << tree[i][1] << "\t" << tree[i][2] << endl; */
        /* } */
        /* for (long i = 1; i < 32; i++) { */
        /*     cout << i << ": " << pending_rots[i] << endl; */
        /* } */
    }
}


