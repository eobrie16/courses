#include "CString.h"
// **********************************************
// CStringIn routines
// **********************************************

istream * CStringIn::getIstream()
{
    return m_istrstream;
}
istream & CStringIn::cin()
{
    return *m_istrstream;
}

void CStringIn::init(const char *buffer)
{
    m_pBuffer = strdup(buffer);
    m_size = strlen(m_pBuffer);    
    m_istrstream = new istrstream(m_pBuffer, m_size);
}
CStringIn::CStringIn(const char *buffer)
{
    init(buffer);    
}
CStringIn::~CStringIn()
{
    delete m_istrstream;
    delete m_pBuffer;
}
CStringIn::CStringIn(const string & s)
{
    init(s.c_str());
}



// **********************************************
// CStringOut routines
// **********************************************

CStringOut::CStringOut(int buffSize)
{
    m_size = buffSize;
    if (m_size == 0)
    {
        m_ostrstream = new ostrstream;
        m_pBuffer = NULL;
    }
    else
    {
        m_pBuffer = new char[buffSize];
        m_ostrstream = new ostrstream(m_pBuffer, m_size);
    }
}


CStringOut::~CStringOut()
{
    delete m_ostrstream;
    if (m_pBuffer != NULL) delete[] m_pBuffer;
}

ostream * CStringOut::getOstream()
{
    return m_ostrstream;
}
ostream & CStringOut::cout()
{
    return *m_ostrstream;
}

const char * CStringOut::c_str(bool addEndingZero)
{
    if (addEndingZero)
        *m_ostrstream <<  ends;
    if (m_pBuffer != NULL)
        return m_pBuffer;
    else
    {
        return m_ostrstream->str();

    }
}
