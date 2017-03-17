
#include <fstream>
#include "DataBase.h"
#include "d_setops.h"

extern DataBase dataBase;

void readInFile(const char * filename, GENDER gender)
{
    ifstream infile(filename);
    string str;
    while (getline(infile, str))
    {
        Person p(gender,str);
        dataBase.add(p);        
    }
    cout <<filename << " read in ... new size =" << dataBase.getDB_size()<<endl;
}


void process_range(TRAIT trait, string strIn[], int intIn[], ostream & ostr)
{
    set<int> nameRes = dataBase.getNameRange(strIn[0], strIn[1]);
	set<int> heightRes = dataBase.getHeightRange(intIn[0], intIn[1]);
	set<int> weightRes = dataBase.getWeightRange(intIn[2], intIn[3]);
	set<int> beautyRes = dataBase.getBeautyRange(intIn[4], intIn[5]);
	//set<int> intellRes = dataBase.getIntellRange(intIn[6], intIn[7]);

	set<int> results = nameRes*heightRes;
	results = results*weightRes;
	results = results*beautyRes;
	//results = results*intellRes;

		if (trait == NAME)
		{
			multiset<sort_name> sortedResults = dataBase.sortByName(results);
			multiset<sort_name>::iterator start_iter = sortedResults.begin(),
                                      end_iter = sortedResults.end();

			while (start_iter != end_iter)
			{
				Person * p =(*start_iter).person;
				p->print(ostr);
				start_iter++;
			}
		}
		else if (trait == HEIGHT)
		{
			multiset<sort_height> sortedResults = dataBase.sortByHeight(results);
			multiset<sort_height>::iterator start_iter = sortedResults.begin(),
                                      end_iter = sortedResults.end();

			while (start_iter != end_iter)
			{
				Person * p =(*start_iter).person;
				p->print(ostr);
				start_iter++;
			}
		}
		else if (trait == WEIGHT)
		{
			multiset<sort_weight> sortedResults = dataBase.sortByWeight(results);
			multiset<sort_weight>::iterator start_iter = sortedResults.begin(),
                                      end_iter = sortedResults.end();

			while (start_iter != end_iter)
			{
				Person * p =(*start_iter).person;
				p->print(ostr);
				start_iter++;
			}
		}
		else if (trait == BEAUTY)
		{
			multiset<sort_beauty> sortedResults = dataBase.sortByBeauty(results);
			multiset<sort_beauty>::iterator start_iter = sortedResults.begin(),
                                      end_iter = sortedResults.end();

			while (start_iter != end_iter)
			{
				Person * p =(*start_iter).person;
				p->print(ostr);
				start_iter++;
			}
		}
		/*else if (trait == INTELL)
		{
			multiset<sort_intell> sortedResults = dataBase.sortByIntell(results);
			multiset<sort_intell>::iterator start_iter = sortedResults.begin(),
                                      end_iter = sortedResults.end();

			while (start_iter != end_iter)
			{
				Person * p =(*start_iter).person;
				p->print(ostr);
				start_iter++;
			}
		}*/
		else
		{
			set<int>::iterator start_iter=results.begin(),
                           end_iter = results.end();
			while (start_iter != end_iter)
			{
				Person * p = dataBase.getPerson(*start_iter);
				p->print(ostr);
				start_iter++;
			}
		}

}





int main() 
{
    readInFile("men_names.txt", MALE);
    readInFile("women_names.txt", FEMALE);
 
    //while (true)
    //{
    //    try
    //    {
			cout << "Enter the following questions to find your match! (Enter 0 if not important)" << endl;
            //cout << "Enter one of the following commands: n)ames h)eight w)weight a)dd d)delete q)uit "<<endl;
			//string firstName, endName;
			//int first, end;
			string strInput[2], sort;
			int intInput[4];
			cout << "First Name: ";
			cin >> strInput[0];
			if (strInput[0] == "q") return 0;
			cout << endl << "Last Name: ";
			cin >> strInput[1];
			cout << endl << "Shorest Height (cm): ";
			cin >> intInput[0];
			cout << endl << "Tallest Height: ";
			cin >> intInput[1];
			cout << endl << "Lowest Weight: ";
			cin >> intInput[2];
			cout << endl << "Highest Weight: ";
			cin >> intInput[3];
			cout << endl << "Lowest Beauty: ";
			cin >> intInput[4];
			cout << endl << "Highest Beauty: ";
			cin >> intInput[5];
			cout << endl << "Lowest Intelligence: ";
			cin >> intInput[6];
			cout << endl << "Highest Intelligence: ";
			cin >> intInput[7];
			cout << "Sort by? (N)ame, (H)eight, (W)eight, (B)eauty (I)ntelligence - any other key to skip sorting: ";
			cin >> sort;
			cout << endl;

			if (sort[0] == 'N') process_range(NAME, strInput, intInput, cout);
			else if (sort[0] == 'H') process_range(HEIGHT, strInput, intInput, cout);
			else if (sort[0] == 'W') process_range(WEIGHT, strInput, intInput, cout);
			else if (sort[0] == 'B') process_range(BEAUTY, strInput, intInput, cout);
			else if (sort[0] == 'I') process_range(INTELL, strInput, intInput, cout);
			else process_range(SEX, strInput, intInput, cout);
        //}
        //catch (string s)
        //{
        //    cout << "EXCEPTION::::: " << s << endl;
        //}
        
    //}



    return 0;
}