// ***************   main.cpp ******************
#include <iostream>
using namespace std;
#include "zoo.h"

#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


void doit()
{
    Zoo z;
    Horse * prince = new Horse(1550, "Prince");
    Cow * mollie = new Cow(1220, "Mollie");
    Snake * sly = new Snake(5, "Sly");
    Cow * milkey = new Cow(1110, "Milkey");

    z.addAnimaltoZoo(prince);
    z.addAnimaltoZoo(mollie);
    z.addAnimaltoZoo(sly);
    z.addAnimaltoZoo(milkey);
    
    cout << "The total weight for the zoo is "
         << z.getTotalZooWeight() << " pounds." << endl;

    z.makeAllNoisesInZoo();
}
int main()
{
    doit();
    _CrtDumpMemoryLeaks();

	return 0;
}
