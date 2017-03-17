#include <iostream>
using namespace std;

int values[] ={1000, 500, 100, 25, 10, 5, 1};
char * names[] = {"tens", "fives", "ones", "quarters", "dimes", "nickels", "pennies"};
const int num_items = sizeof(values)/sizeof(int);

struct CHANGE
{
    int items[num_items];
};

void printChange(CHANGE chg)
{
	for (int i=0; i < num_items; i++)
		cout << names[i] << " = " << chg.items[i] << "  " ;

	cout << endl;    
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



CHANGE getChange(int cost, int paid)
{
    CHANGE retVal;
    int money= paid - cost;

	for (int i=0; i < num_items; i++)
	{
		retVal.items[i] = money / values[i];
		money = money % values[i];
	}
    return retVal;
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