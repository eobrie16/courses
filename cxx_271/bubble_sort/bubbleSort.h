#include <iostream>
using namespace std;

template <typename T>
void bubbleSort(T intArr[], int arrLen)
{
	T temp;
	for (int i=0; i<arrLen-1; i++)
	{
		for (int j=0; j<arrLen-1-i; j++)
		{
			if (intArr[j+1] < intArr[j])
			{
				temp = intArr[j];
				intArr[j] = intArr[j+1];
				intArr[j+1] = temp;
			}
		}
	}
}

template <typename T>
void bubbleSort(Vector<T> & vec)
{
	T temp;
	for (int i=0; i<vec.size()-1; i++)
	{
		for (int j=0; j<vec.size()-1-i; j++)
		{
			if (vec[j+1] < vec[j])
			{
				temp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = temp;
			}
		}
	}
}
