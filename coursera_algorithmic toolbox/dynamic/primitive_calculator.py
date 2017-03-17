# Uses python3
# Given an integer n, compute the minimum number of operations
#  needed to obtain the number n starting from the number 1
# Algorithmic toolbox, Week 4.1 (Dynamic Programming)

import sys

def optimal_sequence(n):
    sequence = [0]
    i=1
    while i <= n:
        if i == 1:
            sequence.append([i])
            i += 1
        else:
            a = b = c = sequence[i-1] + [i]
            if i%3 == 0:
                b = sequence[i//3] + [i]
            if i%2 == 0:
                c = sequence[i//2] + [i]
            minlen = min(min(len(a),len(b)),len(c))
            if minlen == len(c):
                sequence.append(c)
            elif minlen == len(b):
                sequence.append(b)
            else:
                sequence.append(a)
            i += 1

    return sequence[n]

input = sys.stdin.readline()
n = int(input)
#import time; start = time.clock()
sequence = list(optimal_sequence(n))
#print (time.clock()-start)
print(len(sequence) - 1)
for x in sequence:
    print(x, end=' ')
print()
