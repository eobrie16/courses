
#include "DataBaseCore.h"

#ifndef _DataBase_h
#define _DataBase_h
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


class sort_height
    {
    public:
        Person * person;
        sort_height(Person *p): person(p)
        {}
        bool operator< (const sort_height & other) const
        {
            return (person->m_height < other.person->m_height);
        }
        bool operator== (const sort_height & other) const
        {
            return (person->m_height == other.person->m_height);
        }
    };

class sort_weight
    {
    public:
        Person * person;
        sort_weight(Person *p): person(p)
        {}
        bool operator< (const sort_weight & other) const
        {
            return (person->m_weight < other.person->m_weight);
        }
        bool operator== (const sort_weight & other) const
        {
            return (person->m_weight == other.person->m_weight);
        }
    };

class sort_beauty
    {
    public:
        Person * person;
        sort_beauty(Person *p): person(p)
        {}
        bool operator< (const sort_beauty & other) const
        {
            return (person->m_beauty < other.person->m_beauty);
        }
        bool operator== (const sort_beauty & other) const
        {
            return (person->m_beauty == other.person->m_beauty);
        }
    };

/*class sort_intell
    {
    public:
        Person * person;
        sort_intell(Person *p): person(p)
        {}
        bool operator< (const sort_intell & other) const
        {
            return (person->m_intell < other.person->m_intell);
        }
        bool operator== (const sort_intell & other) const
        {
            return (person->m_intell == other.person->m_intell);
        }
    };*/


class DataBase : public DataBaseCore
{
public:
   // Methods for you to alter
    set<int> getNameRange(string & lowerName, string & upperName);
    set<int> getHeightRange(int  lowerCount, int  upperCount);
	set<int> getWeightRange(int  lowerCount, int  upperCount);
	set<int> getBeautyRange(int  lowerCount, int  upperCount);
	//set<int> getIntellRange(int  lowerCount, int  upperCount);
    multiset<sort_name> sortByName(set<int>);
    multiset<sort_height> sortByHeight(set<int>);
	multiset<sort_weight> sortByWeight(set<int>);
	multiset<sort_beauty> sortByBeauty(set<int>);
	//multiset<sort_intell> sortByIntell(set<int>);

    // Leave the following alone

    int add(Person & p);
    
    bool remove(int index);
    
private:
    // Data structures for you to mess with
    multiset<sort_name> sortedNames;
    multiset<sort_height> sortedHeights;
	multiset<sort_weight> sortedWeights;
	multiset<sort_beauty> sortedBeauties;
	//multiset<sort_intell> sortedIntells;
};

#endif