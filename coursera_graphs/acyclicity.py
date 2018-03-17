#Uses python3
import sys
sys.setrecursionlimit(200000)


visited = set()
def explore(adj, curvisit, v):
    visited.add(v)
    curvisit.add(v)
    for a in adj[v]:
        if a in curvisit or explore(adj, curvisit, a):
            return True
        curvisit.remove(a)
    return False

def acyclic(adj):
    for i in range(len(adj)):
        if i not in visited and explore(adj, set(), i):
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
