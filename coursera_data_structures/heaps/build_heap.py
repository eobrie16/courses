# python3

class HeapBuilder:
  def __init__(self):
    self._swaps = []
    self._data = []

  def ReadData(self):
    n = int(input())
    self._data = [int(s) for s in input().split()]
    assert n == len(self._data)

  def WriteResponse(self):
    print(len(self._swaps))
    for swap in self._swaps:
      print(swap[0], swap[1])

  def GenerateSwapsSlow(self):
    # The following naive implementation just sorts
    # the given sequence using selection sort algorithm
    # and saves the resulting sequence of swaps.
    # This turns the given array into a heap,
    # but in the worst case gives a quadratic number of swaps.
    for i in range(len(self._data)):
      for j in range(i + 1, len(self._data)):
        if self._data[i] > self._data[j]:
          self._swaps.append((i, j))
          self._data[i], self._data[j] = self._data[j], self._data[i]

  def GenerateSwaps(self):
    self.size = len(self._data)
    for i in range((self.size-1)//2, -1, -1):
        self.SiftDown(i)

  def SiftUp(self, i):
      while i > 0 and self._data[self.Parent(i)] > self._data[i]:
          self._data[self.Parent(i)], self._data[i] = self._data[i], self._data[self.Parent(i)]
          self._swaps.append((i, self.Parent(i)))
          i = self.Parent(i)

  def SiftDown(self, i):
      min_index = i
      l = self.LeftChild(i)
      if l <= self.size-1 and self._data[l] < self._data[min_index]:
          min_index = l
      r = self.RightChild(i)
      if r <= self.size-1 and self._data[r] < self._data[min_index]:
          min_index = r
      if i != min_index:
          self._data[i], self._data[min_index] = self._data[min_index], self._data[i]
          self._swaps.append((i, min_index))
          self.SiftDown(min_index)

  def LeftChild(self, i):
    return (2*i)+1

  def RightChild(self, i):
    return (2*i)+2

  def Parent(self, i):
    return (i-1)//2


  def Solve(self):
    self.ReadData()
    #self._data = [5, 4, 3, 2, 1]
    #self._data = [1, 2, 3, 4, 5]
    self.GenerateSwaps()
    self.WriteResponse()

if __name__ == '__main__':
    heap_builder = HeapBuilder()
    heap_builder.Solve()
    #print (heap_builder._data)
