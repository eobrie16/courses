#include <iostream>
using namespace std;
#include <stdlib.h>
#include "d_timer.h"
#include "rand_string.h"

template <class T>
void bubbleSort(T x[], int N)
{
      int i, j, flag = 1;    // set flag to 1 to start first pass
      T temp;             // holding variable
      //int numLength = num.length( );
      for(i = 1; (i <= N) && flag; i++)
     {
          flag = 0;
          for (j=0; j < (N -1); j++)
         {
               if (x[j+1] > x[j])      // ascending order simply changes to <
              {
                    temp = x[j];             // swap elements
                    x[j] = x[j+1];
                    x[j+1] = temp;
                    flag = 1;               // indicates that a swap occurred.
               }
          }
     }
     return;   //arrays are passed to functions by address; nothing is returned
}

//Function to determine the partitions
// partitions the array and returns the middle index (subscript)
template <class T>
int partition(T array[], int top, int bottom)
{
  // Set x=array[top]
  // Swap all array entries >= x to the bottom
  // Swap all array entries < x to the top 
  // Return the first index of last entry in first section

  T midVal = array[top];
  while (bottom > top)
    {
      if (array[top+1] < midVal)
        {
          T temp = array[top];
          array[top] = array[top+1];
          array[top+1] = temp;
          top += 1;
        }
        else
          {
            T temp = array[bottom];
            array[bottom] = array[top+1];
            array[top+1] = temp;
            bottom -= 1;
          }
    }
  return top;
     
}

template <class T>
void quicksort(T array[], int top, int bottom)
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


int main()
{
  int N;
  timer timeit;
  string *x;

  do
    {
      cout << "Enter N for bubble sort:";
      cin >> N;
      if (N <= 0) break;

      x = new string[N] ;
	  RandStrings r(10);

      for (int i=0; i < N; i++)
        x[i] = r.getRandString(8);
     
      timeit.start();
      //bubbleSort(x,N);
      quicksort(x,0,N-1);
      timeit.stop();
      cout << "Elapsed time=" << timeit.time()<<endl;


      char c='n';
      cout << "Do you want to see the output?(y/n)";
      cin >> c;
      if (c == 'y')
        {
          for (int i=0; i < N; i++)
            cout << x[i] << endl;
        }

      delete [] x;
    } while  (N > 0);
 
}