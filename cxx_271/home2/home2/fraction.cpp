// Fraction.cpp  **********************************

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
#include "fraction.h"

Fraction Fraction::add(const Fraction & op) const
{
	//a/b + c/d = (a*d + b*c)/(b*d)
	Fraction ans;
	ans.num = (num*op.denom + denom*op.num);
	ans.denom = (denom*op.denom);
	ans.reduce();

	return ans;
}

Fraction Fraction::subtract(const Fraction & op) const
{
	//a/b - c/d = (a*d - b*c)/(b*d)
	Fraction ans;
	ans.num = (num*op.denom - denom*op.num);
	ans.denom = (denom*op.denom);
	ans.reduce();

	return ans;
}
Fraction Fraction::multiply(const Fraction & op) const 
{
	//a/b * c/d = (a*c)/ (b*d)
	Fraction ans;
	ans.num = (num*op.num);
	ans.denom = (denom*op.denom);
	ans.reduce();

	return ans;
}
Fraction Fraction::divide(const Fraction & op) const
{
	//a/b  /  c/d = (a*d)/ (b*c)
	Fraction ans;
	ans.num = (num*op.denom);
	ans.denom = (denom*op.num);
	ans.reduce();

	return ans;
}
  
void Fraction::display(const char * label) const
{
	cout << label << num << "/" << denom << endl;
}

void Fraction::readin(const char * label)
{
	char temp[10];
	char * index;
	cout << label;
	cin >> temp;
        index = strchr(temp, '/');
	if (index == NULL)
	{
		//wrong format so we assume a / b format
	        cout << "Assuming 'a / b' format";
		num = atoi(temp);
		cin >> temp;	//throwaway slash
		cin >> temp;
		denom = atoi(temp);
	}
	else
	{
		denom = atoi(index+1);
		*index = 0;
		num = atoi(temp);
	}

}

void Fraction::reduce()
{
	for (int i=2; i<=abs(num); i++)
	{
		while (denom%i==0 && num%i==0)
		{
			denom = denom/i;
			num = num/i;

			if (num==1)
				break;
		}
	}
}
