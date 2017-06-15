# python3
import os
from sys import stdin

# Splay tree implementation

# Vertex of a splay tree
class Vertex:
  def __init__(self, key, sum, left, right, parent):
    (self.key, self.sum, self.left, self.right, self.parent) = (key, sum, left, right, parent)

def update(v):
  if v == None:
    return
  v.sum = v.key + (v.left.sum if v.left != None else 0) + (v.right.sum if v.right != None else 0)
  if v.left != None:
    v.left.parent = v
  if v.right != None:
    v.right.parent = v

def smallRotation(v):
  parent = v.parent
  if parent == None:
    return
  grandparent = v.parent.parent
  if parent.left == v:
    m = v.right
    v.right = parent
    parent.left = m
  else:
    m = v.left
    v.left = parent
    parent.right = m
  update(parent)
  update(v)
  v.parent = grandparent
  if grandparent != None:
    if grandparent.left == parent:
      grandparent.left = v
    else:
      grandparent.right = v

def bigRotation(v):
  if v.parent.left == v and v.parent.parent.left == v.parent:
    # Zig-zig
    smallRotation(v.parent)
    smallRotation(v)
  elif v.parent.right == v and v.parent.parent.right == v.parent:
    # Zig-zig
    smallRotation(v.parent)
    smallRotation(v)
  else:
    # Zig-zag
    smallRotation(v)
    smallRotation(v)

# Makes splay of the given vertex and makes
# it the new root.
def splay(v):
  if v == None:
    return None
  while v.parent != None:
    if v.parent.parent == None:
      smallRotation(v)
      break
    bigRotation(v)
  return v

# Searches for the given key in the tree with the given root
# and calls splay for the deepest visited node after that.
# Returns pair of the result and the new root.
# If found, result is a pointer to the node with the given key.
# Otherwise, result is a pointer to the node with the smallest
# bigger key (next value in the order).
# If the key is bigger than all keys in the tree,
# then result is None.
def find(root, key):
  v = root
  last = root
  next = None
  while v != None:
    if v.key >= key and (next == None or v.key < next.key):
      next = v
    last = v
    if v.key == key:
      break
    if v.key < key:
      v = v.right
    else:
      v = v.left
  root = splay(last)
  return (next, root)

def split(root, key):
  (result, root) = find(root, key)
  if result == None:
    return (root, None)
  right = splay(result)
  left = right.left
  right.left = None
  if left != None:
    left.parent = None
  update(left)
  update(right)
  return (left, right)


def merge(left, right):
  if left == None:
    return right
  if right == None:
    return left
  while right.left != None:
    right = right.left
  right = splay(right)
  right.left = left
  update(right)
  return right


# Code that uses splay tree to solve the problem

root = None

def insert(x):
  global root
  (left, right) = split(root, x)
  new_vertex = None
  if right == None or right.key != x:
    new_vertex = Vertex(x, x, None, None, None)
  root = merge(merge(left, new_vertex), right)

def erase(x):
  global root
  (left, right) = split(root, x)
  if right is not None and right.key == x:
      (r1, r2) = split(right, x+1)
      (r0, r)  = split(r1, x)
      right = merge(r0, r2)
  root = merge(left, right)

def search(x):
  global root
  (next, root) = find(root, x)
  if next is None:
      return False
  elif next.key == x:
      return True
  else:
      return False

def sum(fr, to):
  global root
  (left, middle) = split(root, fr)
  (middle, right) = split(middle, to + 1)
  ans = 0
  if middle is not None:
      ans += middle.sum
  root = merge(merge(left, middle), right)
  return ans

def printInOrder(newroot, treelist):
    if newroot:
        if newroot.left:
            treelist = printInOrder(newroot.left, treelist)
        treelist.append(newroot.key)
        if newroot.right:
            treelist = printInOrder(newroot.right, treelist)
    return treelist

def printNodes():
    global root
    return printInOrder(root, [])

# naive solution for sum
def mysum(theset, fr, to):
    thesum = 0
    for num in theset:
        if num >= fr and num <= to:
            thesum += num
    return thesum

MODULO = 1000000001
n = int(stdin.readline())
last_sum_result = 0
lines = '''? 1
+ 1
? 1
+ 2
s 1 2
+ 1000000000
? 1000000000
- 1000000000
? 1000000000
s 999999999 1000000000
- 2
? 2
- 0
+ 9
s 0 9'''.split('\n')
lines = '''5
? 0
+ 0
? 0
- 0
? 0'''.split('\n')

for i in range(n):
    line = stdin.readline().split()
    '''for infile in os.listdir('tests'):
    if infile.find('.a') > -1:
        continue
    print (infile)
    #infile = os.path.join('tests', '83')
    lines = open(os.path.join('tests',infile)).readlines()
    #ansfile = os.path.join('tests', '83.a')
    anslines = open(os.path.join('tests',infile+'.a')).readlines()
    a = 0
    myset = set()
    for i, line in enumerate(lines):'''
    if (1):
      #line = line.split()
      if line[0] == '+':
        x = int(line[1])
        value = (x + last_sum_result) % MODULO
        insert(value)
        #myset.add(value)
      elif line[0] == '-':
        x = int(line[1])
        value = (x + last_sum_result) % MODULO
        erase(value)
        #if value in myset:
        #    myset.remove(value)
      elif line[0] == '?':
        x = int(line[1])
        res = ('Found' if search((x + last_sum_result) % MODULO) else 'Not found')
        #res1 = ('Found' if ((x + last_sum_result) % MODULO) in myset else 'Not found')
        #ans = anslines[a]
        #a += 1
        #if res.strip() != ans.strip():
        #    print ("WRONG ANSWER! ", res, res1)
        #    break
        #else:
        print (res)
        #print('Found' if search((x + last_sum_result) % MODULO) else 'Not found')
      elif line[0] == 's':
        l = int(line[1])
        r = int(line[2])
        res = sum((l + last_sum_result) % MODULO, (r + last_sum_result) % MODULO)
        #res1 = mysum(myset, (l + last_sum_result) % MODULO, (r + last_sum_result) % MODULO)
        #ans = int(anslines[a])
        #a += 1
        #if res != ans:
        #    print ("WRONG ANSWER! ", res, res1)
        #    break
        #else:
        print(res)
        last_sum_result = res % MODULO
