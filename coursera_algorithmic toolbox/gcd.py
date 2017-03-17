# Uses python3
# Computes greatest common divisor
# Algorithmic toolbox Week2.3

import sys

def gcd_naive(a, b):
    current_gcd = 1
    for d in range(2, min(a, b) + 1):
        if a % d == 0 and b % d == 0:
            if d > current_gcd:
                current_gcd = d

    return current_gcd

def gcd_better(a, b):
    c = max(a,b) % min(a,b)
    if c==0:
        return min(a,b)
    while c != 0:
        a = min(a, b)
        b = c
        c = a % b
    return b


if __name__ == "__main__":
    input = sys.stdin.readline()
    a, b = map(int, input.split())
    #print(gcd_naive(a, b))
    print(gcd_better(a, b))
