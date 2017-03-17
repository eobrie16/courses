#ifndef _DataBase_h
#define _DataBase_h

#include "DataBaseCore.h"

class sort_name
    {
    public:
        Person * person;
        sort_name(Person *p): person(p)
        {}
        bool operator< (const sort_name & other) const
        {
            return (person->m_name < other.person->m_name);
        }

        bool operator== (const sort_name & other) const
        {
            return (person->m_name == other.person->m_name);
        }
    };


class sort_count
    {
    public:
        Person * person;
        sort_count(Person *p): person(p)
        {}
        bool operator< (const sort_count & other) const
        {
            return (person->m_count < other.person->m_count);
        }
        bool operator== (const sort_count & other) const
        {
            return (person->m_count == other.person->m_count);
        }
    };


class DataBase : public DataBaseCore
{
public:
   // Methods for you to alter
    set<int> getNameRange(string & lowerName, string & upperName);
    set<int> getCountRange(int  lowerCount, int  upperCount);
    multiset<sort_name> sortByName(set<int>);
    multiset<sort_count> sortByCount(set<int>);

    // Leave the following alone

    int add(Person & p);
    
    bool remove(int index);
    
private:
    // Data structures for you to mess with
    multiset<sort_name> sortedNames;
    multiset<sort_count> sortedCounts;
};

#endif