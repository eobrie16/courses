#Uses python3

import sys
import queue


def distance(adj, s, t):
    dist = [None for i in range(len(adj))]
    dist[s] = 0
    q = [s]
    while len(q):
        u = q.pop()
        for v in adj[u]:
            if dist[v] is None:
                q.append(v)
                dist[v] = dist[u] + 1
            if v == t:
                return dist[v]
    return -1


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
    s, t = map(int, sys.stdin.readline().split())
    print(distance(adj, s-1, t-1))
