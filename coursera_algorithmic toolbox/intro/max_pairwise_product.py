# Uses python3
import random

def maxProduct(a):
    result = 0
    for i in range(0, n):
        for j in range(i+1, n):
            if a[i]*a[j] > result:
                result = a[i]*a[j]

    return result

def maxProductFast(a):
    maxIndex1 = -1
    for i in range(n):
        if maxIndex1 == -1 or a[i] > a[maxIndex1]:
            maxIndex1 = i
    maxIndex2 = -1
    for j in range(n):
        if maxIndex1 != j and (maxIndex2 == -1 or a[j] > a[maxIndex2]):
            maxIndex2 = j

    return a[maxIndex1]*a[maxIndex2]

n = int(input())
a = [int(x) for x in input().split()]
assert(len(a) == n)

print (maxProductFast(a))

'''while (True):
    #stress testing
    n = random.randint(2,1000)
    a = [random.randint(0, 100000) for x in range(n)]
    #n = random.randint(2,5)
    #a = [random.randint(0,100) for x in range(n)]
    print (a)

    result1 = maxProduct(a)
    result2 = maxProductFast(a)
    if result1 != result2:
        print (result1, result2)
        break
    else:
        print ("OK!")'''
