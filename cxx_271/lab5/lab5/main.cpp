#include "zoo.h"

void doit()
{
    Zoo z;
    z.addAnimaltoZoo(t_Horse, 1550, "Prince");
    z.addAnimaltoZoo(t_Cow, 1220, "Mollie");
    z.addAnimaltoZoo(t_Snake, 5, "Sly");
    z.addAnimaltoZoo(t_Cow, 1110, "Milkey");

    Animal* a=  new Animal(1300, t_Horse, "Scout");
    // Note we will not explicitly  delete "Animal a" because
    // it will be deleted in the destructor for "Zoo z".  
    z.addAnimaltoZoo(a);

    z.getTotalZooWeight();
    z.makeAllNoisesInZoo();

	delete a;
    
}
int main()
{
    doit();
    
// The following call will check for memory leaks and print them
//     out if we run the debugger. 
     _CrtDumpMemoryLeaks();

	 return 0;
}