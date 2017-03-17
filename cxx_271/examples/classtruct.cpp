// *************************************
// Main.cpp
// *************************************
#include <iostream>
using namespace std;

class Distance
{
public:
	int feet;
	int inches;
	void add(int f, int i)
	{
		feet += f;
		inches += i;
	}
};

struct SDistance
{
	int feet;
	int inches;
	
	
};





int main(int argc ,  char * argv[])
{
   Distance d;
   SDistance s;

   s.feet = 1;
   s.inches =2;

   d.feet = 1;
   d.inches = 2;
   d.add(100, 11);

   Distance *pd = new Distance;
   (*pd).feet = 10;
   pd->feet = 10;

   (*pd).inches = 11;
   pd->inches = 11;

   Distance *pdarr = new Distance[4];
   pdarr[0].feet = 10;
   pdarr[0].inches =11;
   pdarr[1].feet = 10;
   pdarr[1].inches = 11;

	pdarr->feet =10;
	pdarr->inches =1;
	pdarr +=1;
	pdarr->feet =10;
	pdarr->inches =1;



   SDistance *ps = new SDistance();
   // ps can do everythin pd can do
}