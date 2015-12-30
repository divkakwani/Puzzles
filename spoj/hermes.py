

n = int(input())

coords = []

# input coords
for i in range(n):
    x, y = map(int, input().split())
    coords.append((x, y))

# states[p][0] = go from point p onwards optimally starting at p[0]
# states[p][1] = go from point p onwards optimally starting at p[1]
# states[p][0] = max(states[p+1][0] states[p+1][1]

states = []



def optimal(pt, x=0, y=0):
    
    if states[pt]:
        dx = abs(coords[pt][0] - x)
        dy = abs(coords[pt][1] - y)
        return max(dx + states[pt][0], dy + states[pt][1])

    optimal(pt+1, coords[pt][0], y) optimal

