#include "WebServerInc.h"

// *************************************************
// Socket.cpp
// *************************************************


//     #include "Socket.h"


const char * NEW_LINE="\n";
const char * NEW_TOKEN=" \t\n";

#ifdef LINUX
bool oneTimeSocketInitialization()
{
    return true;
}

void socketDeIntialization()
{
}
#else
bool oneTimeSocketInitialization()
{
    wVersionRequested = MAKEWORD(1,1);
    int nRet = WSAStartup(wVersionRequested, &wsaData);
    if (wsaData.wVersion != wVersionRequested)
    {
        fprintf(stderr,"\n Wrong version\n");
        return false;
    }
    return true;
}

void socketDeIntialization()
{
    WSACleanup();
}
#endif


Socket::Socket(int buff_size) :
m_sock ( -1 ), m_num_in_buffer(0), m_curr_index(0), m_max_buff_size(buff_size), m_good(true), m_continueBufferReads(true)
{
    m_buffer = new char[buff_size+1];
    memset ( &m_addr,       0,  sizeof ( m_addr ) );

}

bool Socket::is_valid() const 
{ 
    return m_sock != -1; 
}

Socket::~Socket()
{
    delete(m_buffer);
    if ( is_valid() )
#ifdef LINUX
        ::close ( m_sock );
#else
        closesocket(m_sock);
#endif
}

bool Socket::create()
{
    m_sock = socket ( AF_INET,
        SOCK_STREAM,
        0 );

    if ( ! is_valid() )
        return false;

    //set_non_blocking ( false );
    // TIME_WAIT - argh
    int on = 1;
    if ( setsockopt ( m_sock, SOL_SOCKET, SO_REUSEADDR, 
        ( const char* ) &on, sizeof ( on ) ) == -1 )
        return false;


    return true;

}




Socket& Socket::write(const char * buff, int len) 
{
    //int status = ::send ( m_sock, buff, len, MSG_NOSIGNAL );
    int num_written = 0;
    if (len > 0)
    {
#ifdef LINUX
        num_written = ::write ( m_sock, buff, len );
#else
        num_written = send ( m_sock, buff, len, 0 );
#endif
        if (num_written <= 0) m_good = false;
        if (num_written < 0) 
            throw SocketException ( "Socket::send  - Could not write to socket." );
    }
    return *this;
}

Socket&  Socket::write ( const string & s ) 
{
    write( s.c_str(), s.size() );
    return *this;
}

int Socket::read(char * buf, int len)
{
    int status = 0;
    if (len > 0)
    {
#ifdef LINUX
        status =  ::read ( m_sock, buf, len );
#else
        status = recv(m_sock, buf, len, 0);
#endif
        if (status <= 0) m_good = false;
    }

    if (status < 0)
    {
        throw SocketException ( "Socket::readBytes - Could not read from socket." );
    }
    return status;
}

int Socket::fillBuffer ( ) 
{
    memset ( m_buffer, 0, m_max_buff_size+1);
    return  read ( m_buffer, m_max_buff_size );

}



bool Socket::getNext(string &s, const char * delims)
{
    bool nextFound=false;
    int index = m_curr_index;

    // If there are no terminators, we don't need to look ....
    //     just grab what's in the buffer and run.
    if (delims[0] == 0)
        index = m_num_in_buffer;

    for ( ; index < m_num_in_buffer; index++)
    {
        int tindex=0;
        while (delims[tindex] != 0)
        {
            if (m_buffer[index] == delims[tindex])
            {
                nextFound=true;
                break;
            }
            tindex +=1;
        }
        if (nextFound) break;
    }

    m_buffer[index] = '\0';
    if (index > 0)
        if (m_buffer[index-1] == '\r')
            m_buffer[index-1] ='\0'; // Trim trailing carriage returns
    s += &m_buffer[m_curr_index];
    m_curr_index = index+1;

    if (s.size() > 0) return true;
    return false;
}



