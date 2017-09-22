#Uses python3

import sys

visited = set()
def explore(adj, x):
    cycle = 0
    visited.add(x)
    for a in adj[x]:
        if cycle or a in visited:
            return 1
        cycle = explore(adj, a)
        visited.remove(a)
    return cycle

def acyclic(adj):
    for i in range(len(adj)):
        if i not in visited:
            if explore(adj, i):
                return 1
    return 0

if __name__ == '__main__':
    n, m = map(int, sys.stdin.readline().split())
    data = []
    for _ in range(m):
        data.extend(map(int, sys.stdin.readline().split()))
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
    print(acyclic(adj))
    
    '''input = sys.stdin.read()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
    print(acyclic(adj))'''
