#############
# Problem 1
############
'''Given an array a, perform a left rotation k places'''
def array_left_rotation(a, n, k):
    return a[k:]+a[:k]


'''n, k = map(int, input().strip().split(' '))
a = list(map(int, input().strip().split(' ')))
answer = array_left_rotation(a, n, k);
print(*answer, sep=' ')'''

#############
# Problem 2
############
import sys

""" Node is defined as"""
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def checkBST(root):
    if root is None:
        return True
    return checkVal(-sys.maxsize, sys.maxsize, root)

def checkVal(minval, maxval, root):
    if root is None:
        return True
    elif root.data <= minval or root.data >= maxval:
        return False
    else:
        return checkVal(minval, min(maxval, root.data), root.left)  \
            and checkVal(max(minval, root.data), maxval, root.right)


'''root = Node(6)
root.left = Node(4)
root.right = Node(8)
root.left.left = Node(2)
root.left.right = Node(7)
root.right.left = Node(10)
#root.right.right = Node(7)
print (checkBST(root))'''


#########################
# Problem 3 - hash tables
#########################

def ransom_note(magazine, ransom):
    magazine_words = {}
    for word in magazine:
        if word not in magazine_words:
            magazine_words[word] = 1
        else:
            magazine_words[word] += 1
    for word in ransom:
        if word in magazine_words and magazine_words[word] > 0:
            magazine_words[word] -= 1
        else:
            return False
    return True

#m, n = map(int, input().strip().split(' '))
#magazine = input().strip().split(' ')
#ransom = input().strip().split(' ')
'''magazine = 'give me one grand today night'.split()
ransom = 'give one grand today'.split()
answer = ransom_note(magazine, ransom)
if(answer):
    print("Yes")
else:
    print("No")'''

#########################
# Problem 3 - linked lists
#########################
"""
Detect a cycle in a linked list. Note that the head pointer may be 'None' if the list is empty.

A Node is defined as:
"""

class Node(object):
    def __init__(self, data = None, next_node = None):
        self.data = data
        self.next = next_node
        self.visited = 0


def has_cycle(head):
    if head == None:
        return False
    node = head
    visited = []
    while node.next is not None:
        if node in visited:
            return True
        visited.append(node)
        node = node.next
    return False

'''head = Node(5)
print (has_cycle(head))
node1 = Node(1)
node2 = Node(2)
node3 = Node(3)
node1.next = node2
node2.next = node3
node3.next = node2
head = node1
print (has_cycle(head))'''

#########################
# Problem 4 - sorting
#########################

from functools import cmp_to_key
class Player:
    def __init__(self, name, score):
        self.name = name
        self.score = score

    def __repr__(self):
        return name

    def comparator(a, b):
        if a.score == b.score:
            return a.name > b.name
        else:
            return a.score > b.score

'''n = int(input())
data = []
for i in range(n):
    name, score = input().split()
    score = int(score)
    player = Player(name, score)
    data.append(player)

data = sorted(data, key=cmp_to_key(Player.comparator))
for i in data:
    print(i.name, i.score)'''

#########################
# Problem 5 - queues
#########################

class MyQueue(object):
    def __init__(self):
        self.enqueue = []
        self.dequeue = []


    def peek(self):
        if len(self.dequeue) == 0:
            while len(self.enqueue) > 0:
                self.dequeue.append(self.enqueue.pop())
        return self.dequeue[-1]

    def pop(self):
        if len(self.dequeue) == 0:
            while len(self.enqueue) > 0:
                self.dequeue.append(self.enqueue.pop())
        return self.dequeue.pop()


    def put(self, value):
        self.enqueue.append(value)


'''queue = MyQueue()
t = int(input())
for line in range(t):
    values = map(int, input().split())
    values = list(values)
    if values[0] == 1:
        queue.put(values[1])
    elif values[0] == 2:
        queue.pop()
    else:
        print(queue.peek())'''

#########################
# Problem 5 - anagrams
#########################
import string

def number_needed(a, b):
    anagram = ''
    new_b = list(b)
    for letter in a:
        if letter in new_b:
            anagram += letter
            new_b.remove(letter)
    return len(a)-len(anagram) + len(b)-len(anagram)

'''a = input().strip()
b = input().strip()

print(number_needed(a, b))'''

