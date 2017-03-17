# Uses python3
# Basic fibonacci numbers
# Algorithmic Toolbox, Week2.1

def calc_fib(n):
    if (n <= 1):
        return n

    return calc_fib(n - 1) + calc_fib(n - 2)

def calc_fib_faster(n):
    if n<2:
        return n
    fib = [0,1]
    for i in range(2,n+1):
        fib.append(fib[i-2]+fib[i-1])
    return fib[n]

n = int(input())
print(calc_fib_faster(n))
