
def dist(a, b):
    return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1])



t = int(input())

for cas in range(1, t+1):
    n = int(input())
    points = []
    for i in range(n):
        x, y = map(int, input().split())
        points.append((x, y))

    distdict = []

    for i in range(n):
        pivot = points[i]
        distdict.append({})
        for end in points:
            distdict[i][dist(pivot, end)] = distdict[i].get(dist(pivot, end), 0) + 1

    ans = 0
    for i in range(n):
        for _, val in distdict[i].items():
            if val >= 2:    ans += (val*(val-1))//2

    print("Case #" + str(cas) + ": " + str(ans))

