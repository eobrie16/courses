#include <iostream>
#include <string.h>
using namespace std;

// This function should completely copy the array in src into 
//   the array dst.  The src array is null (zero) terminated.
//   In otherwords, if src contains 5 entries (0, 1, 2, 3, and 4),
//   then the fifth entry is zero and this tells you how many 
//   entries are filled in src. 

void mystrcpy(char dst[], const char src[])
{
	int i=0;

	do 
	{
		dst[i] = src[i];
		i++;
	} while (src[i-1] != '\0');
}


// This function does the same thing as mystrcpy if the number
// of characters in src is no more than n.  Otherwise,
// mystrncpy will copy only n characters if src contains more 
// than n characters. 

void mystrncpy(char  dst[], const char src[], int n)
{
	int num, i=0;
	if (strlen(src) > n)
		num = n;
	else
		num = strlen(src);

	for (int i=0; i<num; i++)
	{
		dst[i]=src[i];
	} 
	dst[num] = '\0';

}


void main()
{
   char s1[] = "Hello there ";
   char result[40];
   char s2[] = "Testing my routine";
   char result2[40];
   char result3[40];

   strcpy(result, s1);
   cout << "The output string: " << result <<endl;
   mystrcpy(result2, s2);
   cout << "My output string: " << result2 <<endl;

   strncpy(result,"1234567", 2);
   cout << "The first 2 bytes of the output string: " << result << endl;

   mystrncpy(result3,"1234567", 2);
   cout << "The first 2 bytes of My output string: " << result3 << endl;

}
