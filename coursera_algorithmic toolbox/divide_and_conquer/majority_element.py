# Uses python3
# The goal in this code problem is to check whether an input sequence
#  contains a majority element
# Algorithmic Toolbox, Week3.2 (Divide and Conquer)
import sys, random

def swap(a, i, j):
    temp = a[i]
    a[i] = a[j]
    a[j] = temp

def partition(a, left, right):
    x = a[left]
    j = left
    k = left
    for i in range(left+1, right+1):
        if a[i] <= x:
            k += 1
            swap(a, i, k)
            if a[k] != x:
                j += 1
                swap(a, j, k)
    a[left] = a[j]
    a[j] = x
    return j, k

def get_majority_element(a, left, right):
    if len(a) == 1:
        return a[0]
    if left >= right:
        return -1
    pivot = random.randint(left,right)
    #print (pivot)
    swap(a, left, pivot)
    m, n = partition(a, left, right)
    #print (a)
    if n-m+1 > len(a) // 2:
        return a[n]
    if m-left > len(a) // 2:
        return get_majority_element(a, left, m-1)
    if right-n > len(a) // 2:
        return get_majority_element(a, n+1, right)
    return -1

if __name__ == '__main__':
    '''while 1:
        x=random.randint(1,10e9)
        n=random.randint(1,10e5)
        a = [x if i%2==0 else 0 for i in range(n)]
        import time
        start = time.clock()
        num = get_majority_element(a, 0, len(a)-1)
        print ("time = %f" % (time.clock()-start))
        if n%2:
            expected = x
        else:
            expected = -1
        if num != expected:
            print (a)
            print (n)
            print ("Should get %s" % expected)
            print ("But got %s instead" % num)
            break
        else:
            print ("OK")'''

    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    if get_majority_element(a, 0, n-1) != -1:
        print(1)
    else:
        print(0)
