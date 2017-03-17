# Uses python3
import sys

def get_change(m):
    tens = m // 10
    fives = (m - tens*10) // 5
    ones  = (m - tens*10 - fives*5)
    return tens + fives + ones

if __name__ == '__main__':
    m = int(sys.stdin.readline())
    print(get_change(m))
