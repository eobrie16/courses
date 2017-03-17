#include <vector>

// sort a vector using quicksort
template <typename T>
void quicksort(vector<T>& v, int first, int last);

//Function to determine the partitions
// partitions the array and returns the middle index (subscript)
template <typename T>
int partition(vector<T> & v, int top, int bottom)
{
  // Set x=array[top]
  // Swap all array entries >= x to the bottom
  // Swap all array entries < x to the top 
  // Return the first index of last entry in first section

  T midVal = v[top];
  while (bottom > top)
    {
      if (v[top+1] < midVal)
        {
          T temp = v[top];
          v[top] = v[top+1];
          v[top+1] = temp;
          top += 1;
        }
        else
          {
            T temp = v[bottom];
            v[bottom] = v[top+1];
            v[top+1] = temp;
            bottom -= 1;
          }
    }
  return top;
     
}


template <typename T>
void quicksort(vector<T>& v, int top, int bottom)
{
  // top = subscript of beginning of vector being considered
  // bottom = subscript of end of vector being considered
  // this process uses recursion - the process of calling itself
  int middle;
  if (top < bottom)
    {
      middle = partition(v, top, bottom);
      quicksort(v, top, middle);   // sort top partition
      quicksort(v, middle+1, bottom);    // sort bottom partition
    }
  return;
}

template <typename T>
int binSearch(T target, vector<T>& v, int top, int bottom, int & count)
{
  count += 1;
  if (top >= bottom)
    {
      if (target == v[top]) return top;
      else return -1;
    }
  int mid = (bottom + top)/2;
  if (target < v[mid])
    return binSearch(target, v, top, mid, count);
  else if (target > v[mid])
    return binSearch(target, v, mid+1, bottom, count);
  else return mid;

} 