// Assumption that line is found within the m_max_buff_size



void Socket::setContinueBufferReads (bool continueBufferReads)
{
    m_continueBufferReads= continueBufferReads;
}

Socket&  Socket::recvNext( string& s, const char * delims) 
{
    int status=0;
    bool nextFound=false;
    s = "";

    if (m_curr_index < m_num_in_buffer)
        nextFound = getNext(s, delims);
    if (!nextFound)
    {
        status = 0;
        if (m_continueBufferReads)
            status = fillBuffer();
        if (status <= 0) 
        {
            m_good = false;
            return *this;
        }

        m_curr_index = 0;
        m_num_in_buffer = status;
        getNext(s, delims);
    }
    return *this;
}


Socket&  Socket::recvString( string& s) 
{
    // The following will take whatever is in the buffer +
    // the next packet read.
    return recvNext(s, ""); // No terminators
}

Socket &  Socket::get(char & c ) 
{  
    c=-1;
    if (m_curr_index < m_num_in_buffer)
        c = m_buffer[m_curr_index++];
    else
    {    
        int status = 0;
        if (m_continueBufferReads)
            status = fillBuffer();
        if (status <= 0) 
            return *this;

        m_curr_index = 0;
        m_num_in_buffer = status;
        c = m_buffer[m_curr_index++];
    }
    return *this;
}





Socket& Socket::operator << ( const string& s ) 
{
    return write ( s );

}

Socket& Socket::operator << ( const char * cstr ) 
{
    return write ( cstr, strlen(cstr) );

}


Socket& Socket::operator >> ( stringBuffer& s ) 
{
    return recvString ( s );
}


Socket& Socket::operator >> ( char & c ) 
{
    return get(c);
}


Socket& Socket::operator >> ( string& s ) 
{
    return recvNext ( s, NEW_TOKEN );
}

Socket& Socket::operator >> ( stringLine& s ) 
{
    return recvNext ( s , NEW_LINE);
}

Socket & getline(Socket & sock, string & s, const char * delim)
{
    sock.recvNext(s, delim);
    return sock;
}





void Socket::set_non_blocking ( const bool b )
{
#ifdef LINUX
    /*
    int ioctl_flag=1;
    if (ioctl(m_sock, FIONBIO, &ioctl_flag) < 0)
    perror("ioctl err");
    */
    int opts;

    opts = fcntl ( m_sock,
        F_GETFL );

    if ( opts < 0 )
    {
        return;
    }

    if ( b )
        opts = ( opts | O_NONBLOCK );
    else
        opts = ( opts & ~O_NONBLOCK );

    fcntl ( m_sock,
        F_SETFL,opts );
#endif

}


// ****************************************************
// ClientSocket.cpp
// ****************************************************


//        #include "ClientSocket.h"
#include <strstream>


ClientSocket::ClientSocket ( std::string host, int port )
{
    if ( ! Socket::create() )
    {
        throw SocketException ( "Could not create client socket." );
    }

    connect ( host, port );

}




bool ClientSocket::connect ( const std::string host, const int port )
{
    if ( ! is_valid() ) return false;
    // ------------------------------------
    struct hostent *hp;
    hp = gethostbyname(host.c_str());
    if (hp == NULL)
    {
        string err="UNKNOWN HOST: " ;
        err += host;
        throw SocketException(err);
    }
    //------------------------------------
    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons ( port );
    memcpy(&m_addr.sin_addr, hp->h_addr, hp->h_length);
    //  int status = inet_pton ( AF_INET, host.c_str(), &m_addr.sin_addr );

    //if ( errno == EAFNOSUPPORT ) return false;


    int status = ::connect ( m_sock, ( sockaddr * ) &m_addr, sizeof ( m_addr ) );

    if ( status >= 0 )
        return true;
    else
    {
        char membuff[200];              //memory for ostrstream
        ostrstream omem(membuff, sizeof(membuff) );
        omem <<  "ClientSocket:connect - Can't connect to:" 
            <<host << ":" << port << ends ; //ends terminates string with 0 
        string err = membuff;
        throw SocketException ( err );    
    }
}




