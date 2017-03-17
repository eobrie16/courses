#include <iostream>
using namespace std;
#include <string>
// The following 3 lines are used to turn on Memory Leak Debug Info
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

enum animal_type {t_Horse, t_Cow, t_Snake};

class Animal
{
   double weight;
   animal_type type;
   string name;
   string sound;

  public:
  // The following constructs an animal, note that additionally,
  // you will need to set the "sound" variable based on the animal_type
  // Horses make the sound="whinney", For Cows, sound = "Moo", and 
  // for Snakes sound = "Hiss"
   Animal(double w, animal_type t,   const char * n);
  
   // cout is called to print out the sound of the animal
   void makeNoise();

   // Return the name of the anmial.  
   // Note the string class has a method c_str() that 
   // returns what you want
   const char *getName(); 

   double getWeight();
   animal_type getAnimalType();
};

class Zoo
{
    Animal * animals[10];
    int animalCount;
public:
    Zoo(): animalCount(0)
    {
    }

    // The following destructor is responsible for cleaning up allocated memory
    ~Zoo();
    

    // The following method adds the specified animal to the Zoo
    void addAnimaltoZoo(animal_type t, double weight, const char * name);
    void addAnimaltoZoo(Animal * a);

    // The following calls the makeNoise routines for all of the 
    // animals in the zoo
    void makeAllNoisesInZoo();

    // The following does a cout with the total weight of the Zoo
    double getTotalZooWeight();
};
