#include <iostream>
#include <fstream>                
using namespace std;

const int MAX=256;

class myGrep
{
private:
	char buff[MAX];
	char * searchstr;
	bool caseins;
	bool lineno;
public:
	myGrep(char * s, bool c, bool l)
	{
		buff[0] = 0;
		searchstr = s;
		caseins = c;
		lineno = l;
	}

	void processFile(char * filename)
	{
		int line = 1;
		char tempstr[MAX];
		
	    if (caseins)
			makeLower(searchstr);
	    ifstream in(filename);
	    while (in)
	    {
			in.getline(buff, MAX*sizeof(char));
			strcpy(tempstr, buff);
			if (caseins)
				makeLower(buff);
			if (strstr(buff, searchstr) != NULL)
				if (lineno)
    				cout << filename << ":" << line << ": " << tempstr << endl;		
				else
					cout << filename << ": " << tempstr << endl;
			line++;
		}
	}

	void makeLower(char * x)
	{
		char temp[MAX];
		int len = strlen(x);

		for (int i=0; i <= len; i++)
		{
		temp[i] = tolower(x[i]);
		x[i] = temp[i];
		}
	}

};


int main(int argc, char *argv[])
{
    char * search;
	bool par1 = false;
	bool par2 = false;
	int i;

	if (argc < 3)
		return -1;
	
	//probably needs more error checking
	if (argv[1][0] == '-' && argv[2][0] == '-')
	{
		for (int k=1; k<3; k++)
		{
			if (argv[k][1] == 'i')
				par1 = true;
			else if (argv[k][1] == 'n')
				par2 = true;
			else
			{
				//Really should inform user which option is wrong
				cout << "IGNORING INVALID OPTION" << endl;
			}
			search = argv[3];
			i = 4;
		}
	}
	else if (strcmp(argv[1], "-i") == 0)
	{
		search = argv[2];
		par1 = true;
		par2 = false;
		i = 3;
	}
	else if (strcmp(argv[1], "-n") == 0)
	{
		search = argv[2];
		par1 = false;
		par2 = true;
		i = 3;
	}
	else
	{
		search = argv[1];
		i = 2;
	}
	myGrep filep(search, par1, par2);

	for (int j=i; j<argc; j++)
	{
		filep.processFile(argv[j]);
	}

	return 0;
}