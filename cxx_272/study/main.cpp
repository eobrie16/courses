#include <iostream>
#include <fstream>
#include <vector>
#include "param.h"
#include "qsort.h"
using namespace std;

const int MAX=128;
void readNames(char *filename, vector<Parm> & names);

int main()
{
        vector<Parm> names;
        readNames("boys.txt", names);
        int size = names.size();
        quicksort(names, 0, size-1);
		for (int i=0; i<names.size(); i++)
		{
			names[i].print();
		}
		string input;
		int count=0;
		int found;
		cout << "Enter Name to look up:  ";
	    cin >> input;
		while (input != "q")
		{
			Parm test(input, 1);
			found = binSearch(test, names, 0, names.size()-1, count);
			cout << input << " found at index: " << found << " count= " << count << endl;
			cout << "Enter Name to look up:  ";
			cin >> input;
		}

}

void readNames(char *filename, vector<Parm> & names)
{
    ifstream input(filename);
    string n, temp, temp2;
    int f,i=0;
    char buff[MAX];
    while (input)
    {
      input.getline(buff, MAX);
          temp = buff;
          if (temp.find(' ') != string::npos)
          {
                n = temp.substr(0,temp.find(' '));
                //cout << n << endl;
                temp2 = temp.substr(temp.find(' ')+1, temp.length());
                //cout << temp2 << endl;
                f = atol(temp2.c_str());
                Parm new_r(n, f);
                names.push_back(new_r);
                i++;
           }
	}
	cout << "Read " <<  i << " lines!" << endl;
}
