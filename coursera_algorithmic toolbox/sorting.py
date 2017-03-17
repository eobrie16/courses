# Quick sort
# Algorithmic toolbox Week3.3 (Divide and Conquer)

def partition(arr1, low, high):
    pivot = arr1[high]
    index = low
    for i in range(low, high):
        if arr1[i] < pivot:
            arr1[i], arr1[index] = arr1[index], arr1[i]
            index += 1
    arr1[high], arr1[index] = arr1[index], arr1[high]

    print (*arr1, sep=" ")
    return index

def quick_sort(arr1, low, high):
    if high <= low:
        return
    m = partition(arr1, low, high)
    quick_sort(arr1, low, m-1)
    quick_sort(arr1, m+1, high)



if __name__ == '__main__':
    n = input().split()
    arr1 = list(map(int, input().strip().split()))
    #arr1 = [1, 3, 9, 8, 2, 7, 5]
    quick_sort(arr1, 0, len(arr1)-1)