// **********************************************************
// ServerSocket.cpp
// **********************************************************


//      #include "ServerSocket.h"



ServerSocket::ServerSocket ( int port )
{
    if ( ! Socket::create() )
    {
        throw SocketException ( "Could not create server socket." );
    }

    if ( ! bind ( port ) )
    {
        throw SocketException ( "Could not bind to port." );
    }

    if ( ! listen() )
    {
        throw SocketException ( "Could not listen to socket." );
    }

}

ServerSocket::~ServerSocket()
{
}

void ServerSocket::accept ( Socket& new_socket )
{
    int addr_length = sizeof ( m_addr );
#ifdef LINUX
    new_socket.m_sock = ::accept ( m_sock, ( sockaddr * ) &m_addr, ( socklen_t * ) &addr_length );
#else
    new_socket.m_sock = ::accept ( m_sock, NULL , NULL); 
#endif
    if ( !new_socket.is_valid() )
    {
        throw SocketException ( "Could not accept socket." );
    }
}





bool ServerSocket::bind ( const int port )
{

    if ( ! is_valid() )
    {
        return false;
    }



    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = INADDR_ANY;
    m_addr.sin_port = htons ( port );

    int bind_return = ::bind ( m_sock,
        ( struct sockaddr * ) &m_addr,
        sizeof ( m_addr ) );


    if ( bind_return == -1 )
    {
        return false;
    }

    return true;
}


bool ServerSocket::listen() const
{
    if ( ! is_valid() )
    {
        return false;
    }

    int listen_return = ::listen ( m_sock, MAXCONNECTIONS );


    if ( listen_return == -1 )
    {
        return false;
    }

    return true;
}







void ServerSocket::runServer(bool multiTask, bool debug)
{
    // multiTask boolean not implemented yet

    while ( true )
    {

        Socket new_sock;
        accept ( new_sock );
        if (debug)
            cout <<"New Socket" << endl;
#ifdef LINUX
        if (multiTask)
        {
            if (fork() > 0)
            {
                // Must be parent of child ...
                // The following will close new_sock and start a new accept call
                // This parent will not be monitoring its spawned child.
                continue;
            }
        }
#endif

        try
        {
            while (processSocket(new_sock))
            {               
                if (debug)
                    cout << "processed another record:"<<endl;
            }
            if (debug)
                cout <<"Finished socket "<<  ((multiTask)?" Child task terminating":"")  <<endl;
#ifdef LINUX
            if (multiTask)
            {
                // If we are are here, we must be a Child task trying to terminate;
                // We will break out of the while accept loop which should close the new_sock.
                break;
            }
#endif
        }
        catch ( SocketException& e) 
        {
            cout << "runServer:Exception was caught:" 
                << e.description() << "\n";

        }

    }// end of accept loop;

}
bool ServerSocket::processSocket(Socket & new_sock)
{
    stringLine data;
    new_sock >> data;
    cout << "processSocket received:" << data <<"***"<< endl;
    if (data.size() == 0)
    {
        cout << "Socket termination" << endl;
        return false;
    }
    new_sock << data;
    return true;
}





// ************************************************
// webParms.cpp
// ************************************************




void webParms::parse(string & s)
{
    unsigned int startParm=0;
    string temp;

    for (unsigned int i=0; i < s.size(); i++)
    {
        if (s[i] == '&')
        {
            temp = s.substr(startParm, i-startParm);
            processOneParm(temp);
            startParm = i+1;
        }
    }

    // process the remainder of the string after last &
    if (startParm < s.size())
    {
        temp = s.substr(startParm, s.size() - startParm);
        processOneParm(temp);
    }
}

