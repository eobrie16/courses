#include <iostream>
using namespace std;

#include "Pointers.h"

// Create an array of num random numbers 
int * createInts(int num)
{
	int * ptr = new int[num];
	for (int i=0; i<num; i++)
		ptr[i] = i;

	return ptr;
}

// Reverse the Integer Array
void  reverseIntArr(int intArr[], int num)
{
	int split = num/2;
	int temp;
	for (int i=0; i<split; i++)
	{
		temp = intArr[i];
		intArr[i] = intArr[num-i-1];
		intArr[num-i-1] = temp;
	}
}

// Print out the Integer Arry
void  printInArr(int intArr[], int num)
{
	for (int i=0; i<num; i++)
		cout << intArr[i] << "  "; 
	cout << endl;
	cout << endl;
}

// Free up the dyanmic memory allocated for the integer array
void  freeIntArr(int intArr[])
{
	delete [] intArr;
}

// Create an array of num doubles that contain Random values
double * createDbls(int num)
{
	double * ptr = new double[num];
	for (int i=0; i<num; i++)
		ptr[i] = i+0.1;

	return ptr;
}

// Reverse the array of doubles
void   reverseDblArr(double * dblArr, int num)
{
	int split = num/2;
	double temp;
	for (int i=0; i<split; i++)
	{
		temp = dblArr[i];
		dblArr[i] = dblArr[num-i-1];
		dblArr[num-i-1] = temp;
	}
}

// Print out the array of doubles
void   printDblArr(double * dblArr, int num)
{
	for (int i=0; i<num; i++)
		cout << dblArr[i] << "  ";
	cout << endl;
	cout << endl;
}

// Free up the memory allocated to the array of doubles
void   freeDblArr(double * dblArr)
{
	delete [] dblArr;
}

// Create an array of num Distance classes that contain random data
Distance *createDst(int num)
{
	Distance * ptr = new Distance[num];
	for (int i=0; i<num; i++)
	{
		ptr[i].feet = i;
		ptr[i].inches = i+0.5;
	}

	return ptr;
}


// Reverse the Distance Array
void   reverseDstArr(Distance dstArr[], int num)
{
	int split = num/2;
	Distance temp;
	for (int i=0; i<split; i++)
	{
		temp = dstArr[i];
		dstArr[i] = dstArr[num-i-1];
		dstArr[num-i-1] = temp;
	}
}

// Print out the Distance array using the output method in the 
// Distance class
void   printDstArr(Distance dstArr[], int num)
{
	cout << "(feet,inches): ";
	for (int i=0; i<num; i++)
		cout << dstArr[i].feet << "," << dstArr[i].inches << "  " ;
    cout << endl;
	cout << endl;

}

// Free up the memory allocated for the Distance array
void   free(Distance dstArr[])
{
	delete [] dstArr;
}
