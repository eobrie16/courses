#include <iostream>
using namespace std;

#include "Vector.h"
#include "bubbleSort.h"
#include "Fraction.h"

int main()
{
    int arr[]={99, 12, 50, 80, 1, 79, 20};

    cout << endl<< "bubbleSort ints" << endl;
    bubbleSort(arr, 7);
    for (int i=0; i < 7; i++)
        cout << arr[i]<< endl;

    double arr2[]={99.2, 12.9, 50.5, 80.7, 1.8, 79.0, 20.3};

    cout << endl<< "bubbleSort doubles" << endl;
    bubbleSort(arr2, 7);
    for (int i=0; i < 7; i++)
        cout << arr2[i]<< endl;

    
    Fraction arr3[]={Fraction(1,2), Fraction(1,3), Fraction(1,4),
                     Fraction(5,6), Fraction(3,4), Fraction(7,3),
                     Fraction(9,4)};

    cout << endl<< "bubbleSort Fractions" << endl;
    bubbleSort(arr3, 7);
    for (int i=0; i < 7; i++)
        cout << arr3[i]<< endl;

    cout << endl<< endl<< "Vector stuff"<< endl;
    Vector<Fraction> varr;

    varr.add(Fraction(12,14));
    varr.add(Fraction(5,7));
    varr.add(Fraction(2,5));    
    varr.add(Fraction(1,6));   
    varr.add(Fraction(3,7));

    bubbleSort(varr);

    for (int i=0; i < varr.size(); i++)
        cout << varr[i] << endl;
    return 0;
}