# python3

import sys, threading
sys.setrecursionlimit(10**6) # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size
from collections import deque

class TreeOrders:
  def read(self):
    self.n = int(sys.stdin.readline())
    self.key = [0 for i in range(self.n)]
    self.left = [0 for i in range(self.n)]
    self.right = [0 for i in range(self.n)]
    for i in range(self.n):
      [a, b, c] = map(int, sys.stdin.readline().split())
      self.key[i] = a
      self.left[i] = b
      self.right[i] = c

  def printInOrder(self, index):
      if index==-1:
          return
      self.printInOrder(self.left[index])
      self.result.append(self.key[index])
      self.printInOrder(self.right[index])

  def printPreOrder(self, index):
      if index==-1:
          return
      self.result.append(self.key[index])
      self.printPreOrder(self.left[index])
      self.printPreOrder(self.right[index])

  def printPostOrder(self, index):
      if index==-1:
          return
      self.printPostOrder(self.left[index])
      self.printPostOrder(self.right[index])
      self.result.append(self.key[index])

  def printOrderLoop(self, index, order=1):
      q = []
      right = []
      curIndex = index
      done = 0
      while not done:
          if curIndex != -1:
              if order == 0:
                  self.result.append(self.key[curIndex])
              q.append(curIndex)
              curIndex = self.left[curIndex]
          else:
              if len(q) > 0:
                  curIndex = q.pop()
                  if order == 1:
                      self.result.append(self.key[curIndex])
                  curIndex = self.right[curIndex]
              else:
                  done = 1

  def printPostOrderLoop(self, index):
    stack1 = []
    stack2 = []
    stack1.append(index)
    while len(stack1) > 0:
        curIndex = stack1.pop()
        stack2.append(curIndex)
        if self.left[curIndex] != -1:
            stack1.append(self.left[curIndex])
        if self.right[curIndex] != -1:
            stack1.append(self.right[curIndex])

    while len(stack2) > 0:
        self.result.append(self.key[stack2.pop()])


  def inOrder(self):
    self.result = []
    #self.printInOrder(0)
    self.printOrderLoop(0, 1)
    return self.result

  def preOrder(self):
    self.result = []
    #self.printPreOrder(0)
    self.printOrderLoop(0, 0)
    return self.result

  def postOrder(self):
    self.result = []
    #self.printPostOrder(0)
    self.printPostOrderLoop(0)
    return self.result

def main():
    tree = TreeOrders()
    tree.read()
    #print (tree.key, tree.left, tree.right)
    '''tree.key = [10*i for i in range(10)]
    tree.left = [7,-1,-1,8,3,-1,1,5,-1,-1]
    tree.right = [2,-1,6,9,-1,-1,-1,4,-1,-1]
    tree.key = [i for i in range(int(10e5))]
    tree.left = [i+1 for i in range(int(10e5))]
    tree.left[-1] = -1
    tree.left[-2] = -1
    tree.right = [-1 for i in range(int(10e5))]'''
    print(" ".join(str(x) for x in tree.inOrder()))
    print(" ".join(str(x) for x in tree.preOrder()))
    print(" ".join(str(x) for x in tree.postOrder()))

threading.Thread(target=main).start()
