#Uses python3
import sys
import math
import queue

def dist(x, y, v, z):
    return math.sqrt(pow((x[z]-x[v]), 2) + pow((y[z]-y[v]), 2))

def minimum_distance(x, y):
    # Prim
    result = 0.
    cost = [sys.maxsize for i in range(len(x))]
    parent = [None for i in range(len(x))]
    done = set()
    cost[0] = 0
    pq = queue.PriorityQueue()
    pq.put((0.0,0))
    while not pq.empty():
        v = pq.get()
        if v[1] in done:
            continue
        if parent[v[1]] is not None:
            result += dist(x, y, v[1], parent[v[1]])
        for j in range(len(x)):
            if j == v[1]:
                continue
            if j not in done and cost[j] > dist(x, y, v[1], j):
                cost[j] = dist(x, y, v[1], j)
                parent[j] = v[1]
                pq.put((cost[j], j))
        done.add(v[1])
    return result


if __name__ == '__main__':
    n = int(sys.stdin.readline().strip())
    x = []
    y = []
    for _ in range(n):
        x1, y1 = list(map(int, sys.stdin.readline().strip().split()))
        x.append(x1)
        y.append(y1)
    print("{0:.9f}".format(minimum_distance(x, y)))
