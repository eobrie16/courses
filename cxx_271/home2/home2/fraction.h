// Fraction.h  **********************************

#include <iostream>
using namespace std;
#include <stdlib.h>

class Fraction
{
  int num;
  int denom;
public:
  Fraction(): num(1), denom(1)
  {}
  
  Fraction(int n, int d): num(n), denom(d)
  {}

  Fraction add(const Fraction & op) const;  
  Fraction subtract(const Fraction & op) const;  
  Fraction multiply(const Fraction & op) const;  
  Fraction divide(const Fraction & op) const;
  
  void reduce();
  void display(const char * label) const;
  void readin(const char * label);
 
};
