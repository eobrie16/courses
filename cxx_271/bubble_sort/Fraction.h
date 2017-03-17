#include <iostream>
using namespace std;

class Fraction
{
private:
	int num, denom;
public:
	Fraction(int n=1, int d=1)
	{
		num = n;
		denom = d;
	}
	bool operator < (Fraction & f)
	{
		float f1 = (float)num / denom;
		float f2 = (float)f.num / f.denom;
		if (f1 < f2) return true;
		return false;
	}
	friend ostream& operator << (ostream& s, Fraction & f)
	{                                          
		s << f.num << '/' << f.denom;   
		return s;                                   
	}    

};
