#include "DataBaseCore.h"

int DataBaseCore::add(Person & p)
{
    int index;
    if (!empty_entries.empty())
    {
        index = empty_entries.top();
        empty_entries.pop();
        m_data[index] = new Person(p);
    }
    else
    {
        index = m_data.size();
        m_data.push_back(new Person(p));
    }
    Person * p_person = m_data[index];
    p_person->m_index = index;
   
    return index;
}

bool DataBaseCore::remove(int index)
{
    if (index < 0 || index >= m_data.size())
        throw string("DataBaseCore.remove index out of bounds");
    if (m_data[index]==NULL) 
        throw string("DataBaseCore.remove this entry already removed");  
   
    delete m_data[index];
    m_data[index] = NULL; // Mark as unused
    empty_entries.push(index);
    return true;
}


DataBaseCore::~DataBaseCore()
{
    cout << "Cleaning up resources from database " << endl;
    for (int i=0; i < m_data.size(); i++)
    {
        if (m_data[i] != NULL) 
            delete m_data[i];
    }
}

Person * DataBaseCore::getPerson(int index)
{
    if (index < 0 || index >= m_data.size())
        throw string("DataBase.getPerson index out of bounds");
    if (m_data[index] == NULL)
        throw string("DataBase.getPerson index is NULL");

    return m_data[index];
}

