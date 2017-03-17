#include <iostream>
#include <fstream>
using namespace std;
#include <string>
#include <list>
#include "fraction.h"

template <typename T>
void dump(list<T> lst)
{
	list<T>::iterator iter = lst.begin();
	while (iter != lst.end())
	{
		cout << *iter << " ";
		iter++;
	}
	cout << endl;
}
template <typename T>
typename list<T>::iterator find(list<T> & lst, T target)
{
	typename list<T>::iterator iter = lst.begin();
	while (iter != lst.end())
	{
		if (*iter == target) return iter;
		iter++;
	}
	return iter;
}
template <typename T>
void insertOrder(list<T> & lst, T item)
{
	list<T>::iterator iter = lst.begin();
	while (iter != lst.end())
	{
		if (*iter > item) break;
		iter++;
	}
	lst.insert(iter, item);
}
template <typename T>
void splice(list<T>& dest, typename list<T>::iterator pos,
				 list<T>& source)
{
	list<T>::iterator srcIter = source.begin();
	while (srcIter != source.end())
	{
		dest.insert(pos, *srcIter);
		srcIter++;
	}
}

int main()
{
	Fraction f_arr[] = {Fraction(1,2), Fraction(1,4), Fraction(2,3), Fraction(4,5), Fraction(10,5)};
	for (int i=0; i<5; i++)
		cout << f_arr[i] << endl;

	int farrSize = sizeof(f_arr)/sizeof(Fraction);
	list<Fraction> lst_fract(f_arr, f_arr+farrSize);
	dump(lst_fract);

	Fraction ftest(2,3);
	list<Fraction>::iterator iterFound = find(lst_fract, ftest);

	if (iterFound == lst_fract.end())
		cout << "Fraction not found" << endl;
	else
	{
		cout << "Found: " << *iterFound << endl;
		dump(lst_fract);
	}

	Fraction itest(1,9);
	insertOrder(lst_fract, itest);
	dump(lst_fract);

	Fraction f_arr2[] = {Fraction(1,3), Fraction(2,5), Fraction(3,4), Fraction(5,6)};

	int farrSize2 = sizeof(f_arr2)/sizeof(Fraction);
	list<Fraction> lst_fract2(f_arr2, f_arr2+farrSize2);
	dump(lst_fract2);

	list<Fraction>::iterator iter = lst_fract2.begin();
	iter++;
	iter++;
	splice(lst_fract2, iter, lst_fract);
	dump(lst_fract);
	dump(lst_fract2);

	/*string arr[] = {"alpha", "gamma", "beta", "gamma" , "sigma"};
	int arrSize = sizeof(arr)/ sizeof(string);
	list<string> lstarr(arr, arr+arrSize);

	string str="beta";
	list<string>::iterator iterFound = find(lstarr, str);

	if (iterFound == lstarr.end())
		cout << "string not found" << endl;
	else
	{
		cout << "found " << *iterFound << endl;
		dump(lstarr);
	}

	string str2 = "zeta";
	insertOrder(lstarr, str2);
	dump(lstarr);

	string arr2[]  = {"abc", "def", "ghi", "jkl", "mno"};
	int arrSize2 = sizeof(arr2)/sizeof(string);
	list<string> lstarr2(arr2, arr2+arrSize2);
	dump(lstarr2);

	list<string>::iterator iter = lstarr2.begin();
	iter++;
	iter++;
	splice(lstarr2, iter, lstarr);
	dump(lstarr);
	dump(lstarr2);*/



}