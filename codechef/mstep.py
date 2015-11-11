
t = int(input())

loc = {}

for _ in range(t):
    n = int(input())
    
    for rowidx in range(n):
        row = [int(s) for s in input().split()]
        for colidx in range(n):
            loc[row[colidx]] = (rowidx, colidx)
    
    ans = 0
    for i in range(2, n*n+1):
        ans = ans + abs(loc[i][0] - loc[i-1][0]) + abs(loc[i][1] - loc[i-1][1])

    print(ans)
        
