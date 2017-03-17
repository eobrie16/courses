# Uses python3
# The  rst line contains an integer 𝑛,
#  the next one contains a sequence of 𝑛 non-negative
#  integers 𝑎0, 𝑎1, . . . , 𝑎𝑛−1.
# Output 1 if the sequence contains an element
#  that appears strictly more than 𝑛/2 times, and 0 otherwise.
# Algorithmic Toolbox, Week3.2 (Divide and Conquer)

import sys

def partition(a, left, right):
    x = a[left]
    j = left
    k = left
    for i in range(left+1, right+1):
        if a[i] <= x:
            j += 1
            temp = a[i]
            a[i] = a[j]
            a[j] = temp
            if a[i] == x:
                k = i
            elif k > left:
                temp = a[j]
                a[j] = a[k]
                a[k] = temp
                k = j
    a[left] = a[j]
    a[j] = x
    return k, j

def get_majority_element(a, left, right):
    if left >= right:
        return
    m, n = partition(a, left, right)
    print (a)
    print (m,n)
    get_majority_element(a, left, m-1)
    get_majority_element(a, n+1, right)

if __name__ == '__main__':
    a = [2, 5, 3, 2, 1, 7, 8, 2]
    get_majority_element(a, 0, len(a)-1)
    print (a)

    '''input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    if get_majority_element(a, 0, n) != -1:
        print(1)
    else:
        print(0)'''
