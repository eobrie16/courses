#include <iostream>
using namespace std;
#include <string>
#include "zoo.h"

Animal::Animal(double w, animal_type t,   const char * n)
{
	weight = w;
	type = t;
	name = n;

	if (type == t_Horse)
		sound = "whinney";	
	else if (type == t_Cow)
		sound = "moo";
	else if (type == t_Snake)
		sound = "hiss";
	else
		cout << "Animal not found!" << endl;
}

void Animal::makeNoise()
{
	cout << name << " says " << sound << endl;
}

const char *Animal::getName()
{
	return name.c_str();
}

double Animal::getWeight()
{
	return weight;
}

animal_type Animal::getAnimalType()
{
	return type;
}

Zoo::~Zoo()
{
	for (int i=0; i<animalCount; i++)
	  delete animals[i];

}

void Zoo::addAnimaltoZoo(animal_type t, double weight, const char * name)
{
	animals[animalCount] = new Animal(weight, t, name);
	animalCount++;
}

void Zoo::addAnimaltoZoo(Animal * a)
{
	animals[animalCount] = new Animal(a->getWeight(), a->getAnimalType(), a->getName());
	animalCount++;
}

void Zoo::makeAllNoisesInZoo()
{
	for (int i=0; i<animalCount; i++)
		animals[i]->makeNoise();
}

double Zoo::getTotalZooWeight()
{
	double totalWeight=0;
	for (int i=0; i<animalCount; i++)
		totalWeight += animals[i]->getWeight();
	cout << "The total weight of the zoo is " << totalWeight << endl;
	return totalWeight;
}
