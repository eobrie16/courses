#Uses python3
# Maximize revenue
# algorithmic toolbox, Greedy algorithms #3

import sys
#import random, time

def max_dot_product(a, b):
    a.sort()
    b.sort()
    res = 0
    for i in range(len(a)):
        res += a[i] * b[i]
    return res

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    b = list(map(int, sys.stdin.readline().split()))
    print(max_dot_product(a, b))
    '''start = time.clock()
    a = []
    b = []
    for i in range(10000):
        a.append(random.randint(-10e5, 10e5))
        b.append(random.randint(-10e5, 10e5))
    print(max_dot_product(a, b))
    print (time.clock()-start)'''
