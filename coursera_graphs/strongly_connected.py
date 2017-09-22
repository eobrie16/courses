#Uses python3

import sys
from collections import deque

sys.setrecursionlimit(200000)

def explore(adj, visited, order, v):
    visited.add(v)
    for a in adj[v]:
        if a not in visited:
            order = explore(adj, visited, order, a)
    order.appendleft(v)
    return order

def dfs(adj, visited, order, x):
    for v in range(len(adj)):
        if v not in visited:
            order = explore(adj, visited, order, v)
    return order

def number_of_strongly_connected_components(adj, adj_rev):
    result = 0
    order = dfs(adj_rev, set(), deque(), 0)
    visited = set()
    for v in order:
        if v not in visited:
            explore(adj, visited, deque(), v)
            result += 1
    return result

if __name__ == '__main__':
    n, m = map(int, sys.stdin.readline().split())
    data = []
    for _ in range(m):
        data.extend(map(int, sys.stdin.readline().split()))
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    adj_rev = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
        adj_rev[b - 1].append(a - 1)
    print(number_of_strongly_connected_components(adj, adj_rev))

