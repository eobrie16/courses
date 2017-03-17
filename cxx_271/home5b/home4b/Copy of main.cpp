#include <iostream>
#include <fstream>                
using namespace std;


void makeLower(char * x)
{
   char temp[100];
   int len = strlen(x);

   for (int i=0; i <= len; i++)
   {
       temp[i] = tolower(x[i]);
	   x[i] = temp[i];
   }

}

int main(int argc, char *argv[])
{
	char * infile;
    char *search;
	bool caseins = false;
	bool lineno = false;
	const int MAX = 100;
	char buff[MAX], tempstr[MAX];
	int i=1, line=1;
	while (argv[i][0] == '-')
	{
		if (argv[i][1] == 'i')
		{
			caseins = true;
		}
		else if (argv[i][1] == 'n')
			lineno = true;
		else
		{
			cout << "ERR: INVALID OPTION!\n";
			return -1;
		}
		i++;
	}
	
	search = argv[i];
	i++;
	while (i<argc)
	{
    	infile = argv[i];
		line = 1;
		cout << endl;
		
	    if (caseins)
			makeLower(search);
	    ifstream temp(infile);
	    while (temp.good())
	    {
			temp.getline(buff, MAX*sizeof(char));
			strcpy(tempstr, buff);
			if (caseins)
				makeLower(buff);
			if (strstr(buff, search) != NULL)
				if (lineno)
    				cout << infile << ":" << line << ": " << tempstr << endl;		
				else
					cout << infile << ": " << tempstr << endl;
			line++;
		}
		i++;
	}
	

	return 0;
}