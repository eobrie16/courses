#include <iostream>
using namespace std;

int main()
{
	const int NUM_PTRS = 10000;
	int * ptrs[NUM_PTRS];
	int MEM_TO_WASTE = 10*1024*1024;

	for (int i=0;;i++)
	{
		int index = i % NUM_PTRS;
		ptrs[index] = new int[MEM_TO_WASTE];
		cout << "Wasting piece: " << index << endl;

		// Go out and access all the memory we have allocated so far
		for (int j=0; j < index; j++)
		{
			int * p = ptrs[j];
			for (int k=0; k < MEM_TO_WASTE; k++)
				p[k] = k;
		}
	}
    return 0;    
} 
