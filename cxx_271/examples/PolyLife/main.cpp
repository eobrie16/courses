#include <iostream>
using namespace std;
#include "Life.h"










// Return the number of adjacent Ants to the cell defined by col and row


// Look for an adjacent Empty cell to create a baby Ant in.
// Also output a print line announcing the baby's birth


extern World theWorld;


int main()
{
    bool continueFlag = true;
	do
    {
        int density;
        cout << "To play the game of life, enter an integer between 1 and 99: ";
        cin >> density;
        if (density > 0 && density <= 99)
            theWorld.lifeGame(density);
        else
            continueFlag = false;
    } while (continueFlag);        

	return 0;
}