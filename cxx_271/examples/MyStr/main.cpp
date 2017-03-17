#include <iostream>
using namespace std;
#include "Mystr.h"

int main()
{
	Mystr z;
	Mystr x("01234");
	Mystr y("xyz");

	z = x + y;

	cout << z << endl;


   return 0;
 }  //end main()

