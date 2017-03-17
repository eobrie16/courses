// ***************** zoo.h *************************

enum animal_type {t_Horse, t_Cow, t_Snake};

class Animal
{
   double weight;
   animal_type type;
   string name;

  public:
   Animal(double w, animal_type t, char * n): 
                     weight(w), type(t), name(n)
   {
   }
   virtual void makeNoise()
   {
      cout << "This should never be called for any animal"
                  << endl;
   }

   const char *getName()
   {
      return name.c_str();
   }


   double getWeight()
   {
      return weight;
   }

   animal_type getAnimalType()
   {
      return type;
   }

};

class Horse : public Animal
{
public:
    Horse (double weight, char * name);
    void makeNoise(); // Horses should say Whinney
};

class Snake : public Animal
{
public:
    Snake (double weight, char * name);
    void makeNoise(); // Snakes should say Hiss
};


class Cow : public Animal
{
public:
    Cow (double weight, char * name);
    void makeNoise();  // Cows should say Mooo
};

const int ZOO_SIZE=10;

class Zoo
{
    
    Animal * animals[ZOO_SIZE];
    int animalCount;
public:
    Zoo(): animalCount(0)
    {
    }
    ~Zoo();

    // The following method adds the specified animal to the Zoo
    void addAnimaltoZoo(Animal *a);

    // The following calls the makeNoise routines for all of the 
    // animals in the zoo
    void makeAllNoisesInZoo();

    // The following returns the total weight of the Zoo
    double getTotalZooWeight();
};
