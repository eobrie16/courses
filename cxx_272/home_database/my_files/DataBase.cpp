#include "DataBase.h"
 
DataBase dataBase;


// ************************************
int DataBase::add(Person & p)
{
    int index = DataBaseCore::add(p);
    Person * p_person = m_data[index];
    p_person->m_index = index;

    // Your code to add
    sort_name sn(p_person);
    sort_height sc(p_person);
	sort_weight sw(p_person);
	sort_beauty sb(p_person);
	//sort_intell si(p_person);
    sortedNames.insert(sn);
    sortedHeights.insert(sc);
	sortedWeights.insert(sw);
	sortedBeauties.insert(sb);
	//sortedIntells.insert(si);
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

    sort_height sc(p_person);

    pair<multiset<sort_height>::iterator, multiset<sort_height>::iterator> p2;
    p2=sortedHeights.equal_range(sc);
    
    while (p2.first != p2.second)
    {
        if ( (*p2.first).person == p_person)
           sortedHeights.erase(p2.first++);
        else
            p2.first++;
    }
    return DataBaseCore::remove(index);
    
}

set<int> DataBase::getNameRange(string & lowerName, string & upperName)
{
    if (upperName < lowerName)
        throw string("DataBase.getNameRange:  upperName is < lowerName");

    Person lower(lowerName, 1, FEMALE);
    Person upper(upperName, 1, FEMALE);
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
set<int> DataBase::getHeightRange(int  lowerHeight, int  upperHeight)
{
    if (upperHeight < lowerHeight)
        throw string("DataBase.getHeightRange::: upperHeight < lowerHeight");

    Person lower(string(""), lowerHeight, FEMALE);
    Person upper(string(""), upperHeight, FEMALE);
    Person * p_lower = &lower, *p_upper = &upper;
   
    sort_height sh_lower(p_lower);
    sort_height sh_upper(p_upper);
    multiset<sort_height>::iterator iterBeg = sortedHeights.lower_bound(sh_lower);
    multiset<sort_height>::iterator iterEnd = sortedHeights.upper_bound(sh_upper);
    
    
    set<int> retSet;
    while(iterBeg != iterEnd)
    {
        int index = (*iterBeg).person->m_index;
        retSet.insert(index);
        iterBeg++;
    }
    return retSet;
} 

set<int> DataBase::getWeightRange(int  lowerWeight, int  upperWeight)
{
    if (upperWeight < lowerWeight)
        throw string("DataBase.getWeightRange::: upperWeight < lowerWeight");

    Person lower(string(""), lowerWeight, WEIGHT, FEMALE);
    Person upper(string(""), upperWeight, WEIGHT, FEMALE);
    Person * p_lower = &lower, *p_upper = &upper;
   
    sort_weight sh_lower(p_lower);
    sort_weight sh_upper(p_upper);
    multiset<sort_weight>::iterator iterBeg = sortedWeights.lower_bound(sh_lower);
    multiset<sort_weight>::iterator iterEnd = sortedWeights.upper_bound(sh_upper);
    
    
    set<int> retSet;
    while(iterBeg != iterEnd)
    {
        int index = (*iterBeg).person->m_index;
        retSet.insert(index);
        iterBeg++;
    }
    return retSet;
} 

set<int> DataBase::getBeautyRange(int  lowerBeauty, int  upperBeauty)
{
    if (upperBeauty < lowerBeauty)
        throw string("DataBase.getWeightRange::: upperWeight < lowerWeight");

    Person lower(string(""), lowerBeauty, BEAUTY, FEMALE);
    Person upper(string(""), upperBeauty, BEAUTY, FEMALE);
    Person * p_lower = &lower, *p_upper = &upper;
   
    sort_beauty sh_lower(p_lower);
    sort_beauty sh_upper(p_upper);
    multiset<sort_beauty>::iterator iterBeg = sortedBeauties.lower_bound(sh_lower);
    multiset<sort_beauty>::iterator iterEnd = sortedBeauties.upper_bound(sh_upper);
    
    
    set<int> retSet;
    while(iterBeg != iterEnd)
    {
        int index = (*iterBeg).person->m_index;
        retSet.insert(index);
        iterBeg++;
    }
    return retSet;
} 

/*set<int> DataBase::getIntellRange(int  lowerIntell, int  upperIntell)
{
    if (upperIntell < lowerIntell)
        throw string("DataBase.getIntellRange::: upperIntell < lowerIntell");

    Person lower(string(""), lowerIntell, INTELL, FEMALE);
    Person upper(string(""), upperIntell, INTELL, FEMALE);
    Person * p_lower = &lower, *p_upper = &upper;
   
    sort_intell sh_lower(p_lower);
    sort_intell sh_upper(p_upper);
    multiset<sort_intell>::iterator iterBeg = sortedIntells.lower_bound(sh_lower);
    multiset<sort_intell>::iterator iterEnd = sortedIntells.upper_bound(sh_upper);
    
    
    set<int> retSet;
    while(iterBeg != iterEnd)
    {
        int index = (*iterBeg).person->m_index;
        retSet.insert(index);
        iterBeg++;
    }
    return retSet;
} */

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

multiset<sort_height> DataBase::sortByHeight(set<int>  stuff2Sort)
{
    multiset<sort_height> results;
    set<int>::iterator start_iter= stuff2Sort.begin(),
                       end_iter = stuff2Sort.end();
    while(start_iter != end_iter)
    {   
        sort_height sc(m_data[*start_iter]);
        results.insert(sc);
        start_iter++;
    }
    return results;
}

multiset<sort_weight> DataBase::sortByWeight(set<int>  stuff2Sort)
{
    multiset<sort_weight> results;
    set<int>::iterator start_iter= stuff2Sort.begin(),
                       end_iter = stuff2Sort.end();
    while(start_iter != end_iter)
    {   
        sort_weight sc(m_data[*start_iter]);
        results.insert(sc);
        start_iter++;
    }
    return results;
}

multiset<sort_beauty> DataBase::sortByBeauty(set<int>  stuff2Sort)
{
    multiset<sort_beauty> results;
    set<int>::iterator start_iter= stuff2Sort.begin(),
                       end_iter = stuff2Sort.end();
    while(start_iter != end_iter)
    {   
        sort_beauty sc(m_data[*start_iter]);
        results.insert(sc);
        start_iter++;
    }
    return results;
}

/*multiset<sort_intell> DataBase::sortByIntell(set<int>  stuff2Sort)
{
    multiset<sort_intell> results;
    set<int>::iterator start_iter= stuff2Sort.begin(),
                       end_iter = stuff2Sort.end();
    while(start_iter != end_iter)
    {   
        sort_intell sc(m_data[*start_iter]);
        results.insert(sc);
        start_iter++;
    }
    return results;
}*/