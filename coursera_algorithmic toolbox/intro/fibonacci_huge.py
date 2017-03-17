# Uses python3
import sys

def get_fibonacci_huge_naive(n, m):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % m
    
        
def get_fibonacci_num(n):
    if n <= 1:
        return n
    
    previous = 0
    current  = 1
    i = 1
        
    while i < n:
        previous, current = current, previous + current
        i += 1

    return current
    
def get_pisano_period(m):
    
    previous = 0
    previous_m = 0
    current  = 1
    current_m = 1
    count = 1
        
    while not (previous_m == 0 and current_m == 1 and count > 1):
        count += 1
        previous_m = current_m
        previous, current = current, previous + current
        current_m = current % m
        
    return count-1
        
    
def get_fibonacci_huge_better(n, m):
    
    if n <= 1:
        return n
        
    if m == 1:
        return 0

    pisano = get_pisano_period(m)
    #print ("pisano %s" % pisano)
    equiv = n % pisano
    #print ("equiv %s" % equiv)
    
    current = get_fibonacci_num(equiv)
    return current % m

if __name__ == '__main__':
    input = sys.stdin.readline()
    n, m = map(int, input.split())
    print(get_fibonacci_huge_better(n, m))
    #print(get_fibonacci_huge_naive(n, m))
