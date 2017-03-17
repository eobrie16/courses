#########################################
#shapes.h
#
#include <iostream>
using namespace std;
#include <cmath>

const double PI = 3.14159265359;
const double PI2 = 2*PI;

class Shape
{   
public:
   Shape()
   {
   }   
   virtual double getPerimeter()=0;
   virtual double getArea()=0;
   
   double getAPRatio()
   {
       double p = getPerimeter();
       if (p == 0.0) return 0.0; // indeterminate
       return getArea()/p;
   }
   virtual ~Shape()
   { // When everything is freed up properly,

    cout << "Shape Destructor"<<endl;
   };
};

class Circle : public Shape
{
private:
	double radius;
public:
    Circle(double r);
	double getPerimeter();
	double getArea();
};


class Rectangle : public Shape
{
private:
	double length, width;
public:
    Rectangle(double l, double w);
	double getPerimeter();
	double getArea();

};

class Triangle : public Shape
{
private:
	double sideA, sideB, includedAngle;
public:
    Triangle(double a, double b, double r);
	double getPerimeter();
	double getArea();

};

class RegularPoly : public Shape
{
private:
	int numSides;
	double side;
public:
    RegularPoly(double s, int n);
	double getPerimeter();
	double getArea();

};

class ShapeArr
{
// The following is what you need to have an 
// array of pointers to the Shape class

    Shape ** arr;
    int arrSize;   
    

// To allocate this array, you will need something like:
//    arr = new Shape* [arrSize];
// Note that you are responsible for freeing up all of 
// the memory when your ShapeArr class is destructed.
// If you do it correctly, you should see the Shape Destructor
// generate it's cout statement for every Shape class created. 

// It's useful to keep track of the number of Shapes added to 
// the array. 

    int currCount;
public:
    ShapeArr(int arrSize);
    ~ShapeArr();
    void addRectangle(double height, double width);
    void addCircle(double radius);      
    void addTriangle(double sideA, double includedAngle, double sideB);
    void addRegularPoly(double side, int numSides);

   // This routine prints out the Max getAPRatio and the average 
   // getAPRatio for all of the Shapes in this class.

    void publishStats();
};