void webParms::processOneParm(string & p)
{
    for (unsigned int i=0; i < p.size(); i++)
    {
        if (p[i] == '=')
        {
            string name = p.substr(0,i);
            string value;
            if (i < p.size()-1)
                value = p.substr(i+1);

            unencode(name);
            unencode(value);
            Parm parm(name, value);
            m_parms.push_back(parm);
            break;
        }
    }
}

void webParms::unencode(string & s)
{
    string temp = s;
    s = "";
    for (unsigned int i=0; i < temp.size(); i++)
    {
        char c = temp[i];
        if (c == '+') c = ' ';
        if (c == '%')
        {
            // Next 2 chars should be hex digits
            char c1 = temp[i+1];
            char c2=  temp[i+2];

            // Note that all digits < all Cap letters < all lower case letters
            // Note that 0xdf converts lower case to upper case
            int digit1 =((c1>='A')? 10+(c1&0xdf)-'A': c1-'0'); 
            int digit2 =((c2>='A')? 10+(c2&0xdf)-'A': c2-'0');
            c = digit1*16 + digit2;
            i += 2; // skip 2 extra characters
        }
        s += c;
    }
}


void webParms::encode(string & s)
{
    string temp = s;
    s = "";
    for (unsigned int i=0; i < temp.size(); i++)
    {
        int d1, d2;
        char c = temp[i];
        if (c == ' ') c = '+';
        switch (c)
        {
        case '\n':
        case '\r':
        case '\t':
        case ';':
        case ':':
        case '=':
        case '<':
        case '>':
        case '&':
        case '"':
        case '\'':
            s += '%';
            d1 = c/16;
            d2 = c & 0x0f;
            s += ((d1 < 10)? '0'+d1: 'A' + (d1-10)); 
            s += ((d2 < 10)? '0'+d2: 'A' + (d2-10)); 
            break;

        default:
            s += c;
            break;
        }

    }
}

void webParms::print()
{
    cout <<" ******** webParms ********* " << endl;
    for (unsigned int i=0; i < m_parms.size(); i++)
    {
        cout << "name="<<m_parms[i].name << 
            " value=" << m_parms[i].value<<endl;
    }

    cout << endl << "******** Headers *******"<<endl;
    for (unsigned int i=0; i < m_headers.size(); i++)
    {
        cout << "Hdr: " << m_headers[i].name << ": " << 
            m_headers[i].value << endl;
    }        
    if (m_cookies.size() > 0)
    {
        cout << endl << "********* Cookies *******"<<endl;
        for (unsigned int i=0; i < m_cookies.size(); i++)
            cout << m_cookies[i].name << "=" << m_cookies[i].value<<endl;
    }

}


void webParms::parseOneHeader(string & line)
{
    string name, value;
    for (unsigned int i=0; i < line.size(); i++)
    {
        if (line[i] == ':')
        {
            name = line.substr(0, i);
            if (i < line.size() -2) // skip ": "
                value = line.substr(i+2);

            Parm parm(name, value);
            m_headers.push_back(parm);
            break;
        }
    } // end of for loop
}

void webParms::setCookie(const char *name, string & value, COOKIE_CMDS cmd)
{
    string n = name;
    setCookie(n, value, cmd);
}
void webParms::setCookie(string &name, string & value, COOKIE_CMDS cmd)
{
    // Need to encode the name and value  
    cookieHeader += "Set-Cookie: ";
    cookieHeader += name;
    cookieHeader += "=";
    cookieHeader += value;
    if (cmd == DELETE_COOKIE)
        cookieHeader += "; expires=Wed, 20-Aug-2007 00:00:00 GMT;";
    cookieHeader += "\r\n";
}

string * webParms::getParameter(const char * name)
{
    string n = name;
    return getParameter(n);
}

string * webParms::getParameter(string & name)
{
    for (unsigned int i=0; i < m_parms.size(); i++)
    {
        if (m_parms[i].name == name)
            return &m_parms[i].value;
    }
    return NULL;
}

