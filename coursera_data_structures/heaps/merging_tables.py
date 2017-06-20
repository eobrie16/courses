# python3

import sys

n, m = map(int, sys.stdin.readline().split())
lines = list(map(int, sys.stdin.readline().split()))
rank = [1] * n
parent = list(range(0, n))
ans = max(lines)

def getParent(table):
    #while table != parent[table]:
    #    table = getParent(parent[table])
    #return parent[table]
    if table != parent[table]:
        parent[table] = getParent(parent[table])
    return parent[table]

def merge(destination, source):
    realDestination, realSource = getParent(destination), getParent(source)

    if realDestination != realSource:

        if rank[realDestination] > rank[realSource]:
            parent[realSource] = realDestination
            lines[realDestination] += lines[realSource]
            lines[realSource] = 0
        else:
            parent[realDestination] = realSource
            if rank[realDestination] == rank[realSource]:
                rank[realSource] += 1
            lines[realSource] += lines[realDestination]
            lines[realDestination] = 0


    #print (lines)
    #print (parent)
    #print (rank)
    return max(lines)

for i in range(m):
    destination, source = map(int, sys.stdin.readline().split())
    ans = merge(destination - 1, source - 1)
    print(ans)
