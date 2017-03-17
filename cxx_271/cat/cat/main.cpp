#include <iostream>
#include <fstream>                
using namespace std;


void write2file(char * out, char * file)
{
	const int MAX = 80;
	char buffer[MAX];
	ifstream infile(file);
	if (out == NULL)
	{
		while (infile.good())
	    {
		  infile.getline(buffer, MAX);
		  cout << buffer << endl; 
	    }
	}
	else
	{
		ofstream outfile(out, ios::app);
		while (infile.good())
	    {
		  infile.getline(buffer, MAX);
		  outfile << buffer << endl;
	    }
	}
}

int main(int argc, char *argv[])
{
	char *outfile;
	int start;
	outfile = argv[1];
	if (outfile[0]=='-' && outfile[1]=='o')
	{
		outfile = argv[2];
        //probably more elegant way to do this
		//want to make sure file is empty before writing
		ofstream temp(outfile, ios::trunc);
		temp.close();
		start = 3;
		cout << "Output file: " << outfile << endl;
	}
	else
	{
		start = 1;
		outfile = NULL;
		cout << "Output to cout." << endl;
	}
	for (int i=start; i<argc; i++)
		  write2file(outfile, argv[i]);
	

	return 0;
}