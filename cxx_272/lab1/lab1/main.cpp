#include <iostream>
using namespace std;

#include "d_random.h"

int countHeads (int n, randomNumber& rnd);
double empiricalHeadToss();
const int NUMBERTOSSES = 20;


int main ()
{
  randomNumber r(100);
  int a, b, c;

  a=4;
  b=8;
  c=4;

  cout << a << " cards, " << countHeads(a,r) << "heads" << endl;
  cout << b << " cards, " << countHeads(b,r) << "heads" << endl;
  cout << c << " cards, " << countHeads(c,r) << "heads" << endl;

  cout << empiricalHeadToss() << endl;

  }

int countHeads (int n , randomNumber& rnd)
{
  int x=0;
  for (int i=0; i<n; i++)
  {
    // Assume half are heads
    if (rnd.frandom() < 0.5)  x++;
  }
  return x;
}

double empiricalHeadToss()
{
	randomNumber r(1000);
	int mHeadCount=0;

	mHeadCount = countHeads(NUMBERTOSSES,r);
	return double(mHeadCount)/NUMBERTOSSES;
}
