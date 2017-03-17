#include <iostream>
using namespace std;
#include "Distance.h"

Distance::Distance()
{
	inches = 0;
	feet = 0;
}
void Distance::Normalize()
{
	if (inches >= 12)
	{
		feet = feet + inches/12;
		inches = inches%12;
	}

}
Distance::Distance(float initialValueInFeet)
{
	feet = 0;
	inches = initialValueInFeet*12;
	Normalize();
}
Distance::Distance(int initialValueInInches)
{
	feet = 0;
	inches = initialValueInInches;
	Normalize();
}
void Distance::add( Distance & currTotal)
{
	inches += currTotal.inches;
	feet += currTotal.feet;
	Normalize();
}
void Distance::add(float distanceInFeet)
{
	inches += distanceInFeet*12;
	Normalize();
}
void Distance::add(int distanceInInches)
{
	inches += distanceInInches;
	Normalize();
}
void Distance::getdist()              //get length from user
         {
         cout << "\n   Enter feet: ";  cin >> feet;
         cout << "   Enter inches: ";  cin >> inches;
		 Normalize();
         }
void Distance::showdist() const       //display distance
         { cout << feet << "\'-" << inches << '\"'; }
