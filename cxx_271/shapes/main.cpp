#include <iostream>
#include "shapes.h"
using namespace std;

 int main()
 {

	 //RegularPoly c(4.0, 4);
	 //cout << "per= " << c.getPerimeter() << endl;
	 //cout << "area= " << c.getArea() << endl;
     
    ShapeArr  arr(3);

    cout << "Rectangles *******"<<endl;
    arr.addRectangle(1.0, 2.0);
    arr.addRectangle(3.0, 2.0);
    arr.addRectangle(2.0, 2.0);
    arr.publishStats();

    cout << "Circles *******"<<endl;
    ShapeArr arr2(3);
    arr2.addCircle(1.0);
    arr2.addCircle(2.0);
    arr2.addCircle(3.0);
    arr2.publishStats();

    cout << "Triangles *******"<<endl;
    ShapeArr arr3(3);
// Note that angles are in Radians (NOT degrees)
    arr3.addTriangle(1.0, 4.0, 1.0);
    arr3.addTriangle(1.0, 30., 2.);
    arr3.addTriangle(1.0, 0.8, 1.0);
    arr3.publishStats();
    
    cout << "Regular Polygon *******"<<endl;
    ShapeArr arr4(3);
    arr4.addRegularPoly(1.0, 3);
    arr4.addRegularPoly(1.0, 10);
    arr4.addRegularPoly(1.0, 50);
    arr4.publishStats();

  
    cout << "Mixture *******"<<endl;
    ShapeArr arr5(4);
    arr5.addRegularPoly(1.0, 3);
    arr5.addCircle(3.0);
    arr5.addTriangle(1.0, 0.8, 1.0);
    arr5.addRegularPoly(1.0, 50);
    arr5.publishStats();
 
 }
