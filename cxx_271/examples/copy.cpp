#include <iostream>
#include <fstream>
using namespace std;

const int BUFF_SIZE=100;

bool copy(const char * ifile, const char * ofile)
{
	ifstream in(ifile, ios::binary);
	ofstream out(ofile, ios::binary);

	if (!in || !out) return false;

	char buff[BUFF_SIZE];

	while (in)
	{
		in.read(buff, sizeof(buff));
		
		int numBytesRead = in.gcount();
		if (!in)
			cout << "Termination" << endl;
		out.write(buff, numBytesRead);
		
	}
	return true;

}

int main(int argc , char * argv[])
{
	if (argc != 3)
	{
		cout << "Copy needs 2 filenames"<<endl;
		return -1;
	}
	char * inputFilename = argv[1];
	char * outputFilename = argv[2];

	copy(inputFilename, outputFilename);
}