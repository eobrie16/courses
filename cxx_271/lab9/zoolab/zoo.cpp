#include <iostream>
using namespace std;
#include "zoo.h"


Horse::Horse (double weight, char * name):Animal(weight, t_Horse, name)
{
}
void Horse::makeNoise()
{
	cout << "Whinney" << endl;
}

Snake::Snake (double weight, char * name):Animal(weight, t_Snake, name)
{
}
void Snake::makeNoise()
{
	cout << "Hiss" << endl;
}

Cow::Cow (double weight, char * name):Animal(weight, t_Cow, name)
{
}
void Cow::makeNoise()
{
	cout << "Moo" << endl;
}

Zoo::~Zoo()
	{
		for (int i=0; i<animalCount; i++)
			delete animals[i];
	}

    // The following method adds the specified animal to the Zoo
void Zoo::addAnimaltoZoo(Animal *a)
	{
		//char * name = (char *) a->getName();
		//animals[animalCount] = new Animal(a->getWeight(), a->getAnimalType(), name);
		animals[animalCount] = a;
		animalCount++;
	}

// The following calls the makeNoise routines for all of the 
// animals in the zoo
void Zoo::makeAllNoisesInZoo()
{
	for (int i=0; i<animalCount; i++)
	{
		Animal * a = animals[i];
		if (a->getAnimalType() == t_Horse)
		{
			Horse * h;
			h = (Horse *) a;
			h->makeNoise();
		}
		else if (a->getAnimalType() == t_Snake)
		{
			Snake * s;
			s = (Snake *) a;
			s->makeNoise();
		}
		else if (a->getAnimalType() == t_Cow)
		{
			Cow * c;
			c = (Cow *) a;
			c->makeNoise();
		}
		//should never get here
		else
			cout << "Animal Not Found!" << endl;
	}
		
}

    // The following returns the total weight of the Zoo
double Zoo::getTotalZooWeight()
	{
		double totalWeight=0.0;
		for (int i=0; i<animalCount; i++)
			totalWeight += animals[i]->getWeight();
		return totalWeight;

	}