#include <iostream>
#include <fstream>                
using namespace std;

void writefile(char * f)
{
	const int MAX = 80;
	char buffer[MAX];
	ifstream infile(f);
	while (infile.good())
	{
		infile.getline(buffer, MAX);
		cout << buffer << endl; 
	}
}

int main(int argc, char *argv[])
{
	for (int i=1; i<argc; i++)
		writefile(argv[i]);

	return 0;
}
