#Uses python3

import sys
import queue

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

def shortest_paths(adj, cost, s, dist, reachable, shortest):
    # first determine reachability
    print (reachable)
    for v in [x for x in range(len(adj)) if x != s]:
        if not reach(adj, s, v):
            reachable[v] = 0
    reachable[s] = 1
    print (reachable)
    prev = [None for i in range(len(adj))]
    dist[s] = 0
    negative_cycle = -1
    neg_cycle = queue.Queue()
    for iteration in range(len(adj)):
        print (iteration)
        # relax all the edges
        for u in [x for x in range(len(adj)) if reachable[x]]:
            for i, v in enumerate(adj[u]):
                if dist[v] > dist[u] + cost[u][i]:
                    dist[v] = dist[u] + cost[u][i]
                    prev[v] = u
                    if iteration == len(adj)-1:
                        neg_cycle.put(v)
    visited = set()
    while not neg_cycle.empty():
        v = neg_cycle.get()
        if v in visited:
            continue
        visited.add(v)
        shortest[v] = 0
        for i in adj[v]:
            if i not in visited:
                neg_cycle.put(i)


if __name__ == '__main__':
    n, m = map(int, sys.stdin.readline().split())
    data = []
    for _ in range(m):
        data.extend(map(int, sys.stdin.readline().split()))
    s = int(sys.stdin.readline()) - 1
    edges = list(zip(zip(data[0:(3 * m):3], data[1:(3 * m):3]), data[2:(3 * m):3]))
    adj = [[] for _ in range(n)]
    cost = [[] for _ in range(n)]
    for ((a, b), w) in edges:
        adj[a - 1].append(b - 1)
        cost[a - 1].append(w)
    distance = [10**19] * n
    reachable = [0] * n
    shortest = [1] * n
    shortest_paths(adj, cost, s, distance, reachable, shortest)
    print (distance)
    print (shortest)
    for x in range(n):
        if reachable[x] == 0:
            print('*')
        elif shortest[x] == 0:
            print('-')
        else:
            print(distance[x])

