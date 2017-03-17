class Mystr
{
    char * m_ptr;
    int m_len;
	char * strdup(char * s);


public:

    Mystr(char * s="");
    ~Mystr();
    Mystr( Mystr & m); // copy constructor
  
    Mystr(int len, char a[]);

	Mystr & operator= (const Mystr & s);

    void concat( const char *);
    operator const char *();

    Mystr operator + (Mystr & s);
    void  operator += (const Mystr & op);
    char & operator [] (int n);
    int length();
   // int find (const char *s);
    void insertAt(int index, const char *s);
    //void delete(int start, int numChars=1);
    //void replace(int start, int numChars, const char *s);
    bool operator == (Mystr & m);
    bool operator < (Mystr & m);
};
