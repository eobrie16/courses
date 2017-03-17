# Uses python3
# Counts the inversions needed to sort a given sequence
# Algorithmic toolbox, Week 3.4 (Divide and conquer)

import sys

def merge(b,c):
    #print (b,c)
    d = []
    inversions = 0
    while len(b) and len(c):
        elemB = b[0]
        elemC = c[0]
        if elemB <= elemC:
            d.append(b.pop(0))
        else:
            inversions += len(b)
            d.append(c.pop(0))
    if len(b):
        #inversions += len(b)-len(c)
        d.extend(b)
    if len(c):
        d.extend(c)
    #print (inversions)
    return (inversions,d)

def merge_sort(a):
    inversions = 0
    if len(a) == 1:
        return (0, a)
    m = len(a) // 2
    new, b = merge_sort(a[:m])
    inversions += new
    new, c = merge_sort(a[m:])
    inversions += new
    new, newA = merge(b,c)
    inversions += new
    return (inversions, newA)

if __name__ == '__main__':
    #a = [5,4,3,2,1]
    #a = [2,3,9,2,9]
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    #n, *a = list(map(int, input.split()))
    #b = len(a) * [0]
    number_of_inversions, newA = merge_sort(a)
    print (number_of_inversions)
    #print(get_number_of_inversions(a, b, 0, len(a)))
