// **********************************
//DateArr.h
// **********************************
#include <string.h>
#include <iostream>
using namespace std;

class Date
{
    int year;
    int month;
    int dayInMonth;

    int NumDaysInMonth(int m, int y);

    public:
        // Month should be 1, 2, ... 12
        // d should be 1, 2, ... 31 
        // Depending on the month and year, 
        // Throw exceptions if bad parameters come in.
        Date (int y=2000, int m=1, int d=1);
        Date operator + (int days);
        friend ostream& operator << (ostream& s, Date & d);
};


class DateArr {
   private:
      int size;
      Date *arr;  

   public:                            
        DateArr(int size=10);
        ~DateArr();
        Date & operator[] (int pos);
        void  resize(int newSize);
};
