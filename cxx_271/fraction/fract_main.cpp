#include <iostream>
using namespace std;
#include <stdlib.h>
#include "fraction.h"

int main()
  {
  // First some hard coded operations
    Fraction f1, f2, f3;
    char c;

    for (;;)
    {
        cout << "Enter operation : + - * / q  (q ==> quit): ";
        cin >> c;  cout << endl;
        if (c == 'q') exit(0);

	    cout << "Please enter fractions in 'a/b' format." << endl;
        f1.readin("Enter Fraction 1: "); cout << endl;
        f2.readin("Enter Fraction 2: "); cout << endl;

        f1.display("f1 = ");     
        f2.display("f2 = ");

        switch (c)
        {
        case '+':
            f3 = f1.add(f2);
            f3.display("f1+f2 = ");
            break;

        case '-':
            f3 = f1.subtract(f2);
            f3.display("f1-f2 = ");
            break;

        case '*':
            f3 = f1.multiply(f2);
            f3.display("f1*f2 = ");
            break;

        case '/':
            f3 = f1.divide(f2);
            f3.display("f1/f2 = ");
            break;

        default:
            cout << "Illegal command: " << c << endl;
            break;
        }
    }

  }