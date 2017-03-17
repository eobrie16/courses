# Uses python3
# Computes least common multiple of two integers
# Algorithmic toolbox Week2.4

import sys

def lcm_naive(a, b):
    for l in range(1, a*b + 1):
        if l % a == 0 and l % b == 0:
            return l
    return a*b

def gcd(a, b):
    c = max(a,b) % min(a,b)
    if c==0:
        return min(a,b)
    while c != 0:
        a = min(a, b)
        b = c
        c = a % b
    return b

def lcm(a, b):
    return int(a*b//gcd(a,b))

if __name__ == '__main__':
    input = sys.stdin.readline()
    a, b = map(int, input.split())
    #print(lcm_naive(a, b))
    print (lcm(a,b))
