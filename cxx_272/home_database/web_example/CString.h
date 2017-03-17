#include <strstream>
#include <iostream>
using namespace std;
#include <string>
#include <iomanip>                  //for setiosflags()
using namespace std;
#ifndef _CString
#define _CString

class CStringIn
{
public:
    CStringIn(const char * buffer);
    CStringIn(const string & s);
    ~CStringIn();
    istream * getIstream();
    istream & cin();
private:
    void init(const char *buffer);
    int m_size;
    char * m_pBuffer;              //buffer in memory
    istrstream *m_istrstream;  
};

class CStringOut
{
public:
    CStringOut(int buffSize = 0 /* 0 ==> ostrstream allocates as needed*/);
    ~CStringOut();
    ostream * getOstream();
    ostream & cout();
    const char * c_str(bool addEndingZero=true);
private:
    int m_size;
    char * m_pBuffer;              //buffer in memory
    ostrstream *m_ostrstream;  
};
#endif
