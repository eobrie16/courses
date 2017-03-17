// ************************************************
// Distance.h
// ************************************************
#include <iostream>
using namespace std;


class Distance                    //English Distance class
{
private:
    int feet;
    int inches;

    // Normalize adjusts feet and inches if inches is >= 12;
    void Normalize();

    // utility function to return Distance in inches
    int sizeInInches() const;
    
public:
    
    // Constructors
    Distance();  // default constructor setting feet=0 and inches=0
    Distance(int initialValueInInches);

    // used for int x = dist1;
    operator int();
    
    // used for dist3 = dist1 + dist2;
    Distance operator + (Distance & d2) const;

    // used for dist1 += dist2;
    void operator += (Distance & d2);

    // used for dist1 += 22;
    void operator += (int value);

    // used for dist1 = dist2
    void operator = (Distance & d2);

    // used for dist1 = 22
    void operator = (int value);

    // used for if (dist1 == dist2) ...
    bool operator == (Distance & d2)  ;

    // used for if (dist1 < dist2) ...
    bool operator < (Distance & d2) ;

    
    // **************************************

    void getdist()              //get length from user
    {
        cout << "\n   Enter feet: ";  cin >> feet;
        cout << "   Enter inches: ";  cin >> inches;
    } 
    void showdist()
    {
        cout << " feet=" << feet << " inches=" << inches;
    }
};

class ArrDistance
{
    Distance * arr;
    int arrSize;
public:
    // Constructor creates an Array of Distance classes the 
    // size specified in size.  
    ArrDistance(int size);

    // Make sure you free up your dynamic allocation
    ~ArrDistance();

    // This operator should do a sanity check on the index
    Distance & operator [](int index);
};
