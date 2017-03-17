#include <iostream> 
#include <fstream>
using namespace std;

#include "date.h"

int Date::NumDaysInMonth(int m, int y)
{
    // Assuming m = 1, 2, ... 12
    int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m != 2) return months[m-1];
    if ((y % 4 == 0) && (y % 100 != 0))
        return 29; // Leap year
    if (y % 400 == 0) return 29; // One very special case
    return 28;
}
 
Date::Date (int y, int m, int d)
{
	char * exception;
	if (y < 0)
		throw exception = "Invalid year!";
	year = y;

	if ((m<1) || (m>12))
		throw exception = "Month out of range (1-12)!";
	month = m;

	if ((d < 1) || (d > NumDaysInMonth(month, year)))
		throw exception = "Day out of range for month given!";
	dayInMonth = d;
}
Date Date::operator + (int days)
{
	int newDay;
	int newYear = year,  newMonth = month; 
	newDay = dayInMonth + days;
	while (newDay > NumDaysInMonth(newMonth, newYear))
	{
		newDay -= NumDaysInMonth(newMonth, newYear);
		newMonth++;
		if (newMonth > 12)
		{
			newMonth = 1;
			newYear++;
		}
	}
	return Date(newYear, newMonth, newDay);
}
ostream& operator << (ostream& s, Date & d)
{                          
   s << d.month << '/' << d.dayInMonth << '/' << d.year;   
   return s;                               
}   

DateArr::DateArr(int size)
{
	this->size = size;
	arr = new Date[size];
}

DateArr::~DateArr()
{
	delete [] arr;
}
Date & DateArr::operator[] (int pos)
{
	char * exception;
	if ((pos < 0) || (pos >= size))
		throw exception = "DateArr: index out of bounds";
	return arr[pos];
}
void  DateArr::resize(int newSize)
{
	Date * temp = new Date[newSize];
	int copySize = size;
	if (newSize < copySize) copySize = newSize;
	for (int i=0; i < copySize; i++)
		temp[i] = arr[i];
	delete [] arr;
	arr = temp;
	size = newSize;
}
