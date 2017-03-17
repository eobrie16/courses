// *************************************
// Main.cpp
// *************************************
#include <iostream>
using namespace std;

// The following 3 lines are used to turn on Memory Leak Debug Info
#define CRTDBG_MAP_ALLOC
//#include <crtdbg.h> Used to need to include this

#include "Pointers.h"

void doit(int argc, char * argv[])
{
    /*if (argc <= 1)
    {
        cout << argv[0] << " requires a number parameter" << endl;
        return;
    }
    int num = atol(argv[1]);
	*/
	int num = 4;

    int * intArr = createInts(num);
    cout << "Initial Ints" << endl;
    printInArr(intArr, num);
    
    reverseIntArr(intArr, num);
    cout << "Reversed Ints" << endl;
    printInArr(intArr, num);
    freeIntArr(intArr);

    double * dblArr = createDbls(num);
    cout << "Initial Doubles" << endl;
    printDblArr(dblArr, num);
    cout << "Reversed Doubles" << endl;
    reverseDblArr(dblArr, num);    
    printDblArr(dblArr, num);
    freeDblArr(dblArr);

    Distance *dstArr = createDst(num);
    cout << "Initial Distance " << endl;
    printDstArr(dstArr, num);
    cout << "Reversed Distance " << endl;
    reverseDstArr(dstArr, num);
    printDstArr(dstArr, num);
    free(dstArr);


}

int main(int argc ,  char * argv[])
{
    doit(argc, argv);

// The following call will check for memory leaks and print them
//     out if we run the debugger. 
     _CrtDumpMemoryLeaks();
}