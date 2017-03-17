#include <iostream>
using namespace std;
#include "Mystr.h"

char * Mystr::strdup(char * s)
{
	int len = strlen(s);
	char * retval = new char[len+1];
	strcpy(retval, s);
	return retval;
}
int Mystr::length()
{
	return m_len;
}

Mystr::Mystr(char * s)
{
	m_ptr = strdup(s);
	m_len = strlen(m_ptr);
}
Mystr::~Mystr()
{
	delete[] m_ptr;
}
Mystr::Mystr( Mystr & m) // copy constructor
{
	m_ptr = strdup(m.m_ptr);
	m_len = strlen(m_ptr);
}
Mystr::Mystr(int len, char a[])
{
	m_ptr = new char[len+1];
	m_len = len;
	for (int i=0; i < len; i++)
		m_ptr[i] = a[i];
	m_ptr[len] = 0;
}

Mystr::operator const char *()
{
	return m_ptr;
}

void Mystr::insertAt(int insertPos, const char *arr2)
{
	int len1 = m_len;
	char * arr1 = m_ptr;

	int len2 = (int)strlen (arr2);
	char * temp ;
	m_len = len1 + len2;
	temp = new char[m_len+1];

	for(int i=0; i < insertPos; i++)
		temp[i] = arr1[i];
	for (int i=0;  i <len2; i++)
		temp[insertPos +i] = arr2[i];
	for (int i= insertPos; i < len1; i++)
		 temp[i +len2  ]= arr1[i]; 

	temp[len1+len2] = 0;
	
	delete[] m_ptr;
	m_ptr = temp;
	

}

void Mystr::concat( const char * s)
{
	insertAt(m_len, s);
}
  
Mystr Mystr::operator + (Mystr & s)
{
	Mystr retval(m_ptr);
	const char * temp = s;
	retval.concat(temp);
	return retval;
}

Mystr & Mystr::operator= (const Mystr & s)
{
	delete[] m_ptr;
	m_ptr = strdup(s.m_ptr);
	m_len = s.m_len;
	return *this;
}
