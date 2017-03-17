// *************************************************
// Socket.h
// *************************************************

#ifndef Socket_class
#define Socket_class

//#define LINUX
#ifdef LINUX
typedef int SOCKET;

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>

#else  // WINDOWS DEFINITIONS
#include <iostream>
using namespace std;
#include <string>
#include <stdio.h>
#include <winsock.h>
static WORD wVersionRequested;
static WSADATA wsaData;
bool oneTimeSocketInitialization();
void socketDeIntialization();

#endif


//    #include "SocketException.h"

const int MAXHOSTNAME = 200;

const int MAXRECV = 4096;


class stringLine: public string
{
};


class stringBuffer: public string
{
};

class ServerSocket;
class ClientSocket;

class Socket
{
public:
    Socket(int buff_size=MAXRECV);
    virtual ~Socket();

    // Server initialization
    bool create();



    // Data Transimission
    Socket&  write(const char * buf, int len);
    Socket&  write ( const string & s );

    int read(char * buf, int len);
    Socket&  get(char &c);
    Socket&  recvNext(string & s, const char * delims);
    Socket&  recvString ( string& );


    // is_valid() tells whether the socket opened properly to start with
    bool is_valid() const ;

    // The m_good flag tracks whether the opened socket seems to have closed. 
    bool good() const { return m_good;}
    operator bool() const
    {
        return m_good;
    }

    // Output definitions
    Socket& operator << ( const string& ) ;  
    Socket& operator << ( const char * cstr ) ;

    // Input definitions
    Socket& operator >> ( string& s ) ;
    Socket& operator >> ( char &c  ) ;
    Socket& operator >> ( stringLine& s) ;   // read a line
    Socket& operator >> ( stringBuffer& s) ; // reads all available

    void set_non_blocking ( const bool );  
    void setContinueBufferReads (bool continueBufferReads);

    friend class ServerSocket; // need to access m_sock and m_addr
    friend class ClientSocket; // need to access m_sock and m_addr

    // similar to getline in string and iostream
    friend Socket& getline(Socket & sock, string & s, const char * delim="\n");



private:

    int  fillBuffer ( ) ;
    bool getNext(string &s, const char * terminator);
    bool m_continueBufferReads;
    char * m_buffer;
    int m_num_in_buffer;
    int m_max_buff_size;
    int m_curr_index;


    SOCKET m_sock;
    bool m_good;
    sockaddr_in m_addr;


};


#endif



// **************************************************
// SocketException.h
// **************************************************


#ifndef SocketException_class
#define SocketException_class

#include <string>
using namespace std;

class SocketException
{
public:
    SocketException ( std::string s ) : m_s ( s ) {};
    ~SocketException (){};

    string description() { return m_s; }

private:

    string m_s;

};

#endif



// ***************************************************
// ClientSocket.h
// ***************************************************

#ifndef ClientSocket_class
#define ClientSocket_class

//   #include "Socket.h"


class ClientSocket : public Socket
{
public:

    ClientSocket ( std::string host, int port );
    virtual ~ClientSocket(){};

    // Client initialization
    bool connect ( const std::string host, const int port );
};


#endif



// ***********************************************
// ServerSocket.h
// ***********************************************

#ifndef ServerSocket_class
#define ServerSocket_class


//   #include "Socket.h"

const int MAXCONNECTIONS = 5;

class ServerSocket : public Socket
{
public:

    ServerSocket ( int port );
    ServerSocket (){};
    virtual ~ServerSocket();

    bool bind ( const int port );
    bool listen() const;
    void accept ( Socket& );
    void runServer(bool multiTask=false, bool debug=false);
    virtual bool  processSocket(Socket & new_sock);
};


#endif



// *********************************************************
// webParms.h 
// *********************************************************

#include <string>
#include <vector>
using namespace std;

class Parm
{
public:
    Parm(string & n, string & v)
    {
        name = n;
        value = v;
    }
    string name;
    string value;

};



class webParms
{
public:
    //
    enum COOKIE_CMDS {SET_COOKIE, DELETE_COOKIE};
    webParms()
    { }
    const vector<Parm> & getParms()
    {
        return m_parms;
    }
    const vector<Parm> & getCookies()
    {
        return m_cookies;
    }

    const vector<Parm> & getHeaders()
    {
        return m_headers;
    }
    void parse(string & sParms);
    void parseOneHeader(string & line);
    void print();
    void setCookie(const char * name, string & value, COOKIE_CMDS=SET_COOKIE);
    void setCookie(string & name, string & value, COOKIE_CMDS=SET_COOKIE);
    string * getCookie(const char * name);
    string * getCookie(string & name);
    string * getParameter(const char * name);
    string * getParameter(string & name);
    string url;
    void encode(string & s);
    void unencode(string & s);

    friend class WebServer;

private:
    void extractCookies();
    void processCookie(string & s);
    string cookieHeader;
    vector<Parm> m_parms;
    vector<Parm> m_headers;
    vector<Parm> m_cookies;
    void processOneParm(string & p);

};



// **************************************************
// WebServer.h
// **************************************************

#ifndef WebServerSocket_class
#define WebServerSocket_class

#include <strstream>

//     #include "ServerSocket.h"
//     #include "webParms.h"

static const int BIG_BUFF_SIZE=1024*32;

class WebServer : public ServerSocket
{
public:

    WebServer ( int port, bool debug=false);

    enum OutputType {TEXT, HTML, HTM, JPEG, JPG, GIF, CPP, H};

    void setHeader (OutputType type);
    void setHeader (string & strType);

    bool  processSocket(Socket & new_sock);
    virtual void  processWebSocket( webParms & parms);
    void write_to_socket(string & s);
    void write_to_socket(const char * cstr);
    void flush();
    Socket & writeBinary(char * buff, int sizeOfBuff);
    int writeFile(const char * filename);
    int writeFile(string & filename);

private:
    webParms *m_p_parms;
    bool m_debug;
    char m_big_buff[BIG_BUFF_SIZE +1];
    int m_curr_in_buff;
    ostrstream *m_p_stream;
    Socket m_sock;
    void sendError(char * err);
    void processHeaders();
};


#endif
