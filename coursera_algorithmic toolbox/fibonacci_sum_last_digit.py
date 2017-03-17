# Uses python3
# Computes the last digit of the sum of the
#  fibonacci numbers n
# Algorithmic toolbox, Week 2.6
import sys

def fibonacci_sum_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum      = 1

    for _ in range(n - 1):
        previous, current = current, previous + current
        sum += current

    return sum % 10

def fibonacci_sum_better(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum      = 1

    for _ in range(n - 1):
        previous, current = current % 10, (previous + current) % 10
        sum = (sum + current) % 10

    return sum

if __name__ == '__main__':
    input = sys.stdin.readline()
    n = int(input)
    print(fibonacci_sum_better(n))
    #print(fibonacci_sum_naive(n))
