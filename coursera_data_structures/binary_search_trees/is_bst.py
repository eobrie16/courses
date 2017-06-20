#!/usr/bin/python3

import sys, threading

sys.setrecursionlimit(10**9) # max depth of recursion
threading.stack_size(2**30)  # new thread will get stack of such size

# tree[0] = key
# tree[1] = left index
# tree[2] = right index
def IsBinarySearchTree(tree):
  for i in range(len(tree)):
      value = tree[i][0]
      if tree[i][1] == -1:
          left = -sys.maxsize
      else:
          left = tree[tree[i][1]][0]
      if tree[i][2] == -1:
          right = sys.maxsize
      else:
          right = tree[tree[i][2]][0]
      print (value, left, right)
      if not (value > left and value < right):
          return False
  return True

def IsBinarySearchTree(tree, i, minval, maxval):
    if len(tree) == 0:
        return True
    value = tree[i][0]
    left_ret = right_ret = True
    if tree[i][1] != -1:
        left = tree[tree[i][1]][0]
        if left <= minval or left >= value:
            return False
        else:
            left_ret = IsBinarySearchTree(tree, tree[i][1], minval, min(value, maxval))
    if tree[i][2] != -1:
        right = tree[tree[i][2]][0]
        if right > maxval or right < value:
            return False
        else:
            if value > minval:
                minval = value - 1
            right_ret = IsBinarySearchTree(tree, tree[i][2], minval, maxval)
    return left_ret and right_ret

def test2():
  print('Running examples...')
  example11 = ["1:1", True, [2, 1, 2], [1, -1, -1], [3, -1, -1]]
  example12 = ["1:2", False,[1, 1, 2], [2, -1, -1], [3, -1, -1]]
  example13 = ["1:3", True]
  example14 = ["1:4", True, [1, -1, 1], [2, -1, 2], [3, -1, 3], [4, -1, 4], [5, -1, -1]]
  example15 = ["1:5", True, [4, 1, 2], [2, 3, 4], [6, 5, 6], [1, -1, -1], [3, -1, -1], [5, -1, -1], [7, -1, -1]]
  example16 = ["1:6", False,[4, 1, -1], [2, 2, 3], [1, -1, -1], [5, -1, -1]]
  # Hard Examples
  example21 = ["2:1", True, [2, 1, 2], [1, -1, -1], [3, -1, -1]]
  example22 = ["2:2", False, [1, 1, 2], [2, -1, -1], [3, -1, -1]]
  example23 = ["2:3", True, [2, 1, 2], [1, -1, -1], [2, -1, -1]]
  example24 = ["2:4", False, [2, 1, 2], [2, -1, -1], [3, -1, -1]]
  example25 = ["2:5", True]
  example26 = ["2:6", True, [2147483647, -1, -1]]
  example27 = ["2:7", True, [1, -1, 1], [2, -1, 2], [3, -1, 3], [4, -1, 4], [5, -1, -1]]
  example28 = ["2:8", True, [4, 1, 2], [2, 3, 4], [6, 5, 6], [1, -1, -1], [3, -1, -1], [5, -1, -1], [7, -1, -1]]
  examples = [example11, example12, example13, example14, example15, example16, example21, example22, example23, example24, example25, example26, example27, example28]
  passed = True
  for example in examples:
    name = example[:1][0]
    result = IsBinarySearchTree(example[2:], 0, -sys.maxsize, sys.maxsize)
    answer = example[1:2][0]
    if result != answer:
      print("Failed {}: {} for {}/{}".format(name, result, answer, example[2:]))
      passed = False
  if passed:
    print("All Examples Passed")


def main():
  nodes = int(sys.stdin.readline().strip())
  tree = []
  for i in range(nodes):
    tree.append(list(map(int, sys.stdin.readline().strip().split())))
  '''tree = []
  tree.append([4,1,2])
  tree.append([2,3,4])
  tree.append([6,5,6])
  tree.append([1,-1,-1])
  tree.append([3,-1,-1])
  tree.append([5,-1,-1])
  tree.append([7,-1,-1])
  tree.append([4,1,-1])
  tree.append([2,2,3])
  tree.append([1,-1,-1])
  tree.append([5,-1,-1])
  n = int(10e5)
  tree = [[n, i+1, -1] for i in range(n-1)]
  tree.append([n, -1, -1])'''
  #test2()

  if IsBinarySearchTree(tree, 0, -sys.maxsize, sys.maxsize):
    print("CORRECT")
  else:
    print("INCORRECT")

threading.Thread(target=main).start()
