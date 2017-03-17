# Uses python3
# The goal of this code problem is to implement an algorithm
#  for the fractional knapsack problem.
import sys

def get_optimal_value(capacity, weights, values):
    value = 0.
    val_density = []

    for i in range(len(values)):
        val_density.append((values[i]/weights[i],i))
    val_density.sort()

    while (capacity > 0.0 and len(val_density)):
        current = val_density.pop()[1]
        if capacity >= weights[current]:
            value += values[current]
            capacity -= weights[current]
        else:
            value += (capacity / weights[current]) * values[current]
            capacity = 0.0

    return value


if __name__ == "__main__":
    #data = list(map(int, sys.stdin.readlines().split()))
    #n, capacity = data[0:2]
    n, capacity = list(map(int, sys.stdin.readline().split()))
    #values = data[2:(2 * n + 2):2]
    values = []
    weights = []
    for i in range(n):
        data = list(map(int, sys.stdin.readline().split()))
        values.append(data[0])
        weights.append(data[1])
    #weights = data[3:(2 * n + 2):2]
    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.10f}".format(opt_value))
