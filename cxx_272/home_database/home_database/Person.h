#ifndef _Person_h
#define _Person_h
enum GENDER {MALE, FEMALE};
enum TRAIT {NAME, HAIR, EYES, HEIGHT, WEIGHT, BEAUTY, INTELL, SEX};

class Person
{
public:
    int m_index;
    string m_name;
	string m_hair;
	string m_eyes;
    int m_height;
	int m_weight;
	int m_beauty;
	int m_intell;
    GENDER m_gender;
    Person(GENDER gender, string & inputLine)
    {
        m_gender = gender;
        CStringIn buff(inputLine);
        istream * istr = buff.getIstream();
        *istr >> m_height;
        *istr >> m_weight;
		*istr >> m_beauty;
		*istr >> m_intell;
		*istr >> m_hair;
		*istr >> m_eyes;
		*istr >> m_name;
    }
    Person (string & text, int number, TRAIT trait, GENDER gender)
	{
		if (trait == NAME) m_name = text;
		else if (trait == HAIR) m_hair = text;
		else if (trait == EYES) m_eyes = text;
		else if (trait == HEIGHT) m_height = number;
		else if (trait == WEIGHT) m_weight = number;
		else if (trait == BEAUTY) m_beauty = number;
		else if (trait == INTELL) m_intell = number;
 		m_gender = gender;
	}
	Person (string & text, int number, GENDER gender)
	{
		m_name = text;
		m_height = number;
 		m_gender = gender;
	}
	Person(const Person & p)
	{
		m_name = p.m_name;
		m_height = p.m_height;
		m_gender = p.m_gender;
		m_weight = p.m_weight;
		m_beauty = p.m_beauty;
		m_intell = p.m_intell;
		m_hair = p.m_hair;
		m_eyes = p.m_eyes;
	}
        
    void print(ostream & ostr)
    {
        ostr <<"Name="<< m_name <<" \theight="<<m_height<<" \tweight="<<m_weight<<"\tgender="<<m_gender<<endl;
		ostr <<"Hair="<<m_hair<<" \tEyes="<<m_eyes<<" \tbeauty="<<m_beauty<<" \tintell="<<m_intell<<endl;
    }
};

#endif