// Starting version of MyStream.cpp
//MyStream.h
#define __STREAM_IMPLEMENTATION
#include "MyStream.h"

MyException::MyException (const char *err, 
        const char * filename, int lineNum)
    {
        char cbuff[2000]; // Allocate extra large and then
                          // trim with strdup
        sprintf(cbuff,"%s  FILE=%s  LINENUM=%d", 
            err, filename, lineNum);
        m_ptr = strdup(cbuff);
    }

Myofstream & Myofstream::put(char ch)
    {
        //***** FILL IN CODE **********************
        // use fputc to do the work.  Make sure you check that the 
        // file is open (i.e. m_fp != NULL).  Use THROW for errors
		if (m_fp == NULL)
			THROW ("put called with file not open");
		fputc(ch, m_fp);
        
        return *this; 
    }

Myofstream &Myofstream::write(char * buffer, long writesize)
    {
        //***** FILL IN CODE **********************
        // use fwrite to do the work.  Make sure you check that the 
        // file is open (i.e. m_fp != NULL).  Use THROW for errors
		if (m_fp == NULL)
			THROW ("write called with file not open");
		fwrite(buffer, 1, writesize, m_fp);
        
        return *this;
    }

Myofstream &Myofstream::seekp(long offset, WSEEK_TYPE type)
    {
        //***** FILL IN CODE **********************
        // use fseek to do the work.  Make sure you check that the 
        // file is open (i.e. m_fp != NULL).  Use THROW for errors
            
        return *this;
    }
 
long Myofstream::tellp()
    {
        //***** FILL IN CODE **********************
        // use ftell to do the work.  Make sure you check that the 
        // file is open (i.e. m_fp != NULL).  Use THROW for errors
        
        return 0; // Shouldn't get here ... 
                  // I put this in to keep the compiler happy
    }



Myofstream& operator << (Myofstream& s, char c)
{
    //***** FILL IN CODE **********************
        // use fwrite to do the work.  Make sure you check that the 
        // file is open (i.e. m_fp != NULL).  Use THROW for errors

		if (s.m_fp == NULL)
			THROW ("put called with file not open");
		fputc(c, s.m_fp);
    
    return s;
}


Myofstream& operator << (Myofstream& s, const char *  str)
{
    //***** FILL IN CODE **********************
        // use fwrite to do the work.  Make sure you check that the 
        // file is open (i.e. m_fp != NULL).  Use THROW for errors

	if (s.m_fp == NULL)
			THROW ("put called with file not open");
	int len = strlen(str);
	for (int i=0; i < len; i++)
		fputc(str[i], s.m_fp);
    
    return s;
}

Myofstream& operator << (Myofstream& s, int x)
{
     //***** FILL IN CODE **********************
        // use fprintf to do the work.  Make sure you check that the 
        // file is open (i.e. m_fp != NULL).  Use THROW for errors
	if (s.m_fp == NULL)
			THROW ("put called with file not open");
		fprintf(s.m_fp, "%d", x);
    
    return s;
}



// ****************************************
int Myifstream::get()
    {
         //***** FILL IN CODE **********************
        // use fgetc to do the work.  Make sure you check that the 
        // file is open (i.e. m_fp != NULL).  Use THROW for errors
        // To handle the EOF case, check the character returned from 
        // fgetc as follows:
		if (m_fp == NULL)
			THROW ("get called with file not open");
		char c= fgetc(m_fp);
        if (c == EOF) m_error |= RFLAG_EOF;
       
        return c; 
    }
    
Myifstream &Myifstream::getline(char * buffer, long buffsize)
    {
         //***** FILL IN CODE **********************
        // use fgets to do the work.  Make sure you check that the 
        // file is open (i.e. m_fp != NULL).  Use THROW for errors
        // If fgets returns NULL, then issue the following command
        // to handle the EOF case:
		if (m_fp == NULL)
			THROW ("get called with file not open");
		if (fgets(buffer, buffsize, m_fp) == NULL)
			m_error |= RFLAG_EOF;
        
        return *this;
    }
    
Myifstream &Myifstream::read(char * buffer, long readsize)
    {
        //***** FILL IN CODE **********************
        // use fread to do the work.  Make sure you check that the 
        // file is open (i.e. m_fp != NULL).  Use THROW for errors

        // Don't forget to save the number of bytes read in
        // m_read_count
        // Also if (m_read_count <= 0) m_error |= RFLAG_EOF;
        // This will handle the End of File case

		if (m_fp == NULL)
			THROW ("read called with file not open");
		m_read_count = fread(buffer, 1,readsize, m_fp);

        return *this;
    }
    
long Myifstream::readsome(char * buffer, long readsize)
    {
        m_read_count = 0;
        read(buffer, readsize);
        return m_read_count;
    }
    
Myifstream &Myifstream::seekg(long offset, RSEEK_TYPE type)
    {
        //***** FILL IN CODE **********************
        // use fseek to do the work.  Make sure you check that the 
        // file is open (i.e. m_fp != NULL).  Use THROW for errors        
            
        return *this;
    }
    
long Myifstream::tellg()
    {
        //***** FILL IN CODE **********************
        // use ftell to do the work.  Make sure you check that the 
        // file is open (i.e. m_fp != NULL).  Use THROW for errors  
        
        return *this;
    }

 Myifstream& operator >> (Myifstream& s, char *  str)
 {
     //***** FILL IN CODE **********************
        // use fscanf to do the work.  Make sure you check that the 
        // file is open (i.e. m_fp != NULL).  Use THROW for errors  
	 if (s.m_fp == NULL)
			THROW ("Input called with file not open");
		fscanf(s.m_fp,"%s", str);
   
    return s;
 }
 Myifstream& operator >> (Myifstream& s, int & x)
    {
        //***** FILL IN CODE **********************
        // use fscanf to do the work.  Make sure you check that the 
        // file is open (i.e. m_fp != NULL).  Use THROW for errors 
		if (s.m_fp == NULL)
			THROW ("get called with file not open");
		fscanf(s.m_fp,"%d", &x);
   
    return s;

    }