string * webParms::getCookie(const char * name)
{
    string n = name;
    return getCookie(n);
}
string * webParms::getCookie(string & name)
{
    for (unsigned int i=0; i < m_cookies.size(); i++)
    {     
        if (m_cookies[i].name == name)
            return &m_cookies[i].value;
    }
    return NULL;
}

void webParms::extractCookies()
{
    string temp;

    for (unsigned int i=0; i < m_headers.size(); i++)
    {
        if (m_headers[i].name == "Cookie")
        {
            string cookie = m_headers[i].value;
            unsigned int start = 0;
            for (unsigned int i=0; i < cookie.size(); i++)
            {
                if (cookie[i] == ';')
                {
                    temp = cookie.substr(start, i-start);
                    processCookie(temp);
                    i+=1; // goto space after ;
                    while (cookie[i] == ' ') i+=1; // skip spaces
                    start = i;
                }
            }
            if (start < cookie.size() -3)
            {
                // need at least 3 characters like:  x=1
                temp = cookie.substr(start);
                processCookie(temp);
            }
        }
    }
}

void webParms::processCookie(string & s)
{
    for (unsigned int i=0; i < s.size(); i++)
    {
        if (s[i] == '=')
        {
            string name = s.substr(0, i);
            string value;
            if (i < s.size() -1)
                value = s.substr(i+1);
            Parm p(name,value);
            m_cookies.push_back(p);
            break;
        }
    }
}



// **************************************************
// WebServer.cpp
// **************************************************

//    #include "WebServer.h"
#include <strstream>
#include <fstream>
#include "CString.h"

WebServer::WebServer ( int port, bool debug ) : 
ServerSocket(port), m_debug(debug)
{

}



bool WebServer::processSocket(Socket & new_sock)
{
    m_sock = new_sock;
    string method, url;
    m_p_parms = new webParms();

    m_p_stream = new ostrstream(m_big_buff, BIG_BUFF_SIZE);

    bool webRequestIsGood = false ; //set this to true if it looks good

    m_sock >> method;
    if (m_debug)
        cout << "Method=" << method << endl;

    m_sock >> url;
    if (m_debug)
        cout << "url=" << url << endl;

    m_sock.setContinueBufferReads(false);
    processHeaders();

    if (method == "GET")
    {
        webRequestIsGood = true; 
        for (unsigned int i=0; i < url.size(); i++)
        {
            if (url[i] == '?' && i < url.size()-1)
            {
                string s = url.substr(i+1);
                if (m_debug)
                    cout << " Parms part = " << s << endl;
                m_p_parms->parse(s);
                url = url.substr(0, i);
                break;
            }
        }

    } 
    else   if (method == "POST")
    {     
        webRequestIsGood = true;
        stringBuffer postBuffer;
        m_sock >> postBuffer;
        m_p_parms->parse(postBuffer);
    }
    else
    {
        // Error case.
        sendError("Method must be GET or POST ");
    }
    m_p_parms->url = url;

    if (m_debug)       
    {
        m_p_parms->print();
    }


    if (webRequestIsGood )     
        processWebSocket(*m_p_parms);

    flush();
    delete m_p_parms;
    delete m_p_stream;    
    return false; // We are going to close our socket after a web Request
}

void WebServer::processHeaders()
{
    // assume we need to read the remainder of first line
    string line;
    m_sock >> line; // throw away

    if (m_debug)
        cout << " Throw away: " << line << endl;

    while (getline(m_sock, line))
    {
        string name, value;
        if (line.size() == 0 )
            break; // end of header section

        m_p_parms->parseOneHeader(line);

    } // end of while loop
    m_p_parms->extractCookies();
}


void WebServer::sendError(char * err)
{
    setHeader(TEXT);
    write_to_socket(err);
}

void WebServer::setHeader(OutputType type)
{
    string contentType = "text/plain";

    switch (type)
    {
    case HTML:
    case HTM:
        contentType = "text/html";
        break;

    case JPEG:
    case JPG:
        contentType = "image/jpeg";
        break;

    case GIF:
        contentType = "image/gif";
        break;

    case TEXT:
    case CPP:
    case H:
    default:
        break;
    }

    setHeader(contentType);
}

