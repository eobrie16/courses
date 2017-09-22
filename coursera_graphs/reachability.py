#Uses python3

import sys

visited = set()
def explore(adj, v):
    visited.add(v)
    for a in adj[v]:
        if a not in visited:
            explore(adj, a)
            
def reach(adj, x, y):
    explore(adj, x)
    if y in visited:
        return 1
    return 0

if __name__ == '__main__':
    n, m = map(int, sys.stdin.readline().split())
    data = []
    for _ in range(m):
        data.extend(map(int, sys.stdin.readline().split()))
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    x, y = map(int, sys.stdin.readline().split())
    adj = [[] for _ in range(n)]
    x, y = x - 1, y - 1
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
    print(reach(adj, x, y))
