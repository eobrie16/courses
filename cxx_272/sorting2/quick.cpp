#include <iostream>
using namespace std;
#include <stdlib.h>
#include "d_timer.h" 

//Function to determine the partitions
// partitions the array and returns the middle index (subscript)
int partition(int array[], int top, int bottom)
{
  // Set x=array[top]
  // Swap all array entries >= x to the bottom
  // Swap all array entries < x to the top 
  // Return the first index of last entry in first section

  int midVal = array[top];
  while (bottom > top)
    {
      if (array[top+1] < midVal)
        {
          int temp = array[top];
          array[top] = array[top+1];
          array[top+1] = temp;
          top += 1;
        }
        else
          {
            int temp = array[bottom];
            array[bottom] = array[top+1];
            array[top+1] = temp;
            bottom -= 1;
          }
    }
  return top;
     
}
void quicksort(int array[], int top, int bottom)
{
  // top = subscript of beginning of vector being considered
  // bottom = subscript of end of vector being considered
  // this process uses recursion - the process of calling itself
  int middle;
  if (top < bottom)
    {
      middle = partition(array, top, bottom);
      quicksort(array, top, middle);   // sort top partition
      quicksort(array, middle+1, bottom);    // sort bottom partition
    }
  return;
}

int binSearch(int target, int array[], int top, int bottom, int & count)
{
  count += 1;
  if (top >= bottom)
    {
      if (target == array[top]) return top;
      else return -1;
    }
  int mid = (bottom + top)/2;
  if (target < array[mid])
    return binSearch(target, array, top, mid, count);
  else if (target > array[mid])
    return binSearch(target, array, mid+1, bottom, count);
  else return mid;

} 



void testbs(int target, int x[], int N)
{
  int count = 0;
  int ans=binSearch(target, x, 0, N-1, count);

  cout << "binSearch("<< target <<")=" << ans<< " count=" << count<< endl;
    
}

int main()
{
  int N;
  timer timeit;
  int *x;

  do
    {
      cout << "Enter N for quick sort:";
      cin >> N;
      if (N <= 0) break;

      x = new int[N] ;

      for (int i=0; i < N; i++)
        x[i] =rand() % N;
      
      timeit.start();
      quicksort(x,0,N-1);
      timeit.stop();
      cout << "Elapsed time=" << timeit.time()<<endl;

      char c='n';
      //cout << "Do you want to see the output?(y/n)";
      //cin >> c;
      if (c == 'y')
        {
          for (int i=0; i < N; i++)
            cout << x[i] << endl;
        }

      //testbs(300,x, N);   
      //testbs(5700,x, N);   
      //testbs(9000,x, N);   
      //testbs(2000,x, N);
      delete [] x;
    } while  (N > 0);
  
}