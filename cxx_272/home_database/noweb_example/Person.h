#ifndef _Person_h
#define _Person_h
enum GENDER {MALE, FEMALE};

class Person
{
public:
    int m_index;
    string m_name;
    int m_count;
    GENDER m_gender;
    Person(GENDER gender, string & inputLine)
    {
        m_gender = gender;
        CStringIn buff(inputLine);
        istream * istr = buff.getIstream();
        *istr >> m_name;
        *istr >>m_count;
    }
    Person (string & name, int count, GENDER gender):
        m_name(name), m_count(count), m_gender(gender)
        {}
        Person(const Person & p):
        m_name(p.m_name), m_count(p.m_count), m_gender(p.m_gender), m_index(p.m_index)
        {}
    void print(ostream & ostr)
    {
        ostr <<"Name="<< m_name <<" \tcount="<<m_count<<" \tgender="<<m_gender<<" \tindex="<<m_index<<endl;
    }
};

#endif