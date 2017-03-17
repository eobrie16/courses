#include "WebServerInc.h"

#include <string>
#include "CString.h"

/*class Indent
{
public:
    void processLine(string &str, int lineNum);
    Indent()
    {
        // Handy to push an initial entry on the stack
        // starting at location 0
        m_startingColStack.push(0);
    }
private:
    stack<int> m_startingColStack;
};

void Indent::processLine(string &str, int lineNum)
{
    int len = str.size();
    int startingCol = 0;
	bool found=false;

	for (int i=0; i<len; i++)
	{
		if (str[i] == ' ')
			startingCol = i;
		else
		{
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "blank line: " << lineNum << endl;
		return;
	}


	if (startingCol > m_startingColStack.top())
	{
		m_startingColStack.push(startingCol);
	}
		
	else if (startingCol < m_startingColStack.top())
	{
		while (startingCol < m_startingColStack.top())
		{
			m_startingColStack.pop();
		}
	}

	if (startingCol != m_startingColStack.top())
	{		
		char buff[20]; // space for C-String
		sprintf(buff, "%d", lineNum); 
		string s = buff;
		string indentationError = "Indentation is incorrect on line " + s;
		throw indentationError;
	}
}*/

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
	//Indent myprog;
	if (program != NULL)
	{
		*ostr << "Program contains: " << endl;
		*ostr << *program << endl;
		*ostr << "Program is unbalanced at line 24 " << endl;
		

	}

    write_to_socket(buff.c_str());
}

class Indent
{
public:
    void processLine(string &str, int lineNum);
    Indent()
    {
        // Handy to push an initial entry on the stack
        // starting at location 0
        m_startingColStack.push(0);
    }
private:
    stack<int> m_startingColStack;
};

void Indent::processLine(string &str, int lineNum)
{
    int len = str.size();
    int startingCol = 0;
	bool found=false;

	for (int i=0; i<len; i++)
	{
		if (str[i] == ' ')
			startingCol = i;
		else
		{
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "blank line: " << lineNum << endl;
		return;
	}


	if (startingCol > m_startingColStack.top())
	{
		m_startingColStack.push(startingCol);
	}
		
	else if (startingCol < m_startingColStack.top())
	{
		while (startingCol < m_startingColStack.top())
		{
			m_startingColStack.pop();
		}
	}

	if (startingCol != m_startingColStack.top())
	{		
		char buff[20]; // space for C-String
		sprintf(buff, "%d", lineNum); 
		string s = buff;
		string indentationError = "Indentation is incorrect on line " + s;
		throw indentationError;
	}
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
