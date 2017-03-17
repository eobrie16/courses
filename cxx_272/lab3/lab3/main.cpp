#include <iostream>
using namespace std;
#include "time24.h"

//specifies clock time units
enum timeUnit {AM, PM};

class time12
{
private:
    time24 t;
    time24 convert12To24(int h, int m, timeUnit tunit);
       // build t from standard time

public:
    time12(int h=12, int m=0, timeUnit tunit = AM);
      // initialize time24 data member t
    void addTime(int m);
      // add m minutes to unpdate current time

    void readTime(istream& istr=cin);
    void writeTime(ostream& ostr=cout) const;

      // I/O member functions use format HH:MM:  AM (PM)



    friend bool operator== (const time12& lhs, const time12& rhs);

    friend bool operator<  (const time12& lhs, const time12& rhs);

    friend time12 operator+ (const time12& lhs, const time12& rhs);
            // form and return lhs + rhs
    friend time12 operator+ (const time12& lhs, int min);
            // form and return lhs + min
            // Precondition:  min must be >= 0
    friend time12 operator+ (int min, const time12& rhs);
            // form and return min + rhs
            // Precondition:  min must be >= 0
    friend time12 operator- (const time12& lhs, const time12& rhs);
            // form and return lhs - rhs
            // Precondition: lhs >= rhs. if not, throw a rangeError exception

    time12& operator+= (const time12& rhs);
            // current object = current object + rhs
            // Postcondition: the time increases by the value of rhs
    time12& operator+= (int min);
            // current object = current object + min
            // Precondition:  min must be >= 0
            // Postcondition: the time increases by min minutes

    friend istream& operator>> (istream& istr, time12& t);
            // input t in the format hh:mm. may omit the leading digit
            // if hours or minutes < 10
    friend ostream& operator<< (ostream& ostr, const time12& t);
            // output t in the format hh:mm. always include two digits
            // for the minute (e.g. 10:07). hours before 10 use 1 digit
            // and precede the hour by a blank (e.g. " 7:15")





};


time12::time12(int h, int m, timeUnit tunit )
 {
     t = convert12To24(h,m,tunit);
 }
void time12::addTime(int m)
 {
     t.addTime(m);
 }
time12& time12::operator+= (const time12& rhs)
{
    // current object = current object + rhs
    // Postcondition: the time increases by the value of rhs
    t += rhs.t;
    return *this;
}

time12& time12::operator+= (int min)
{
    t += min;
    return *this;
}


time12 operator+ (const time12& lhs, const time12& rhs)
{
    time12 ret =lhs;
    ret += rhs;
    return ret;
}
time12 operator+ (const time12& lhs, int min)
{
	time12 ret = lhs;
	ret += min;
	return ret;
}
time12 operator+ (int min, const time12& rhs)
{
	time12 ret = rhs;
	ret += min;
	return ret;
}
time12 operator- (const time12& lhs, const time12& rhs)
{
	time12 ret;
	ret.t = lhs.t - rhs.t;
	return ret;
	
	
}
bool operator== (const time12& lhs, const time12& rhs)
{
    return (lhs.t == rhs.t);
}
bool operator<  (const time12& lhs, const time12& rhs)
{
	return (lhs.t < rhs.t);
}

ostream& operator<< (ostream& ostr, const time12& t)
{
    t.writeTime(ostr);
    return ostr;
}
istream& operator>> (istream& istr, time12& t)
 {
     // input t in the format hh:mm. may omit the leading digit
     // if hours or minutes < 10
     t.readTime( istr);
     return istr;
 }
   

time24 time12::convert12To24(int h, int m, timeUnit tunit)
{
    if (tunit == AM)
    {
        if (h != 12)   return time24(h,m);
        else return time24(h+12, m);
    }
    else
    {
        if (h != 12)  return time24(h+12,m);
        else return time24(h, m);
    }
}

void time12::writeTime(ostream& ostr)const
{
    int hour = t.getHour();
    int minute = t.getMinute();
    timeUnit amPmIndicator = AM;
    if (hour > 12)
    {
        hour -= 12;
        amPmIndicator = PM;
    }
    if (hour == 12) amPmIndicator = PM;
    if (hour==0) hour = 12;   

    ostr.fill(' ');
    // output the hour
    ostr << setw(2) << hour << ':';

   // set fill char to '0' and output the minute
   ostr.fill('0');
   ostr << setw(2) << minute << "  ";
   if (amPmIndicator == AM) ostr << "AM";
   else ostr << "PM";
}

void time12::readTime(istream& istr)
{
   int hour=-1, minute=-1;
   char colonSeparator;
   string amPmIndicator;
   cout << "Enter hh:min AM/PM" <<endl;

   istr >> hour >> colonSeparator >> minute >> amPmIndicator;

   if ("AM" == amPmIndicator)
      t =  convert12To24(hour, minute, AM);
   else if ("PM" == amPmIndicator)
      t =  convert12To24(hour, minute, PM);
   else
       cout << "Bad readTime call, hour = " << hour << " minute=" <<
            minute << " AM/PM =" << amPmIndicator << endl;

  
}




// Nice to do lots of testing
int main()
{
   time12 myTime(0,0,AM), answer;
   myTime.addTime(770);
   cin >> answer;
   cout << "myTime=" << myTime<<endl;
   cout << "answer =" << answer <<endl;

   if (answer == myTime)
       cout << "The same" << endl;
   else
       cout << "Different" << endl;

   time12 total = myTime + answer;
   cout << "total=" << total << endl;

  
   myTime.addTime(770);
   answer = myTime += 7;
   myTime.writeTime();
   cout << endl << "answer=" << answer <<endl;
   
   cout << endl<<"Enter in your myTime in the format: HH:MM [AM/PM]"<<endl;
   myTime.readTime();
   cout << "Time read in=" << myTime << endl;

   time12 myTime2;
   cout << endl<<"Enter in myTime2 in the format: HH:MM [AM/PM]"<<endl;
   cin >> myTime2;
   cout << myTime2 << endl;

   if (myTime2 == myTime)
       cout << "myTime == myTime2" << endl;
   else
       cout << "myTime != myTime2" << endl;

   if (myTime < myTime2)
       cout << "myTime < myTime2" << endl;
   else
       cout << "myTime >= myTime2" << endl;

	try
	{
	   time12 delta(1,20);
	   time12 base(2,50,PM);
	   time12 sum;
	   sum = base + 70;
	   cout << "base+70 = " << sum << endl;
	   sum = 70 + base;
	   cout << "70+base = " << sum << endl;
	   sum = base + delta;
	   cout << "base+delta = " << sum << endl;
	   sum = base - delta;
	   cout << "base-delta = " << sum << endl;
	   sum = delta - base;
	   cout << "base-delta = " << sum << endl;
	}
	catch (rangeError re)
	{
		cerr << re.what() << endl;
	}
   
   


}