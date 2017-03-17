#include <iostream>
using namespace std;

struct CHANGE
{
    int tens;
	int fives;
	int ones;
	int quarters;
	int dimes;
	int nickels;
	int pennies;
};

void printChange(CHANGE chg)
{
    cout << "tens=" << chg.tens << " fives=" << chg.fives << " ones=" << chg.ones<<
              " quarters="<< chg.quarters << " dimes=" << chg.dimes <<
              " nickels=" << chg.nickels << " pennies=" << chg.pennies << endl;
}

int getMoney( char prompt[])
{
    cout << prompt << " [format: dollars.pennies] = ";
    double money;
    cin >> money;
    // Adding 0.005 and casting with (int) effectively does a Rounding operation
    // to the nearest penny
    return (int)(money*100+0.005);
}

int getRemain(int cents, int & remain)
{
	int change;

	change = remain/cents;
	remain = remain%cents;

	return change;
}


CHANGE getChange(int cost, int paid)
{
    CHANGE chg;
	int remain;

	remain = paid - cost;

	chg.tens = getRemain(1000, remain);
	chg.fives = getRemain(500, remain);
	chg.ones = getRemain(100, remain);
	chg.quarters = getRemain(25, remain);
	chg.dimes = getRemain(10, remain);
	chg.nickels = getRemain(5, remain);
	chg.pennies = remain;

	return chg;
}

int main()
{
    int priceInPennies = getMoney( "Enter Price ");

    while (priceInPennies > 0)
    {
        int moneyInPennies = getMoney( "Enter Money Submitted ");
        CHANGE returnVal = getChange(priceInPennies, moneyInPennies);
        cout << "Change Returned:" << endl;
        printChange(returnVal);
        cout << "*********************" << endl;

        priceInPennies = getMoney( "Enter Price ");
    }

    return 0;
}