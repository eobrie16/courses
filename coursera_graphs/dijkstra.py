#Uses python3

import sys
import queue


def naive_distance(adj, cost, s, t):
    dist = [sys.maxsize for i in range(len(adj))]
    prev = [None for i in range(len(adj))]
    dist[s] = 0
    distChanged = True
    while distChanged:
        distChanged = False
        # relax all the edges
        for u in range(len(adj)):
            for i, v in enumerate(adj[u]):
                if dist[v] > dist[u] + cost[u][i]:
                    dist[v] = dist[u] + cost[u][i]
                    prev[v] = u
                    distChanged = True
    return dist[t] if dist[t] < sys.maxsize else -1

def distance(adj, cost, s, t):
    dist = [sys.maxsize for i in range(len(adj))]
    prev = [None for i in range(len(adj))]
    dist[s] = 0
    H = queue.PriorityQueue()
    H.put((dist[s], s))
    while not H.empty():
        d, u = H.get()
        # relax all the edges
        for i, v in enumerate(adj[u]):
            if dist[v] > dist[u] + cost[u][i]:
                dist[v] = dist[u] + cost[u][i]
                prev[v] = u
                H.put((dist[v], v))
    return dist[t] if dist[t] < sys.maxsize else -1


if __name__ == '__main__':    
    n, m = map(int, sys.stdin.readline().split())
    data = []
    for _ in range(m):
        data.extend(map(int, sys.stdin.readline().split()))
    edges = list(zip(zip(data[0:(3 * m):3], data[1:(3 * m):3]), data[2:(3 * m):3]))
    s, t = map(int, sys.stdin.readline().split())
    adj = [[] for _ in range(n)]
    cost = [[] for _ in range(n)]
    for ((a, b), w) in edges:
        adj[a - 1].append(b - 1)
        cost[a - 1].append(w)
    #print (adj)
    #print (cost)
    print(distance(adj, cost, s-1, t-1))
