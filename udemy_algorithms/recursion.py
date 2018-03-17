
def reverseString(mystr):
    newstr = list(mystr)
    i=0
    j=len(mystr)-1
    while i<=j:
        newstr[i], newstr[j] = newstr[j], newstr[i]
        i += 1
        j -= 1
    return ''.join(newstr)
    
def reverseStringRecursive(mystr):
    if len(mystr) == 1:
        return mystr
    a = mystr[0]
    return reverseStringRecursive(mystr[1:])+a
    
def find(a, value):
    return binarySearch(a, value, 0, len(a)-1)
    
def binarySearch(a, value, low, high):
    if low > high:
        return -1
    index = low + (high-low)//2
    if value==a[index]:
        return index
    elif value < a[index]:
        return binarySearch(a, value, low, index-1)
    else:
        return binarySearch(a, value, index+1, high)
    

a = [11, 22, 33, 44, 55, 66, 77, 88, 99, 110]
print (find(a, 0))