###############################
# Problem 6 - balanced brackets
###############################


brackets = ['{', '[', '(', '}', ']', ')']

def is_matched(expression):
    bracket_stack = []
    for char in expression:
        if char in brackets[:3]:
            bracket_stack.append(char)
        elif char in brackets[3:]:
            if len(bracket_stack)==0 or brackets[brackets.index(bracket_stack.pop())+3] != char:
                return False
    if len(bracket_stack) > 0:
        return False
    else:
        return True


'''t = int(input().strip())
for a0 in range(t):
    expression = input().strip()
    if is_matched(expression) == True:
        print("YES")
    else:
        print("NO")'''


###############################
# Problem 7 - primality
###############################
import math

def is_prime(n):
    if n==1:
        return False
    elif n==2:
        return True
    elif n % 2 == 0:
        return False
    for i in range(3,int(math.sqrt(n))+1,2):
        if n % i == 0:
            return False
    return True

'''p = int(input().strip())
for a0 in range(p):
    n = int(input().strip())
    if is_prime(n):
        print ("Prime")
    else:
        print ("Not prime")'''


###############################
# Problem 8 - bubble sort
###############################

def bubbleSort(a):
    totalSwaps = 0
    for i in range(len(a)):
        numberOfSwaps = 0
        for j in range(len(a)-1):
            if a[j] > a[j+1]:
                a[j], a[j+1] = a[j+1], a[j]
                numberOfSwaps += 1
        if numberOfSwaps == 0:
            break
        else:
            totalSwaps += numberOfSwaps
    return a, totalSwaps


'''n = int(input().strip())
a = list(map(int, input().strip().split(' ')))
a, swaps = bubbleSort(a)
print ("Array is sorted in %s swaps." % swaps)
print ("First element: ", a[0])
print ("Last element: ", a[-1])'''


###############################
# Problem 8 - fibonacci
###############################


def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)

'''n = int(input())
print(fibonacci(n))'''

###############################
# Problem 9 - merge sort
###############################



def count_inversions(a):
    return merge_sort(a)[0]

