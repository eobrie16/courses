#include <iostream>
using namespace std;
#include "timer.h"

struct Parms 
{
	int arr[10000];
};

void func_by_value(Parms p)
{

}

void func_by_ref(Parms & p)
{

}

int main()
{
	Parms p;
	int N = 1000000;
	timer timeIt;


	timeIt.start();
	for (int i=0; i < N; i++)
		func_by_ref(p);
	timeIt.stop();
	cout << "Call by reference took: " << timeIt.time() << " seconds" << endl;

	timeIt.start();
	for (int i=0; i < N; i++)
		func_by_value(p);	
	timeIt.stop();
	cout << "Call by value took: " << timeIt.time() << " seconds" << endl;


	return 0;
}