void WebServer::setHeader(string & strType)
{
    if (m_debug)
        cout << "************  Start of Web Output ********\n"<<endl;

    string endOfLine = "\r\n";
    string firstLine = "HTTP/1.1 200 OK";
    firstLine += endOfLine;

    string secondLine =  "Content-type: ";
    secondLine += strType;
    secondLine += endOfLine;

    *m_p_stream << firstLine;
    *m_p_stream << secondLine;
    if (m_p_parms->cookieHeader.size() > 0)
        *m_p_stream << m_p_parms->cookieHeader;
    *m_p_stream << endOfLine;

    m_curr_in_buff = firstLine.size() + secondLine.size() + endOfLine.size();
}

void WebServer::flush()
{
    if (m_curr_in_buff > 0)
    {
        *m_p_stream << ends;
        m_sock << m_big_buff ;
        if (m_debug)
            cout << m_big_buff;
    }
    m_curr_in_buff = 0;
}

void WebServer::write_to_socket(const char * cstr)
{
    string s = cstr;
    write_to_socket(s);
}
void WebServer::write_to_socket(string & s)
{
    // Simple optimized small buffer case
    if ((s.size() + m_curr_in_buff) < BIG_BUFF_SIZE)
    {
        *m_p_stream << s;      
        m_curr_in_buff += s.size();
        return;
    }
    else
    {
        unsigned int start = 0;
        unsigned int spaceAvail =BIG_BUFF_SIZE - m_curr_in_buff;
        do
        {
            string temp = s.substr(start, spaceAvail);
            *m_p_stream << temp;
            flush();
            start += spaceAvail;
            spaceAvail = BIG_BUFF_SIZE;
            if (start + spaceAvail > s.size())
                spaceAvail = s.size() - start;
        }while(spaceAvail > 0);
    }

}

void WebServer::processWebSocket(webParms & parms)
{
#ifdef GIVE_ME_DEFAULT
#include "default_processWebSocket.h"
#endif
}


Socket & WebServer::writeBinary(char * buff, int sizeOfBuff)
{
    return m_sock.write(buff, sizeOfBuff);
}

int WebServer::writeFile(string & filename)
{
    return writeFile(filename.c_str());
}

int WebServer::writeFile(const char * filename)
{
    string suffixs[]={"html", "htm", "jpeg", "jpg", "gif", 
        "txt", "cpp", "h"};
    OutputType types[] = {HTML, HTM, JPEG, JPG, GIF, TEXT, CPP, H};
    OutputType fileType = TEXT; // Default 

    ifstream infile(filename, ios::binary);
    if (!infile)
    {      
        setHeader(HTML);
        write_to_socket("<html><head><title>Can't find file</title></head>\n");
        write_to_socket("<body> <h2>File Error</h2>\n");
        write_to_socket("Can't find file: ");
        write_to_socket(filename);
        write_to_socket("\n</body></html>");
        return -1;
    }

    string filename_str = filename;
    unsigned int index = filename_str.find_last_of(".");
    if (index != string::npos && index < filename_str.size() -1)
    {
        string suf = filename_str.substr(index+1);
        int matchIndex = -1;
        for (int i=0; i < sizeof(types)/sizeof(OutputType); i++)
        {
            if (suf == suffixs[i])
            {
                matchIndex = i;
                break;
            }
        }
        if (matchIndex >= 0)
            fileType = types[matchIndex];
        // else fileType will still be TEXT
    }

    setHeader(fileType);
    flush();


    char bigBuff[4096];
    int bytesRead, count=0;

    do
    {
        infile.read( bigBuff, sizeof(bigBuff) );
        bytesRead =  infile.gcount();
        count += bytesRead;
        writeBinary(bigBuff, bytesRead);
    } while (bytesRead > 0);
    return count;
}


