# Uses python3
# In this problem, you are given a set of bars of gold
#  and your goal is to take as much gold as possible into your bag.
#  There is just one copy of each bar and for each bar you can either
#  take it or not (hence you cannot take a fraction of a bar).
# Algorithmic toolbox, Week 4.2

import sys

def non_optimal_weight(W, w):
    # write your code here
    result = 0
    for x in w:
        if result + x <= W:
            result = result + x
    return result

def optimal_weight(W, w):
    value =[]
    for i in range(len(w)+1):
        value.append([0 for j in range(W+1)])
    for i in range(1,len(w)+1):
        for j in range(1,W+1):
            value[i][j] = value[i-1][j]
            if w[i-1] <= j:
                val = max(value[i-1][j-w[i-1]]+w[i-1], value[i][j])
                value[i][j] = val
    return value[len(w)][W]

if __name__ == '__main__':
    '''W=10000
    w=[5553, 6498, 1685, 155, 6]
    print (optimal_weight(W,w))'''
    W, n = map(int,sys.stdin.readline().split())
    w = list(map(int, sys.stdin.readline().split()))
    print(optimal_weight(W, w))
