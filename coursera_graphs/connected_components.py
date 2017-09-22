#Uses python3

import sys

visited = set()
def explore(adj, x):
    visited.add(x)
    for a in adj[x]:
        if a not in visited:
            explore(adj, a)

def number_of_components(adj):
    result = 0
    for v in range(len(adj)):
        if v not in visited:
            explore(adj, v)
            result += 1
    return result

if __name__ == '__main__':
    n, m = map(int, sys.stdin.readline().split())
    data = []
    for _ in range(m):
        data.extend(map(int, sys.stdin.readline().split()))
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
    print(number_of_components(adj))
