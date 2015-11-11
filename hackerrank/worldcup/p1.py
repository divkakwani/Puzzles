

n = int(input())

graph = {}

for i in range(1, n+1):
    w, p = map(int, input().split())
    graph[i] = (w, p)

# Properties on the graph

visited = [False for _ in range(n+1)]
treeid  = [-1 for _ in range(n+1)]
hascycle = {}
cyclelen = {}
product = {}

def graph_dfs():
    
    curr_id = 1

    def single_dfs(vtx):
        treeid[vtx] = curr_id
        visited[vtx] = True
        product[curr_id] = product.get(curr_id, 1) * graph[vtx][1]
        cyclelen[curr_id] = cyclelen.get(curr_id, 0) + 1
        if visited[graph[vtx][0]] and treeid[vtx] == treeid[graph[vtx][0]]:
            hascycle[curr_id] = True
        elif visited[graph[vtx][0]] and treeid[vtx] != treeid[graph[vtx][0]]:
            hascycle[curr_id] = False
        else:
            single_dfs(graph[vtx][0])
    
    for node in range(1, n+1):
        if not visited[node]:
            single_dfs(node)
            curr_id = curr_id + 1

    ans = 0
    for i in product:
        if hascycle[i]:
            ans = ans + (product[i]/pow(100, cyclelen[i]))
    return ans

print(graph_dfs())



