// **************************************
// main.cpp
// **************************************

#include <iostream> 
#include <fstream>
using namespace std;

#include "date.h"

int main()
{
    DateArr dates(3);
    
    Date d1(2006, 11, 11);
    Date d2(2005, 12, 4);
    Date d3(1999, 8, 29);

    dates[0] = d1;
    dates[1] = d2 + 23;
    dates[2] = d3 + 100;

    for (int i=0; i < 3; i++)
    {
        cout << "i=" << i << " value=" << dates[i] << endl;
    }

    dates.resize(5);  
    
    for (int i=0; i < 5; i++)
    {
        cout << "i=" << i << " resized value=" << dates[i] << endl;
    }

    // Try out some error cases
    try
    {
        Date derr1(1998, 4, 31);
    }
    catch (char * err)
    {
        cout << "Test1: error: " << err << endl;
    }
	try
    {
        Date derr3(2090, 4, 10);
    }
    catch (char * err)
    {
        cout << "Test3: error: " << err << endl;
    }
	try
    {
        Date derr4(1999, 11, 14);
    }
    catch (char * err)
    {
        cout << "Test4: error: " << err << endl;
    }

    try
    {
        Date derr1(2000, 2, 28);
        cout << "1900 should not be a leap year" << endl;
        Date derr2(1900, 2, 29);
    }
    catch (char * err)
    {
        cout << "Test2 error: " << err << endl;
    }

    return 0;
}
