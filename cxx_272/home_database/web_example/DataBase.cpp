#include "DataBase.h"
 
DataBase dataBase; 

int DataBase::add(Person & p)
{
    int index = DataBaseCore::add(p);
    Person * p_person = m_data[index];
    p_person->m_index = index;

    // Your code to add
    sort_name sn(p_person);
    sort_count sc(p_person);
    sortedNames.insert(sn);
    sortedCounts.insert(sc);
    return index;
}


bool DataBase::remove(int index)
{
    if (index < 0 || index >= m_data.size())
        throw string("DataBase.remove index out of bounds");
    if (m_data[index]==NULL) 
        throw string("DataBase.remove this entry already removed");  
    
    
    Person * p_person = m_data[index];

    //Remove from sortedNames
    sort_name sn(p_person);

    pair<multiset<sort_name>::iterator, multiset<sort_name>::iterator> p;
    p=sortedNames.equal_range(sn);
    
    while (p.first != p.second)
    {
        if ( (*p.first).person == p_person)
           sortedNames.erase(p.first++);
        else
            p.first++;
    }
    
    // Remove from sortedCounts

    sort_count sc(p_person);

    pair<multiset<sort_count>::iterator, multiset<sort_count>::iterator> p2;
    p2=sortedCounts.equal_range(sc);
    
    while (p2.first != p2.second)
    {
        if ( (*p2.first).person == p_person)
           sortedCounts.erase(p2.first++);
        else
            p2.first++;
    }
    return DataBaseCore::remove(index);
    
}

set<int> DataBase::getNameRange(string & lowerName, string & upperName)
{
    if (upperName < lowerName)
        throw string("DataBase.getNameRange:  upperName is < lowerName");

    Person lower(lowerName, 0, FEMALE);
    Person upper(upperName, 0, FEMALE);
    Person * p_lower = &lower, *p_upper = &upper;
    if (lowerName.size() == 0)
    {
        multiset<sort_name>::iterator iter = sortedNames.begin();
        p_lower = (*iter).person;
    }
    if (upperName.size() == 0)
    {
        multiset<sort_name>::iterator iter = sortedNames.end();
        iter--;
        p_upper = (*iter).person;
    }
    sort_name sn_lower(p_lower);
    sort_name sn_upper(p_upper);
    multiset<sort_name>::iterator iterBeg = sortedNames.lower_bound(sn_lower);
    multiset<sort_name>::iterator iterEnd = sortedNames.upper_bound(sn_upper);
    
    
    set<int> retSet;
    while(iterBeg != iterEnd)
    {
        int index = (*iterBeg).person->m_index;
        retSet.insert(index);
        iterBeg++;
    }
    return retSet;
}
set<int> DataBase::getCountRange(int  lowerCount, int  upperCount)
{
    if (upperCount < lowerCount)
        throw string("DataBase.getCountRange::: upperCount < lowerCount");

    Person lower(string(""), lowerCount, FEMALE);
    Person upper(string(""), upperCount, FEMALE);
    Person * p_lower = &lower, *p_upper = &upper;
   
    sort_count sc_lower(p_lower);
    sort_count sc_upper(p_upper);
    multiset<sort_count>::iterator iterBeg = sortedCounts.lower_bound(sc_lower);
    multiset<sort_count>::iterator iterEnd = sortedCounts.upper_bound(sc_upper);
    
    
    set<int> retSet;
    while(iterBeg != iterEnd)
    {
        int index = (*iterBeg).person->m_index;
        retSet.insert(index);
        iterBeg++;
    }
    return retSet;
} 

multiset<sort_name> DataBase::sortByName(set<int> stuff2Sort)
{
    multiset<sort_name> results;
    set<int>::iterator start_iter= stuff2Sort.begin(),
                       end_iter = stuff2Sort.end();
    while(start_iter != end_iter)
    {   
        sort_name sn(m_data[*start_iter]);
        results.insert(sn);
        start_iter++;
    }
    return results;
}

multiset<sort_count> DataBase::sortByCount(set<int>  stuff2Sort)
{
    multiset<sort_count> results;
    set<int>::iterator start_iter= stuff2Sort.begin(),
                       end_iter = stuff2Sort.end();
    while(start_iter != end_iter)
    {   
        sort_count sc(m_data[*start_iter]);
        results.insert(sc);
        start_iter++;
    }
    return results;
}