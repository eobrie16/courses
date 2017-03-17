#include <set>
#include <iostream>
using namespace std;

template <typename T>
bool subset (const set<T>& lhs, set<T>& rhs)
{
	set<T>::const_iterator lhsIter = lhs.begin(), rhsIter = rhs.begin();

	int size = lhs.size();
	for (int i=0; i<size; i++)
	{
		if (rhs.count(*lhsIter) == 0) return false;
		lhsIter++;
	}

	return true;
}

void main()
{
	int a [] = {1, 3, 4, 9, 11, 34, 3, 7};
	int b [] = {3, 4, 9};
	int c [] = {1, 5, 9};

	int size = sizeof(a)/sizeof(int);
	set<int> setA(a, a+size);
	cout << "Set A: ";
	for (int i=0; i<size; i++)
		cout << a[i] << " ";
	size = sizeof(b)/sizeof(int);
	set<int> setB(b, b+size);
	cout << endl << "Set B: ";
	for (int i=0; i<size; i++)
		cout << b[i] << " ";
	size = sizeof(c)/sizeof(int);
	set<int> setC(c, c+size);
	cout << endl << "Set C: ";
	for (int i=0; i<size; i++)
		cout << c[i] << " ";
	cout << endl;
	cout << endl;

	if (subset(setB, setA))
		cout << "Set B is a subset of set A" << endl;
	else
		cout << "Set B is NOT a subset of set A" << endl;

	if (subset(setC, setA))
		cout << "Set C is a subset of set A" << endl;
	else
		cout << "Set C is NOT a subset of set A" << endl;
	


}