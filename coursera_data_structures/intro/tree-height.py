# python3
'''
You are given a description of a rooted tree.
Your task is to compute and output its height.
Data Structures, week1.2
'''

import sys, threading
sys.setrecursionlimit(10**7) # max depth of recursion
from collections import deque

class Node:
    """
    Class for storing nodes
    Node consists of key, and a list of children nodes
    """
    def __init__(self, key):
        self.key = key
        self.children = []

    def addChild(self, child):
        """Creates a child node"""
        self.children.append(child)

class TreeHeight:
        """Class to determine height of a given tree"""
        def read(self):
                """
                Reads inputs from stdin
                """
                self.n = int(sys.stdin.readline())
                self.parent = list(map(int, sys.stdin.readline().split()))
                self.root = None

        def count_levels(self, root):
            """Naive implementation to count levels of tree"""
            maxlevels = 1
            for child in root.children:
                maxlevels = max(1 + self.count_levels(child), maxlevels)
            return maxlevels

        def count_levels_nore(self, root):
            """Non-recursive method to count levels of tree
               Returns levels
            """
            d = deque()
            d.append((1,root))
            maxlevels = 1
            while len(d):
                parent = d.pop()
                for child in parent[1].children:
                    d.appendleft((parent[0]+1, child))
                maxlevels = max(maxlevels, parent[0])
            return maxlevels

        def compute_height_fast(self):
            """Computes height of the tree, starting from the given root
               Prints result to stdout
            """
            for i, x in enumerate(self.parent):
                if x.key == -1:
                    self.root = x
                else:
                    self.parent[x.key].addChild(x)
            print (self.count_levels_nore(self.root))

def main():
  #import time; start = time.clock()
  tree = TreeHeight()
  tree.n = int(input().strip())
  tree.parent=list(map(Node,map(int, input().split())))
  #print(tree.compute_height())
  tree.compute_height_fast()
  #print (time.clock()-start)

main()
