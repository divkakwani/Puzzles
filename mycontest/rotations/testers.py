
t = int(input())

for case in range(t):
    s, l, r, q = input().split()
    l, r, q = int(l), int(r), int(q)

    start = (0 + l - r) % len(s)

    for query in range(q):
        index = int(input())
        print(s[(start+index)%len(s)])



