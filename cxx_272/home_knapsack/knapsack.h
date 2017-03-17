#include <stdlib.h>

class knapsack
{
 public:
  knapsack(int n, int smallest=360, int largest=400, 
       int knapsack_percentage=77, int seed = 0);
  ~knapsack();
  void solve();
  void printSolution();

 private: 
  void solve(int step, int curr_solution_weight);
 
  int num_objects;
  int knapsack_weight;
  int * item_weights;
  int solution_weight;
  bool * solution;
  bool * tmp_solution;
};
