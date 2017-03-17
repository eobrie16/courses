#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <set>
#include <stack>

#include "CString.h"
#include "Person.h"

#ifndef _DataBaseCore_h
#define _DataBaseCore_h

class DataBaseCore
{
public:   
    // Leave the following alone

     ~DataBaseCore();
    int add(Person & p);
    int getDB_size()
    {
        return m_data.size();
    }
    bool remove(int index);
    Person * getPerson(int index);
    
protected:   
    // Leave these data structures alone
    vector<Person*> m_data;
private:
    stack<int> empty_entries;
};

#endif