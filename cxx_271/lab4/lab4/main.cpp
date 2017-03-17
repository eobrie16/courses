// ************************************************
// englaray.cpp
// ************************************************

// objects using English measurements
#include <iostream>
using namespace std;
#include "Distance.h"

Distance addDistArray(Distance  arr[], int num)
{
	Distance totalDist;
	for (int i=0; i<num; i++)
		totalDist.add(arr[i]);
	return totalDist;
}

int main()
   {
  Distance d1(17.25f), d2(17), d3;

  d1.add(12);
  d2.add(12.25f);
  d3.add(d2);

  cout << "d1="; d1.showdist();  cout << endl;
  cout << "d2="; d2.showdist();  cout << endl;
  cout << "d3="; d3.showdist();  cout << endl;



   const int MAX = 100;
   Distance dist[MAX];            //array of distances
   int n=0;                       //count the entries
   char ans;                      //user response ('y' or 'n')

   cout << endl;

       
   do {                           //get distances from user
      cout << "Enter distance number " << n+1;
      dist[n++].getdist();        //store distance in array
      cout << "Enter another (y/n)?: ";
      cin >> ans;
      } while( ans != 'n' );      //quit if user types 'n'
   
   for(int j=0; j<n; j++)         //display all distances
      {
      cout << "\nDistance number " << j+1 << " is ";
      dist[j].showdist();
      }
   cout << endl;


   Distance total;
   
   total = addDistArray(dist,n);
   cout << "Array Total = " ;
   total.showdist();
   cout << endl;

   return 0;
   }
