#include "WebServerInc.h"

#include <string>
#include <iostream>
#include <stack>
#include "CString.h"
const int MAX=128;

//
//Originally in header files, but put here so I could submit on Aardvark
//
class Indent
{
public:
    int processLine(string &str, int lineNum);
    Indent()
    {
        // Handy to push an initial entry on the stack
        // starting at location 0
        m_startingColStack.push(0);
    }
private:
    stack<int> m_startingColStack;
};

int Indent::processLine(string &str, int lineNum)
{
    int len = str.size();
    int startingCol = 0;

    // Find the location of the first non-blank
    // Assuming no TABs, .... TABs would take a little more work here.
    for ( ; startingCol < len; startingCol ++)
        if (str[startingCol] != ' ' ) break;

    // Skip completely blank lines
    if (startingCol == len) return 0; 

    // If the new starting line is > top of stack, then push it on stack
    if (startingCol > m_startingColStack.top())
    {
        m_startingColStack.push(startingCol);
        return 0;
    }

    // Pop off the stack all of the starting locations > than
    //    the current starting position
    while(startingCol < m_startingColStack.top())
        m_startingColStack.pop();


    // If the top of the remaining stack == the current starting position,
    //    we are in good shape, otherwise we have an error to report

    if (startingCol == m_startingColStack.top()) return 0;
    else return -1;

}


class MyWebServer : public WebServer
{
public:
    MyWebServer(int port, bool debug=false): WebServer(port, debug)
    {}

    void processWebSocket(webParms & new_sock);
};

void MyWebServer::processWebSocket(webParms & parms)
{  

    //vector<Parm> parameters = parms.getParms();
	string * program = parms.getParameter("program");

    setHeader(TEXT);

    // Header Stuff
    CStringOut buff;
    ostream * ostr = buff.getOstream();
	Indent checker;
	if (program != NULL)
	{
		CStringIn x(*program);
		istream * istr = x.getIstream();
		char line[MAX];
		*ostr << "Program contains: " << endl;
		int count=1;
		int ok=-1;
		while(*istr)
		{
			istr->getline(line, MAX);
			ok = checker.processLine(string(line), count);
			if (ok < 0)
				*ostr << "//INDENTATION ERROR AT LINE: " << count << endl;
		    *ostr << line << endl;
			count++;
		}
		
		

	}

    write_to_socket(buff.c_str());
}



int main ( int argc, const char* argv[] )
{
#ifndef LINUX
    oneTimeSocketInitialization();
#endif


    int port = 4321; // port number;
    bool debug_flag = false; // no debug
    bool multi_task = true;  // multi-tasking server
    if (argc > 1)
        port = atol(argv[1]);
    if (argc > 2 && strcmp(argv[2],"true") == 0)
        debug_flag = true;

    cout << "running " << argv[0] << " port =" << port 
        << " debug="<< debug_flag<< endl;

    try
    {
        // Create the socket
        MyWebServer webServer ( port , debug_flag);

        webServer.runServer(multi_task, debug_flag);

    }
    catch ( SocketException& e )
    {
        cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }



#ifndef LINUX
    socketDeIntialization();
#endif
    return 0;
}
