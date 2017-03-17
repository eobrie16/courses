#include <fstream>
#include <iostream>
using namespace std;

class FileString
{
private:
	char * buff;
	ifstream input;
	bool ok;
public:
  // If File errors exist place them into the string buffer 
  // which starts with **ERR: 
  // For example, **ERR: Couldn't open file
   FileString (string filename)
   {
	   ok = true;
	   input.open(filename.c_str(), ios::binary);
	   if (!input)
		   ok = false;
	   else
	   {
	     input.seekg(0, ios::end);
	     int endpos = input.tellg();
	     buff = new char[endpos+1];
	     input.seekg(0);
         input.read(buff, endpos);
	     buff[endpos] = 0;
	   }
   }

	~FileString()
	{
		if (ok)
		{
  		  input.close();
		  delete buff;
		}
	}

   // A call to value returns the contents of the file. 
   const char * value()
   {
	   if (ok)
		   return buff;
	   else
		   return "**ERR: Couldn't open file.";
   }
};

int main()
{
	FileString myfile("temp.txt");
	cout << myfile.value() << endl;;

	return 0;
}
