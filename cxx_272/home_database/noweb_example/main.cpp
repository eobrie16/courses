
#include <fstream>
#include "DataBase.h"

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
void process_name_range(bool sort_by_name, string & start, string end, ostream & ostr)
{
    set<int> results = dataBase.getNameRange(start, end);
    if (sort_by_name)
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
void process_count_range(bool sort_by_count, int start, int end, ostream & ostr)
{
    set<int> results = dataBase.getCountRange(start, end);
    if (sort_by_count)
    {
        multiset<sort_count> sortedResults = dataBase.sortByCount(results);
        multiset<sort_count>::iterator start_iter = sortedResults.begin(),
                                      end_iter = sortedResults.end();
        while (start_iter != end_iter)
        {
            Person * p =(*start_iter).person;
            p->print(ostr);
            start_iter++;
        }
    }
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
    readInFile("boys_names.txt", MALE);
    readInFile("girls_names.txt", FEMALE);
 
    while (true)
    {
        try
        {
            cout << "Enter one of the following commands: n)ames c)ounts a)dd d)delete q)uit "<<endl;
            char c;
            cin >> c;
            switch (c)
            {
            case 'q':
                return 0;
            case 'n':
                {
                    cout <<"Enter sort(Y/N) firstName endName :"<<endl;
                    string sort, first, end;
                    cin >> sort >> first >> end;
                    if (sort[0] =='Y')
                        process_name_range(true, first, end, cout);
                    else 
                        process_name_range(false, first, end, cout);
                    break;
                }            
            case 'c':
                {
                    cout <<"Enter sort(Y/N) firstCount endCount :"<<endl;
                    int  first, end;
                    string sort;
                    cin >> sort >> first >> end;
                    if (sort[0]=='Y')
                        process_count_range(true, first, end, cout);
                    else
                        process_count_range(false, first, end, cout);
                    break;
                }
            case 'a':
                {
                    cout << "Enter: M/F name  count "<<endl;
                    string gender, name, count;
                    GENDER g;
                    string input;
                    cin >> gender >> name >> count;
                    if (gender[0]=='M') g = MALE;
                    else g=FEMALE;
                    input = name;
                    input += " ";
                    input += count; 
                    cout << "adding " << g<< ":" << input<<endl;
                    Person p(g,input);
                    dataBase.add(p);
                    break;
                }
            case 'd':
                cout << "Enter index to delete:"<<endl;
                int index;
                cin >> index;
                dataBase.remove(index);
                break;
            }
        }
        catch (string s)
        {
            cout << "EXCEPTION::::: " << s << endl;
        }
        
    }



    return 0;
}