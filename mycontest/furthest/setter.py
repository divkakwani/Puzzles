#!/usr/bin/env python3

__author__ = 'Divyanshu Kakwani'

# Graph Representation:
# G = {node: adjacency list}
# where adjacency list = {node: wt}

def input_graph(nodes):
    "input_graph() => returns a graph G entered via stdin"
    # make an empty graph
    graph = {i: {} for i in nodes}
    for i in range(len(nodes) - 1):
        u, v, D = map(int, input().split())
        graph[u][v] = D
        graph[v][u] = D
    return graph

def farthest(graph, root):
    visited = {i: False for i in graph}
    def postorder_traversal(root=0):
        "returns the distance of the farthest node from root"
        visited[root] = True
        return max((postorder_traversal(adj) + graph[root][adj] 
                    for adj in graph[root] if not visited[adj]),
                   default=0)
    return postorder_traversal(root)

if __name__ == '__main__':
    t = int(input())
    for case in range(t):
        n, h = map(int, input().split())
        graph = input_graph(range(n))
        print(2 * farthest(graph, h))
