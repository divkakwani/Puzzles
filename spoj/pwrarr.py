
t = int(input())

for i in range(t):
    n = int(input())
    arr = [int(s) for s in input().split()]
    
    d = {}
    for i in arr:
        d[i] = d.get(i, 0) + 1


        
