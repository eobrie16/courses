// englret.cpp
// function returns value of type Distance
#include <iostream>
using namespace std;
#include "Cards.h"

int main()
   {
	Deck d;
	Hand north(13);
	Hand south(13);
	Hand east(13);
	Hand west(13);

	north.Deal(d);
	south.Deal(d);
	east.Deal(d);
	west.Deal(d);

	cout << "North:" << endl;
	north.show();

	cout <<endl << endl << "West:" << endl;
	west.show();

	
	cout <<endl << endl << "South:" << endl;
	south.show();

	
	
	cout <<endl << endl << "East:" << endl;
	east.show();



   return 0;
   }
