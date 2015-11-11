
t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    chains = [int(s) for s in input().split()]
    chains.sort()
    req = m-1
    idx = 0
    cut = 0
    while req > 0:
        if chains[idx] > req:
            cut = cut + req
            req = 0
        else:
            req = req-1
            req = req - chains[idx]
            cut = cut + chains[idx]
            idx = idx+1
    print(cut)
