#include <iostream>
using namespace std;

class Distance                    //English Distance class
   {
   private:
      int feet;
      int inches;
      void Normalize(); // Useful routine to adjust inches < 12
   public:
    Distance();  // default constructor setting feet=0 and inches=0
	Distance(float initialValueInFeet); 
	Distance(int initialValueInInches);
	void add( Distance & currTotal); //add passed in Distance
	void add ( float distanceInFeet); //add dist in feet
	void add ( int distanceInInches); //add dist in inches
	void getdist();             //get length from user
	void showdist() const;       //display distance
   };
