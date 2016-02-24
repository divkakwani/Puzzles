
from decimal import *


def upper_bound(lst, k):
    
    if lst[len(lst)-1] < k: return len(lst)

    def __bin_srch__(start, end):
        if start == end:    return start
        mid = (start+end)//2
        if lst[mid] > k  : return __bin_srch__(start, mid)
        elif lst[mid] <= k : return __bin_srch__(mid+1, end)

    return __bin_srch__(0, len(lst)-1)

t = int(input())

for _ in range(t):
    n = int(input())
    Q = int(input())
    arr = [Decimal(s) for s in input().split()]
    arr.sort()
    for q in range(Q):
        k = Decimal(input())
        ans = upper_bound(arr, k)
        print(len(arr)-ans)

