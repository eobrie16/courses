// *************************************************
// Distance.cpp
// *************************************************
#include <iostream>
using namespace std;
#include "Distance.h"  


// Normalize adjusts feet and inches if inches is >= 12;
void Distance::Normalize()
{
	feet += inches/12;
	inches = inches%12;
}

// utility function to return Distance in inches
int Distance::sizeInInches() const
{
	return (inches + feet*12);
}
    
// Constructors
Distance::Distance()
{
	inches = 0;
	feet = 0;
}

Distance::Distance(int initialValueInInches)
{
	feet = 0;
	inches = initialValueInInches;
	Normalize();
}


Distance::operator int()
{
	return sizeInInches();
}
    
// used for dist3 = dist1 + dist2;
Distance Distance::operator + (Distance & d2) const
{
	int totInches = sizeInInches() + d2.sizeInInches();
	Distance d3(totInches);
	return d3;
}

// used for dist1 += dist2;
void Distance::operator += (Distance & d2)
{
	inches += d2.inches;
	feet += d2.feet;
	Normalize();
}

// used for dist1 += 22;
void Distance::operator += (int value)
{
	inches += value;
	Normalize();
}

// used for dist1 = dist2
void Distance::operator = (Distance & d2)
{
	inches = d2.inches;
	feet = d2.feet;
}

// used for dist1 = 22
void Distance::operator = (int value)
{
	feet = 0;
	inches = value;
	Normalize();
}

// used for if (dist1 == dist2) ...
bool Distance::operator == (Distance & d2)
{
	if (sizeInInches() == d2.sizeInInches())
		return true;
	else
		return false;
}

// used for if (dist1 < dist2) ...
bool Distance::operator < (Distance & d2)
{
	if (sizeInInches() < d2.sizeInInches())
		return true;
	else
		return false;
}

// Constructor creates an Array of Distance classes the 
// size specified in size.  
ArrDistance::ArrDistance(int size)
{
	arrSize = size;
	arr = new Distance[arrSize];
}

// Make sure you free up your dynamic allocation
ArrDistance::~ArrDistance()
{
	delete [] arr;
}

// This operator should do a sanity check on the index
Distance & ArrDistance::operator [](int index)
{
	if (index >= arrSize)
	{
		cout << "array reference out of bounds: " << index << endl;
		cout << "Returning first array entry" << endl;
		index = 0;
	}
	return arr[index];
}
