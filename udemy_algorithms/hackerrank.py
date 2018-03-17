
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
 
                
