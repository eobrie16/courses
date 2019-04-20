#Uses python3

import sys
import queue

def bipartite(adj):
    flag = [None for i in range(len(adj))]
    flag[0] = 0
    q = [0]
    while len(q):
        u = q.pop()
        for v in adj[u]:
            if flag[v] is None:
                q.append(v)
                flag[v] = flag[u] ^ 1
            if flag[u] == flag[v]:
                return 0
    return 1

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
    print(bipartite(adj))