def merge_sort(a):
    list_len = len(a)
    if list_len <= 1:
        return 0, a

    i_left, left = merge_sort(a[:list_len//2])
    i_right, right = merge_sort(a[list_len//2:])

    i_merge, a = merge(left, right)
    return (i_left + i_right + i_merge), a

def merge(left, right):
    merged = []
    inversions = 0
    i = j = 0
    while i<len(left) and j<len(right):
        if left[i] <= right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1
            inversions += 1
    if i<len(left):
        merged.extend(left[i:])
    elif j<len(right):
        merged.extend(right[j:])
    return inversions, merged


'''t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    arr = list(map(int, input().strip().split(' ')))
    print(count_inversions(arr))'''


def quicksort(a, low, high):
    if low >= high:
        return
    pivot = partition2(a, low, high)
    quicksort(a, low, pivot-1)
    quicksort(a, pivot+1, high)

def partition2(a, l, r):
    x = a[l]
    j = l
    for i in range(l + 1, r + 1):
        if a[i] <= x:
            j += 1
            a[i], a[j] = a[j], a[i]
    a[l], a[j] = a[j], a[l]
    return j

def partition(a, low, high):
    pivot = (high-low)//2
    a[pivot], a[low] = a[low], a[pivot]
    i = low+1
    j = high
    while i<j:
        while a[i] <= a[low] and i<j:
            i += 1
        while a[j] > a[low]:
            j -= 1
        if i < j:
            a[i], a[j] = a[j], a[i]
    a[low], a[j] = a[j], a[low]
    return j


'''a = [4, 2, 5, 6, 1]
print (a)
quicksort(a, 0, len(a)-1)
print (a)'''

################################
# Problem 10 - Davis' staircase
################################

ways = {}
def staircase(n):
    if n==1:
        return 1
    if n==2:
        return 2
    if n==3:
        return 4
    if n not in ways:
        count = staircase(n-1) + staircase(n-2) + staircase(n-3)
        ways[n] = count
    return ways[n]

'''t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print (staircase(n))'''


################################
# Problem 11 - lonely integer
#          (cheated on this one)
################################

import sys

def lonely_integer(a):
    value = 0
    for i in a:
        value ^= i
    return value


'''n = int(input().strip())
a = [int(a_temp) for a_temp in input().strip().split(' ')]
print(lonely_integer(a))'''

################################
# Problem 12 - comparator
################################

from functools import cmp_to_key
class Player:
    def __init__(self, name, score):
        self.name = name
        self.score = score

    def __repr__(self):
        return "Player(%s, %s)" % (self.name, self.score)

    def comparator(a, b):
        if a.score == b.score:
            if a.name < b.name:
                return -1
            elif a.name == b.name:
                return 0
            else:
                return 1
        else:
            if a.score < b.score:
                return 1
            else:
                return -1

'''n = int(input())
data = []
for i in range(n):
    name, score = input().split()
    score = int(score)
    player = Player(name, score)
    data.append(player)

data = sorted(data, key=cmp_to_key(Player.comparator))
for i in data:
    print(i.name, i.score)'''


################################
# Problem 12 - ice cream parlor
################################

def binary_search(arr, num):
    low = 0
    high = len(arr)-1
    while low < high:
        index = (high-low)//2
        value = arr[index]
        if num == value:
            return True
        elif num < value:
            high = index
        elif num > value:
            low = index
    return False

def ice_cream_parlor2(money, costs):
    sorted_costs = sorted(costs)
    for i in range(len(costs)):
        value = costs[i]
        if binary_search(sorted_costs[i:], money-value):
            cost1 = i
            cost2 = costs.index(money-value, i+1)
            return cost1+1, cost2+1

def ice_cream_parlor(money, costs):
    cost_dict = {}
    for i, x in enumerate(costs):
        if money - x in cost_dict:
            return cost_dict[money-x]+1, i+1
        else:
            cost_dict[x] = i


'''t = int(input().strip())
for a0 in range(t):
    m = int(input().strip())
    n = int(input().strip())
    a = list(map(int, input().strip().split(' ')))
    cost1, cost2 = ice_cream_parlor(m, a)
    print (cost1, cost2)'''

#################################
# Problem 13 - depth first search
#################################

def in_range(grid, i, j, row, col):
    if i==row and j==col:
        return False
    elif i<0 or j<0:
        return False
    elif i>= len(grid):
        return False
    elif j>= len(grid[row]):
        return False
    else:
        return True

def getRegion(grid, row, col):
    count = 0
    # reset so as to not recount
    grid[row][col] = 0
    for i in range(row-1, row+2):
        for j in range(col-1, col+2):
            if not in_range(grid, i, j, row, col) or grid[i][j] == 0:
                continue
            count += getRegion(grid, i, j)
    return 1 + count

def getBiggestRegion(grid):
    maxRegion = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                maxRegion = max(maxRegion, getRegion(grid, i, j))
    return maxRegion


'''n = int(input().strip())
m = int(input().strip())
grid = []
for grid_i in range(n):
    grid_t = list(map(int, input().strip().split(' ')))
    grid.append(grid_t)
#print(getBiggestRegion(grid))'''

#################################
# Problem 14 - Tries
#################################

import sys
sys.setrecursionlimit(100005)
class TrieNode:
    def __init__(self, char='', root=False):
        self.children = []
        self.isLeaf = False
        self.isRoot = root
        self.count = 0
        if not root:
            self.value = char

    def get_child(self, char):
        for child in self.children:
            if child.value == char:
                return child
        return None

def insertKey(node, word):
    node.count += 1
    next_node = node.get_child(word[0])
    if next_node is None:
        next_node = TrieNode(word[0])
        node.children.append(next_node)
    if len(word) == 1:
        next_node.count += 1
        next_node.isLeaf = True
        return
    insertKey(next_node, word[1:])

def findPartialKey(node, partial):
    for char in partial:
        next_node = node.get_child(char)
        if next_node is not None:
            node = next_node
        else:
            return 0
    return node.count

'''root = TrieNode(True)
n = int(input().strip())
for a0 in range(n):
    op, contact = input().strip().split(' ')
    if op == 'add':
        insertKey(root, contact)
    elif op == 'find':
        print(findPartialKey(root, contact))'''

######################################
# Problem 15 - use heap to find median
######################################

class Heap:
    def __init__(self):
        self.heapList = []
        
    def peek(self):
        return self.heapList[0] if self.size() else sys.maxsize
        
    def __repr__(self):
        return str(self.heapList)
        
    def size(self):
        return len(self.heapList)

    def parent(self, index):
        return (index-1)//2 if (index-1)//2 >= 0 else None

    def leftChild(self, index):
        return 2*index + 1 if 2*index + 1 < self.size() else None

    def rightChild(self, index):
        return 2*index + 2 if 2*index + 2 < self.size() else None

    def swap(self, index1, index2):
        self.heapList[index1], self.heapList[index2] = self.heapList[index2], self.heapList[index1]

class MaxHeap(Heap):
    def __init__(self):
        super().__init__()
        
    def peek(self):
        return self.heapList[0] if len(self.heapList) else -sys.maxsize
        
    def maxChildIndex(self, index):
        if self.leftChild(index) is None:
            return self.rightChild(index)
        elif self.rightChild(index) is None:
            return self.leftChild(index)
        elif self.heapList[self.leftChild(index)] > self.heapList[self.rightChild(index)]:
            return self.leftChild(index)
        else:
            return self.rightChild(index)
        
    def insert(self, value):
        self.heapList.append(value)
        i = len(self.heapList) - 1
        par_i = self.parent(i)
        while par_i is not None and self.heapList[i] > self.heapList[par_i]:
            self.swap(i, par_i)
            i = par_i
            par_i = self.parent(i)
            
    def remove(self):
        self.swap(0, len(self.heapList) - 1)
        value = self.heapList.pop()
        i = 0
        i_child = self.maxChildIndex(i)
        if i_child is None or i < 0 or i_child >= len(self.heapList):
            return value
        while i_child is not None and self.heapList[i] < self.heapList[i_child]:
            self.swap(i, i_child)
            i = i_child
            i_child = self.maxChildIndex(i)
        return value
            
class MinHeap(Heap):
    def __init__(self):
        super().__init__()
        
    def minChildIndex(self, index):
        if self.leftChild(index) is None:
            return self.rightChild(index)
        elif self.rightChild(index) is None:
            return self.leftChild(index)
        elif self.heapList[self.leftChild(index)] < self.heapList[self.rightChild(index)]:
            return self.leftChild(index)
        else:
            return self.rightChild(index)
        
    def insert(self, value):
        self.heapList.append(value)
        i = len(self.heapList) - 1
        par_i = self.parent(i)
        while par_i is not None and self.heapList[i] < self.heapList[par_i]:
            self.swap(i, par_i)
            i = par_i
            par_i = self.parent(i)
            
    def remove(self):
        self.swap(0, len(self.heapList) - 1)
        value = self.heapList.pop()
        i = 0
        i_child = self.minChildIndex(i)
        if i_child is None or i < 0 or i_child >= len(self.heapList):
            return value
        while i_child is not None and self.heapList[i] > self.heapList[i_child]:
            self.swap(i, i_child)
            i = i_child
            i_child = self.minChildIndex(i)
        return value
            
class MedianHeap:
    def __init__(self):
        self.min_heap = MinHeap()
        self.max_heap = MaxHeap()
        
    def insert(self, value):
        #import pdb; pdb.set_trace()
        if self.max_heap.size() == 0:
            self.max_heap.insert(value)
        elif value > self.max_heap.peek():
            self.min_heap.insert(value)
        else:
            self.max_heap.insert(value)
        self.rebalance()
        
    def rebalance(self):
        # first check if we need to move nodes between heaps
        if abs(self.max_heap.size() - self.min_heap.size()) > 1:
            if self.max_heap.size()  > self.min_heap.size():
                self.min_heap.insert(self.max_heap.remove())
            elif self.min_heap.size() > self.max_heap.size():
                self.max_heap.insert(self.min_heap.remove())
        
            
    def get_median(self):
        if self.max_heap.size() == 0:
            return self.min_heap.peek()
        elif self.min_heap.size() == 0:
            return self.max_heap.peek()
        elif self.max_heap.size() == self.min_heap.size():
            return float((self.max_heap.peek() + self.min_heap.peek()) / 2)
        elif self.max_heap.size() > self.min_heap.size():
            return float(self.max_heap.peek())
        else:
            return float(self.min_heap.peek())
            

h = MedianHeap()
n = int(input().strip())
for a0 in range(n):
    val = int(input().strip())
    h.insert(val)
    print ("%.1f" % (h.get_median()))
