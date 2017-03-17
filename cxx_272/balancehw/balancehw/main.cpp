#include "Balance.h"
#include <iostream>
using namespace std;


void main()
{
    BalanceSymbols balanceSymbols;
    char cbuff[100];
    for(;;)
    {
        cout << "Enter file to process( or quit to exit):";
        cin >> cbuff;
        if (strcmp(cbuff, "quit")== 0) break;

        ifstream infile(cbuff);
        
        if (!infile)
        {
            cout << "Unable to open input file" << endl;
            return;
        }

        try
        {        
            int lineNum=1;
            while (infile)
            {
                string str;
                getline(infile, str);
                if (infile)
                {
                    balanceSymbols.processLine(str, lineNum);
                }
                lineNum += 1;
            }
            balanceSymbols.checkEnd();
            cout << "Everything Balances " << endl;
        }
        catch (string e)
        {
            cout << e << endl;
        }
    }
}
