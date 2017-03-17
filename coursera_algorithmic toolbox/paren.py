# Find the maximum value of an arithmetic expression
#  by specifying the order of applying its arithmetic operations
#  using additional parentheses.
# Algorithmic toolbox, Week 4.4

import sys

def paren(a, n):
    count = 1
    while count > 0:
        n += 1
        if n == len(a):
            break
        if a[n] == '(':
            count += 1
        elif a[n] == ')':
            count -= 1
    return n

def sort_scores(scores, max_score):
    sorted_scores = []
    for i in range(max_score+1):
        while i in scores:
            sorted_scores.append(i)
            scores.remove(i)
    return sorted_scores

def mini_max(array1):
    minval = float('inf')
    maxval = -float('inf')
    sum1 = 0
    for val in array1:
        sum1 += val
        if val < minval:
            minval = val
        elif val > maxval:
            maxval = val
    return sum1-maxval, sum1-minval

def twoChar(s):
    char_dict = {}
    curLetters = []
    lockedLetters = []
    for i in range(len(s)):
        if s[i] not in char_dict:
            char_dict[s[i]] = [i]
        else:
            char_dict[s[i]].append(i)

    print (char_dict)
    new_list = list(char_dict.items())
    new_list.sort(key=cmp, reverse=True)
    print (new_list)
    for i in range(len(new_list)-1):
        a = new_list[i][1]
        b = new_list[i+1][1]
        print (a, b)
        valid = 1
        for j in range(len(b)):
            if len(a) == len(b) and j == len(b)-1:
                if not a[j] < b[j]:
                    valid = 0
                    break
            elif not (a[j] < b[j] and a[j+1] > b[j]):
                valid = 0
                break
        if valid == 1:
            return len(a) + len(b)

    #print ([x for x in reversed(list(char_dict.items()))])
    return 0

def cmp(x):
    return len(x[1])

def simplifyString(s):
    i = 0
    j = 1
    while j < len(s):
        if s[i] == s[j]:
            s = s.replace(s[i]+s[j], '')
            i = max(i-1,0)
            j = max(j-1,1)
        else:
            i += 1
            j += 1
    if len(s) == 0:
        return "Empty String"
    else:
        return s



if __name__ == '__main__':
    #s_len = int(input().strip())
    s = input().strip()
    #s = 'aa'
    t = simplifyString(s)
    print (t)
