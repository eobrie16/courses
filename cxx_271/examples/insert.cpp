#include <iostream>
#include <string>
using namespace std;

char *insert(char *base, char *thing, int ipos)
{
	int lenBase = strlen(base);
	int lenThing = strlen(thing);
	char *retstr = new char[lenBase+lenThing+1];
	int count = 0;

	for (int i=0; i < ipos; i++)
		retstr[i] = base[i];

	for (int i=0; i < lenThing; i++)
		retstr[ipos+i] = thing[i];

	for (int i=0; i < lenBase - ipos; i++)
		retstr[ipos + lenThing + i] = base[i+ipos];

	retstr[lenBase + lenThing] = 0;
	return retstr;
}

int main()
   {
	//char cbuff[1000];
    char *cbuff = new char[1000];
	char *base, *thing, *answer;

	cout << "Enter the base string:";
	cin >> cbuff;
	
	int len = strlen(cbuff);
	base = new char[len+1];
	strcpy(base, cbuff);
   
	cout << endl << "Enter thing to insert:";
	cin >> cbuff;
	len = strlen(cbuff);
	thing = new char[len+1];
	strcpy(thing, cbuff);

	int ipos;
	cout << endl << "Enter Insertion Position:";
	cin >> ipos;

	answer = insert(base, thing, ipos);
	cout << endl << "Answer = " << answer << endl;


   return 0;
   }
