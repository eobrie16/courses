#include <iostream>
#include <string.h>
using namespace std;

// This function adds the characters in s2 to the end of the 
// characters in s1.  The s2 array is null (zero) terminated.
//   In otherwords, if src contains 5 entries (0, 1, 2, 3, and 4),
//   then the fifth entry is zero and this tells you how many 
//   entries are filled in s2.  Note that s1 is also null terminated. 

void mystrcat(char  s1[], const char  s2[])
{
	int j=0;
	int len=strlen(s1);
    do
	{
		s1[len+j] = s2[j];
		j++;
	} while (s2[j] != '\0');
}

// This function performs exactly the same function as 
// mystrcat if the number of characters in s2 is no more than n.
//  Otherwise, mystrncat will add no more than n characters to 
// the end of the s1 array of characters.  

void mystrncat(char s1[], const char  s2[], int n)
{
    int j=0, num;
	int len=strlen(s1);
	if (strlen(s2) > n)
		num = n;
	else
		num = strlen(s2);
	
	do 
	{
		s1[len+j] = s2[j];
		j++;
	} while (j < num);
}

void main()
{
   char s0[30] = "Hello there ";
   char s1[30] = "Hello there ";

   char  s2[] = "dude";
   char  s3[] = "spectacular!";

   cout << "The input string: " << s1 << endl;

   strcat(s0, s2);
   mystrcat(s1, s2); // does the same thing as strcat(s1,s2)

   cout << "The concatenated string (s0): " << s0 <<endl;
   cout << "The concatenated string (s1): " << s1 <<endl;


   strncat(s0,s3, 1); 
   mystrncat(s1,s3, 1); // does the same thing as strncat(s1,s3,1)
   cout << "The first string plus 1 byte of the second string(s0): " << s0 << endl;
   cout << "The first string plus 1 byte of the second string: " << s1 << endl;

}