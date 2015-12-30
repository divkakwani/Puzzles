/* Contains implementation of union find */

#include <stdio.h>
#include <stdbool.h>

long leader[100001];
long sizes[100001];

long getleader(long x) {
    long root = x;
    while (root != leader[root])
        root = leader[root];
    /* Do path compression */
    long curr = x;
    while (curr != root) {
        long parent = leader[curr];
        leader[curr] = root;
        curr = parent;
    }
    return root;
}

long getsize(long x) {
    return sizes[getleader(x)];
}

void setunion(long x, long y) {
    /* setunion by rank */
    long l1 = getleader(x);
    long l2 = getleader(y);
    long sz1 = getsize(l1);
    long sz2 = getsize(l2);
    
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

bool sameset(long x, long y) {
    return getleader(x) == getleader(y);
}

bool diffset(long x, long y) {
    return !sameset(x, y);
}

int main() {

    long n, m, Q;
    scanf ("%ld %ld %ld", &n, &m, &Q);

    for (int i = 0; i <= n; i++) {
        leader[i] = i;
        sizes[i] = 1;
    }

    char type;
    long x, y;

    for (int q = 0; q < Q; q++) {

        while (scanf ("%c", &type)) {
            if (type == 'A' || type == 'E' || type == 'S')
                break;
        }

        switch(type) {
            case 'A':
                scanf ("%ld %ld", &x, &y);
                int sz1 = getsize(x);
                int sz2 = getsize(y);
                if (sz1 + sz2 <= m) {
                    setunion(x, y);
                }
                break;
            case 'S':
                scanf ("%ld", &x);
                printf ("%ld\n", getsize(x));
                break;
            case 'E':
                scanf ("%ld %ld", &x, &y);
                if (sameset(x, y))
                    printf("Yes\n");
                else
                    printf("No\n");
                break;            
        }
    }
}
