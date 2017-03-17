#include <iostream>
using namespace std;
#include "d_timer.h"
#include "knapsack.h" 


int main()
{
  int N;
  timer timeit;

  do
    {
      cout << "Enter in N for knapsack: ";
      cin >> N;
      if ( N > 0)
      {
        knapsack k(N);

        timeit.start();
        k.solve();
        timeit.stop();

        k.printSolution();
        cout <<"Elapsed time = " << timeit.time()<<endl;
      }
    }while (N > 0);
  return 0;
}
