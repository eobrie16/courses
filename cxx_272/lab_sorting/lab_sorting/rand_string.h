// RandStrings.h

#include "d_random.h"
#include <time.h>
#include <string>

class RandStrings
{
public:
  RandStrings(int seed=0): rand(seed)
  {}
  string getRandString(int numChars=8);

private:
  char getRandChar();
  randomNumber rand;
};

string RandStrings::getRandString(int numChars)
{
  string retVal;
  for (int i=0; i < numChars; i++)
    retVal += getRandChar();

  return retVal;
}

char RandStrings::getRandChar()
{
  char c = 'a' + rand.random(26);
  return c;
}