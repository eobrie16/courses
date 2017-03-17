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
	bool ok_flag;
};

void add2Drawer(CHANGE & drawer, CHANGE money)
{
   drawer.tens = drawer.tens + money.tens;
   drawer.fives = drawer.fives + money.fives;
   drawer.ones = drawer.ones + money.ones;
   drawer.quarters = drawer.quarters + money.quarters;
   drawer.dimes = drawer.dimes + money.dimes;
   drawer.nickels = drawer.nickels + money.nickels;
   drawer.pennies = drawer.pennies + money.pennies;

}


void readChange(CHANGE &chg)
{
    cout <<endl << "tens=";     cin >> chg.tens;
    cout << "fives=";    cin >> chg.fives;
    cout << "ones=";     cin >> chg.ones;
    cout << "quarters="; cin >> chg.quarters;
    cout << "dimes=";    cin >> chg.dimes;
    cout << "nickels=";  cin >> chg.nickels;
    cout << "pennies=";  cin >> chg.pennies;    
}

int valueOfChange(CHANGE &chg)
{
    return chg.pennies + 5*chg.nickels + 10*chg.dimes + 25*chg.quarters +
                         100*chg.ones + 500*chg.fives + 1000*chg.tens;
}

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


CHANGE getChange(int cost, CHANGE paid, CHANGE & inp_drawer)
{
    CHANGE chg;
	int remain;

	chg.ok_flag = true;
	remain = valueOfChange(paid) - cost;

	chg.tens = getRemain(1000, remain);
	if (chg.tens > inp_drawer.tens) chg.ok_flag = false;
	chg.fives = getRemain(500, remain);
	if (chg.fives > inp_drawer.fives) chg.ok_flag = false;
	chg.ones = getRemain(100, remain);
	if (chg.ones > inp_drawer.ones) chg.ok_flag = false;
	chg.quarters = getRemain(25, remain);
	if (chg.quarters > inp_drawer.quarters) chg.ok_flag = false;
	chg.dimes = getRemain(10, remain);
	if (chg.dimes > inp_drawer.dimes) chg.ok_flag = false;
	chg.nickels = getRemain(5, remain);
	if (chg.nickels > inp_drawer.nickels) chg.ok_flag = false;
	chg.pennies = remain;
	if (chg.pennies > inp_drawer.pennies) chg.ok_flag = false;

	if (chg.ok_flag)
	{
		inp_drawer.tens = inp_drawer.tens - chg.tens;
		inp_drawer.fives = inp_drawer.fives - chg.fives;
		inp_drawer.ones = inp_drawer.ones - chg.ones;
		inp_drawer.quarters = inp_drawer.quarters - chg.quarters;
		inp_drawer.dimes = inp_drawer.dimes - chg.dimes;
		inp_drawer.nickels = inp_drawer.nickels - chg.nickels;
		inp_drawer.pennies = inp_drawer.pennies - chg.pennies;
		add2Drawer(inp_drawer, paid);
	}

	return chg;
}

int main()
{
    CHANGE drawer;
    cout << endl << "Enter the money in the Cash Drawer: "<< endl;
    readChange(drawer);
    cout << "=============================" << endl;

    int priceInPennies = getMoney( "Enter Price ");

    while (priceInPennies > 0)
    {
        CHANGE moneySubmitted;
        cout << endl << "Enter the money submitted to the store: "<< endl;
        readChange(moneySubmitted);

        CHANGE returnVal = getChange(priceInPennies, moneySubmitted, drawer);
        if (returnVal.ok_flag)
        {
            cout << "Change Returned:" << endl;
            printChange(returnVal);
        }
        
        cout << "Drawer contains: ";
        printChange(drawer);
        cout << "*********************" << endl;

        priceInPennies = getMoney( "Enter Price ");
    }

    return 0;
}
