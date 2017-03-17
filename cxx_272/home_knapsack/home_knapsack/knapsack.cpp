#include <iostream>
using namespace std;
#include <time.h>
#include "knapsack.h"

knapsack::knapsack(int n,  int smallest, int largest, int knapsack_percentage, int seed )
{
  num_objects = n;
  if (seed == 0)
    srand(time(0));
  else
    srand(seed);
  
  item_weights= new int[n];
  solution = new bool[n];
  tmp_solution = new bool[n];
  int total = 0;
  for (int i=0; i < n; i++)
    {
      item_weights[i] = smallest + rand() % (largest-smallest);
      total += item_weights[i];
      cout << "item("<< i << ") = " << item_weights[i] << endl;
    }
  knapsack_weight = (total * knapsack_percentage)/100;
  cout << "Knapsack size = " << knapsack_weight << endl;    
}

void knapsack::printSolution()
{
  cout << "Solution size =" << solution_weight << endl;
  cout << "Items in solution: ";
  int check_weight=0;
  for (int i=0; i < num_objects; i++)
    {
      if (solution[i])
        {
          cout << " " << i;
          check_weight += item_weights[i];
        }
    }
  cout << endl;
  cout << " total checked weight =" << check_weight << endl;
}
knapsack::~knapsack()
{
  delete [] item_weights;
  delete [] solution;
  delete [] tmp_solution;
}


void knapsack::solve()
{
  solution_weight = -1;
  for (int i=0; i < num_objects; i++)
  {
     tmp_solution[i] = false;
  }
    
  solve(0, 0);

}


void knapsack::solve(int step, int curr_solution_weight)
{
	if (step == num_objects)
	{
		if ((curr_solution_weight > solution_weight) && (curr_solution_weight <= knapsack_weight))
		{
			solution_weight = curr_solution_weight;
			for (int i=0; i<num_objects; i++)
			{
				solution[i] = tmp_solution[i];
			}
		}
	}
	else
	{
		tmp_solution[step] = false;
		solve(step+1, curr_solution_weight);
		tmp_solution[step] = true;
		solve(step+1, (curr_solution_weight + item_weights[step]));
	}

}