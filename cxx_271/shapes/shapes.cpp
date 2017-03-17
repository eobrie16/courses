#####################################
#shapes.cpp
#
#include <iostream>
using namespace std;
#include <cmath>
#include "shapes.h"


Circle::Circle(double r=1.0): radius(r)
	{
	}
double Circle::getPerimeter()
	{
		return PI2*radius;
	}
double Circle::getArea()
	{
		return PI*radius*radius;
	}

Rectangle::Rectangle(double l=1.0, double w=1.0): length(l), width(w)
	{
	}
double Rectangle::getPerimeter()
	{
		return 2*(length+width);
	}
double Rectangle::getArea()
	{
		return length*width;
	}

Triangle::Triangle(double a=1.0, double b=1.0, double r=PI/2)
	{
		sideA = a;
		sideB = b;
		r = fabs(r);
		while (r > PI2)
		{
			r -= PI2;
		}
		includedAngle = r;
	}
double Triangle::getPerimeter()
	{
		return sideA + sideB + sqrt(sideA*sideA + sideB*sideB - 2.0*sideA*sideB*cos(includedAngle));
	}
double Triangle::getArea()
	{
		return 0.5 * sideA * sideB * fabs(sin(includedAngle));
	}


RegularPoly::RegularPoly(double s, int n): side(s), numSides(n)
	{
	}
double RegularPoly::getPerimeter()
	{
		return numSides*side;
	}
double RegularPoly::getArea()
	{
		return (numSides * side * side) / (4.0* tan(PI/numSides));
	}


ShapeArr::ShapeArr(int size)
	{
		arrSize = size;
		arr = new Shape * [arrSize];
		currCount = 0;
	}
ShapeArr::~ShapeArr()
	{
		for (int i=0; i<arrSize; i++)
			delete arr[i];
		delete arr;
	}
void ShapeArr::addRectangle(double height, double width)
	{
		arr[currCount] = new Rectangle(height, width);
		currCount++;
	}
void ShapeArr::addCircle(double radius)
	{
		arr[currCount] = new Circle(radius);
		currCount++;
	}
void ShapeArr::addTriangle(double sideA, double includedAngle, double sideB)
	{
		arr[currCount] = new Triangle(sideA, sideB, includedAngle);
		currCount++;
	}
void ShapeArr::addRegularPoly(double side, int numSides)
	{
		arr[currCount] = new RegularPoly(side, numSides);
		currCount++;
	}
void ShapeArr::publishStats()
	{
		double max=0.0;
		double avg=0.0;
		double temp = 0.0;
		for (int i=0; i<currCount; i++)
		{

			temp = arr[i]->getAPRatio();
			avg += temp;
			if (temp > max) max = temp;
		}
		avg = avg / currCount;
		cout << "Max APRatio = " << max << " Average APRatio = " << avg << endl;
	}