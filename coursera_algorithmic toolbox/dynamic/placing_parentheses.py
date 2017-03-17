# Uses python3
# Find the maximum value of an arithmetic expression
#  by specifying the order of applying its arithmetic
#  operations using additional parentheses.
# Algorithmic toolbox Dynamic Programming #4
import sys

def evalt(a, b, op):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b
    else:
        assert False

def min_and_max(minArr,maxArr,i,j,ops):
    minval = sys.maxsize
    maxval = -sys.maxsize
    for k in range(i, j):
        a = evalt(maxArr[i][k],maxArr[k+1][j],ops[k])
        b = evalt(maxArr[i][k],minArr[k+1][j],ops[k])
        c = evalt(minArr[i][k],maxArr[k+1][j],ops[k])
        d = evalt(minArr[i][k],minArr[k+1][j],ops[k])
        minval = min(minval, a, b, c, d)
        maxval = max(maxval, a, b, c, d)
    return (minval, maxval)


def get_maximum_value(dataset):
    minArr = [[0 for j in range(0,len(dataset),2)] for i in range(0,len(dataset),2)]
    maxArr = [[0 for j in range(0,len(dataset),2)] for i in range(0,len(dataset),2)]
    ops = [dataset[op] for op in range(1,len(dataset),2)]
    for i in range(len(minArr)):
        minArr[i][i] = int(dataset[i*2])
        maxArr[i][i] = int(dataset[i*2])
    for s in range(len(minArr)-1):
        for i in range(len(minArr)-s-1):
            j = i+s+1
            minArr[i][j], maxArr[i][j] = min_and_max(minArr, maxArr, i, j, ops)
    return maxArr[0][len(maxArr)-1]


if __name__ == "__main__":
    #print (get_maximum_value("5-8+7*4+8+9"))
    print(get_maximum_value(input()))
