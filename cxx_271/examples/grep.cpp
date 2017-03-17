#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void sToLower(string & str)
{
	for (int i=0; i < (int)str.length(); i++)
		str[i] = tolower(str[i]);
}

int grep(bool caseInsensitive, bool lineNumbers, char * match, char * filename)
{
	int count =0;
	string smatch = match;
	if (caseInsensitive)
		sToLower(smatch);

	ifstream input(filename);
	if (!input) return 0;

	string sbuff, sbuffForMatch;
	int lineCount = 1;

	while (getline(input, sbuff))
	{
		sbuffForMatch = sbuff;
		if (caseInsensitive)
			sToLower(sbuffForMatch);
		if (sbuffForMatch.find(smatch)!=string::npos)
		{
			cout <<filename<<":";
			if (lineNumbers)
				cout << lineCount<<":";
			cout << sbuff << endl;
		}
		lineCount +=1;
	}

	return count;
}

int main(int argc ,   char * argv[])
{
	bool caseInsensitive=false;
	bool lineNumbers = false;
	char * match =NULL;

	for (int i=1; i < argc; i++)
	{
		char * str = argv[i];
		if (strcmp(str, "-i") ==0)
		{
			caseInsensitive=true;
			continue;
		}
		if (strcmp(str, "-n") ==0)
		{
			lineNumbers=true;
			continue;
		}
		if (match == NULL)
		{
			match = str;
			continue;
		}

		grep(caseInsensitive, lineNumbers, match, str);
	}
}