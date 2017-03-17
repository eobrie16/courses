#include <iostream>
#include <fstream>
#include <vector>

#include "d_hash.h"
#include "d_hashf.h"

using namespace std;



ifstream & getWord(ifstream&fin, string &w)
{
    char c;
    w=""; //clear the string of charactes

    while (fin.get(c))
    {
        c=tolower(c);
        if (c >= 'a' && c <= 'z') break;
    }

    //return on end-of-file
    if (fin.eof()) return fin;

    // record first letter of the word
    w += c;

    //collect letters 
    while (fin.get(c))
    {
        c = tolower(c);
        if (c < 'a' || c > 'z') break;
        w +=c;

    }

    return fin;
}

int main()
{

	ifstream dict;
	dict.open("dict.txt");

	hash<string, hFstring> hm(1373), hmMispelled(1373);
	pair<hash<string, hFstring>::iterator, bool> p;

	// insert elements from intArr, noting duplicates
	string word;
	while (dict)
	{
		dict >> word;
		//cout << word << endl;
		p = hm.insert(word);
	}

	// output the hash size which reflects duplicates
	cout << "Dictionary size " << hm.size() << endl;

	ifstream input("document.txt");
	string word2,word3;
	hash<string, hFstring>::iterator hIter;
	int count=0, miscount=0;
	while (getWord(input, word2))
	{
		hIter = hm.find(word2);
		if (hIter == hm.end())
		{
			word3 = word2.substr(0,word2.length()-1);
			hIter = hm.find(word3);
			if (hIter == hm.end())
			{
				hIter = hmMispelled.find(word2);
				if (hIter == hmMispelled.end())
				{
					cout << "Mispelled Word: " << word2 << endl;
					hmMispelled.insert(word2);
					miscount++;
				}
			}
		}
		count++;
	}

	cout << "Total Words: " << count << endl;
	cout << "Mispelled Words: " << miscount << endl;

}
