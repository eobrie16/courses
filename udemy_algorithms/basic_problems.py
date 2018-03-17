
def is_palindrome(a):
    i=0
    j=len(a)-1
    while i < j:
        while not a[i].isalpha():
            i += 1
        while not a[j].isalpha():
            j -= 1
        if a[i].lower() != a[j].lower():
            return False
        i += 1
        j -= 1
    return True
        
def myrangefunc(num):
    i = 0
    while i<num:
        yield i
        i += 1
 
import copy       
def compute_neighbors(arr, row, col):
    count = 0
    for i in [r for r in [row-1, row, row+1] if r>=0 and r<len(arr)]:
        for j in [c for c in [col-1, col, col+1] if c>=0 and c<len(arr[0])]:
            if i == j:
                continue
            elif count == 3:
                return count
            elif arr[i][j] == 1:
                count += 1
    return count
        
def game_of_life(arr):
    newarr = copy.deepcopy(arr)
    for i in range(len(arr)):
        for j in range(len(arr[0])):   
            count = compute_neighbors(arr, i, j)
            print (count, i, j)
            if arr[i][j] == 1 and count != 2:
                newarr[i][j] = 0
            elif arr[i][j] == 0 and count == 2:
                newarr[i][j] = 1
    return newarr

'''arr = []
for i in range(3):
    arr.append([])
    for j in range(3):
        arr[i].append(i%2)
        
print(arr)
print (game_of_life(arr))'''


                
