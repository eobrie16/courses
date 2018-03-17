#Uses python3
import sys
import math
import queue

def dist(x, y, v, z):
    return math.sqrt(pow((x[z]-x[v]), 2) + pow((y[z]-y[v]), 2))

def find(forest, u):
    for i in range(len(forest)):
        if u in forest[i]:
            return i
    return -1
    

def build_priority_queue(x, y):
    pq = queue.PriorityQueue()
    for i in range(len(x)):
        for j in range(i+1, len(x)):
            pq.put((dist(x,y,i,j), (i, j)))
    return pq
                
def union(forest, u, v):
    u_index = find(forest, u)
    v_index = find(forest, v)
    if u_index == v_index:
        return forest
    forest[u_index] |= forest[v_index]
    return [forest[i] for i in range(len(forest)) if i!=v_index]
            

def clustering(x, y, k):
    forest = []
    for i in range(len(x)):
        forest.append(set([i]))
    X = set()
    pq = build_priority_queue(x, y)
    if len(forest) == k:
        return pq.get()[0]
    while not pq.empty():
        nextitem = pq.get()
        u, v = nextitem[1]
        if find(forest, u) != find(forest, v):
            X.add(u)
            X.add(v)
            forest = union(forest, u, v)
        if len(forest) == k:
            break
    if pq.empty():
        retval = -1.
    else:
        item = pq.get()
        while find(forest, item[1][0]) == find(forest, item[1][1]):
            item = pq.get()
        retval = item[0]
    return retval
    #if not verify_ans(forest, x, y, retval):
    #    sys.exit()
    #else:
    #    return retval
    
def verify_ans(forest, x, y, value):
    min_dist = sys.maxsize
    for i in range(len(forest)):
        for v in range(len(x)):
            if v not in forest[i]:
                for z in list(forest[i]):
                    min_dist = min(min_dist, dist(x, y, v, z))
                    if min_dist < value:
                        print ("Invalid result!")
                        print (forest)
                        print (v, z, min_dist)
                        print ("Expected: ", value)
                        return False
    return True
        
        


if __name__ == '__main__':
    '''import random
    for i in range(100):
        print (i)
        k = random.randint(2,5)
        vals = random.randint(k,10)
        x = []
        y = []
        for _ in range(vals):
            x.append(random.randint(-5,5))
            y.append(random.randint(-5,5))
        print ("input = ", x, y, k)
        print("{0:.9f}".format(clustering(x, y, k)))'''
    n = int(sys.stdin.readline().strip())
    x = []
    y = []
    for _ in range(n):
        x1, y1 = list(map(int, sys.stdin.readline().strip().split()))
        x.append(x1)
        y.append(y1)
    k = int(sys.stdin.readline().strip())
    print("{0:.9f}".format(clustering(x, y, k)))
    
