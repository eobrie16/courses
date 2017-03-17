//MyStream.h

#include <stdio.h>
#include <string.h>

#ifndef _MyStream
#define _MyStream

#define THROW(x) throw MyException(x, __FILE__, __LINE__)

class MyException
{
    char *m_ptr;
public:
    ~MyException()
    {
        delete m_ptr;
    }
    MyException(const char * err)
    {
        m_ptr = strdup(err); // strdup allocates new memory and 
                             // copies in err
    }

    MyException(MyException & e) // Copy Constructor
    {
        m_ptr = strdup(e.m_ptr);
    }
    MyException (const char *err, 
        const char * filename, int lineNum);
    const char * getError()
    {
        return m_ptr;
    }
};

// Legal Seek Types
enum WSEEK_TYPE {WBEG, WCUR, WEND};

const int WFLAG_FAIL=0x0002;

class Myofstream
{
public:
    Myofstream(): m_fp(NULL), m_error(WFLAG_FAIL)
    {
        // You need to clear m_error flag when file opens properly
    }
    Myofstream(const char * filename): m_fp(NULL), m_error(WFLAG_FAIL)
    {
        if (filename != NULL)
            open(filename);
        else m_fp = stdout;
    }
    void open(const char * filename)
    {
        m_fp = fopen(filename, "w");
        if (m_fp != NULL) m_error = 0;
        else 
            THROW ("Unable to open File ");
    }
    bool good()const
    {
        if (m_error == 0) return true;
        return false;
    }
    operator bool()
    {
        return good();
    }
    ~Myofstream()
    {
        if (m_fp != NULL) fclose(m_fp);        
    }
    Myofstream & put(char ch);
    Myofstream &write(char * buffer, long writesize);
    Myofstream &seekp(long offset, WSEEK_TYPE type=WBEG);
    long tellp();
    
    friend Myofstream& operator << (Myofstream& s, char c); 
    friend Myofstream& operator << (Myofstream& s, int x);  
    friend Myofstream& operator << (Myofstream& s, const char *  c); 
   
private:
    FILE *m_fp;
    long m_error;
};


// ****************************************
enum RSEEK_TYPE {RBEG, RCUR, REND};

const int RFLAG_EOF =0x0001;
const int RFLAG_FAIL=0x0002;

class Myifstream
{
public:
    Myifstream():m_read_count(0), m_fp(NULL), m_error(RFLAG_FAIL)
    {
        // You need to clear m_error flag when file opens properly
    }
    Myifstream(const char * filename):m_read_count(0), m_fp(NULL), m_error(RFLAG_FAIL)
    {
        if (filename != NULL)
            open(filename);
        else m_fp = stdin;
    }
    void open(const char * filename)
    {
        m_fp = fopen(filename, "r");
        if (m_fp != NULL) m_error = 0;
        else
            THROW ("Unable to open file for reading ");
    }
    bool good()const
    {
        if (m_error == 0) return true;
        return false;
    }
    bool eof()const
    {
        if (m_error & RFLAG_EOF) return true;
        return false;
    }
    operator bool()
    {
        return good();
    }
    ~Myifstream()
    {
        if (m_fp != NULL) fclose(m_fp);        
    }
    long gcount()const
    {
        return m_read_count;
    }
    int get();
    Myifstream &getline(char * buffer, long buffsize);
    Myifstream &read(char * buffer, long readsize);
    long readsome(char * buffer, long readsize);
    Myifstream &seekg(long offset, RSEEK_TYPE type=RBEG);
    long tellg();
    friend Myifstream& operator >> (Myifstream& s, char *  c);
    friend Myifstream& operator >> (Myifstream& s, int & x);
private:
    FILE *m_fp;
    long m_read_count;
    long m_error;
};

#ifdef __STREAM_IMPLEMENTATION
    Myifstream Myin(NULL);
    Myofstream Myout(NULL);
#else
    extern Myifstream Myin;
    extern Myofstream Myout;
#endif __STREAM_IMPLEMENTATION

#endif _MyStream

