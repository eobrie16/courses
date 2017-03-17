# Uses python3
# Basic binary search
# Algorithmic Toolbox, Divide and Conquer #1

import sys

def binary_search(a, x):
    if (len(a)) == 0:
        return -1
    left, right = 0, len(a)
    index = (left+right)//2
    while (a[index] != x):
        if x < a[index]:
            right = index
        elif x > a[index]:
            left = index+1
        if left == right:
            return -1
        index = (left+right)//2
    return index


def linear_search(a, x):
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1


"""
Simple binary search (week3, problem 1)
"""
if __name__ == '__main__':
    # testing
    '''import time
    a = [x for x in range(10000) if x%3 != 0]
    x = 9999
    start = time.clock()
    print linear_search(a, x)
    print time.clock()-start
    start = time.clock()
    print binary_search(a, x)
    print time.clock()-start'''
    # input is n and sequence of n-1 integers
    input = sys.stdin.readline()
    data = list(map(int, input.split()))
    n = data[0]
    a = data[1 : ]
    # list of integers to search for in given list
    search = list(map(int, sys.stdin.readline().split()))
    for x in search[1:]:
        print(binary_search(a, x), end=' ')
    print()
