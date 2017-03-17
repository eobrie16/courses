#include <iostream>
#include <string>
using namespace std;

class SString
{
private:
	char * m_ptr;
	void init(const char *p);
public:
	SString();
	SString(char * p);
	SString(string & s);
	~SString();
	const char * c_str();
	void insert(char *thing, int ipos);
};

const char * SString::c_str()
{
	return m_ptr;
}



void SString::init(const char * p)
	{
		int len = strlen(p);
		m_ptr = new char[len+1];
		strcpy(m_ptr, p);
	}

SString::SString(string & s)
{
	init(s.c_str());
}

SString::SString(char *p)
{
	init (p);
}
SString::SString()
{
	init("");
}


SString::~SString()
{
	delete[] m_ptr;
}

void SString::insert(char *thing, int ipos)
{
	int lenBase = strlen(m_ptr);
	int lenThing = strlen(thing);
	char *retstr = new char[lenBase+lenThing+1];
	int count = 0;

	for (int i=0; i < ipos; i++)
		retstr[i] = m_ptr[i];

	for (int i=0; i < lenThing; i++)
		retstr[ipos+i] = thing[i];

	for (int i=0; i < lenBase - ipos; i++)
		retstr[ipos + lenThing + i] = m_ptr[i+ipos];

	retstr[lenBase + lenThing] = 0;
	delete [] m_ptr;
	m_ptr = retstr;
}

int main()
   {
    string str1 = "012345";

	SString s2(str1);
	SString s1("abc");
	SString s3();

	s2.insert("xyz", 2);

	cout << "Answer=" << s2.c_str() << endl;

   return 0;
   }
