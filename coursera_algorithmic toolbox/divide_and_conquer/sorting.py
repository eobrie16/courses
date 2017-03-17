# Uses python3
# Implements a 3-way partition for quicksort
import sys
import random

def partition3(a, l, r):
    x = a[l]
    j = l
    k = l
    for i in range(l+1, r+1):
        if a[i] <= x:
            k += 1
            a[i], a[k] = a[k], a[i]
            if a[k] != x:
                j += 1
                a[j], a[k] = a[k], a[j]
    a[l], a[j] = a[j], a[l]
    return j, k

def partition2(a, l, r):
    x = a[l]
    j = l;
    for i in range(l + 1, r + 1):
        if a[i] <= x:
            j += 1
            a[i], a[j] = a[j], a[i]
    a[l], a[j] = a[j], a[l]
    return j


def randomized_quick_sort(a, l, r):
    if l >= r:
        return
    k = random.randint(l, r)
    a[l], a[k] = a[k], a[l]
    #use partition3
    m = partition2(a, l, r)
    randomized_quick_sort(a, l, m - 1);
    randomized_quick_sort(a, m + 1, r);

def randomized_quick_sort3(a, l, r):
    if l >= r:
        return
    k = random.randint(l, r)
    a[l], a[k] = a[k], a[l]
    m, n = partition3(a, l, r)
    randomized_quick_sort3(a, l, m - 1)
    randomized_quick_sort3(a, n + 1, r)


if __name__ == '__main__':
    # testing
    '''ok = 1
    while ok:
        #x=random.randint(1,10e9)
        n=random.randint(1,10e5)
        a = [random.randint(1,10e9) for i in range(n)]
        b = [x for x in a]
        b.sort()
        import time
        start = time.clock()
        randomized_quick_sort3(a, 0, len(a)-1)
        print ("time = %f" % (time.clock()-start))
        if a != b:
            print (a)
            print (b)
            break
        print ("OK")'''
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    randomized_quick_sort3(a, 0, len(a)-1)
    for x in a:
        print(x, end=' ')
    print ()
