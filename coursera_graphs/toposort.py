#Uses python3

import sys
from collections import deque

def dfs(adj, used, order, x):
    used.add(x)
    for a in adj[x]:
        if a not in used:
            order = dfs(adj, used, order, a)
            order.appendleft(a)
    #used.remove(x)
    return order
            

def toposort(adj):
    used = set()
    order = deque()
    for x in range(len(adj)):
        if x not in used:
            order = dfs(adj, used, order, x)
            order.appendleft(x)
    return order

if __name__ == '__main__':
    n, m = map(int, sys.stdin.readline().split())
    data = []
    for _ in range(m):
        data.extend(map(int, sys.stdin.readline().split()))
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
    order = toposort(adj)
    for x in order:
        print(x + 1, end=' ')
    print ()

