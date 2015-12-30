

t = int(input())

for _ in range(t):

    n = int(input())
    amps = [int(s) for s in input().split()]

    amps.sort()

    output = []

    # skip all 1s
    start = 0
    while amps[start] == 1:
        start = start+1
        output.append(1)

    if amps[start] == 2 and amps[start+1] == 3:
        output.append(2)
        output.append(3)
        start = start + 2

    for i in amps[start:][::-1]:
        output.append(i)

    print(' '.join(map(str, output)))
