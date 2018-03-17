#Uses python3

import sys


def negative_cycle(adj, cost):
    dist = [sys.maxsize for i in range(len(adj))]
    prev = [None for i in range(len(adj))]
    dist[0] = 0
    is_negative_cycle = 0
    for iteration in range(len(adj)):
        # relax all the edges
        for u in range(len(adj)):
            for i, v in enumerate(adj[u]):
                if dist[v] > dist[u] + cost[u][i]:
                    dist[v] = dist[u] + cost[u][i]
                    prev[v] = u
                    if iteration == len(adj)-1:
                        is_negative_cycle = 1
    return is_negative_cycle


if __name__ == '__main__':
    n, m = map(int, sys.stdin.readline().split())
    data = []
    for _ in range(m):
        data.extend(map(int, sys.stdin.readline().split()))
    edges = list(zip(zip(data[0:(3 * m):3], data[1:(3 * m):3]), data[2:(3 * m):3]))
    adj = [[] for _ in range(n)]
    cost = [[] for _ in range(n)]
    for ((a, b), w) in edges:
        adj[a - 1].append(b - 1)
        cost[a - 1].append(w)
    print(negative_cycle(adj, cost))
