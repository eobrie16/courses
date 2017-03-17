#include "DataBase.h"
#include "WebServerInc.h"
#include <string>
#include <fstream>
#include "CString.h"
#include "DataBase.h"
#include "d_setopts.h"

extern DataBase dataBase;

void readInFile(const char * filename, GENDER gender)
{
    ifstream infile(filename);
    string str;
    while (getline(infile, str))
    {
        Person p(gender,str);
        dataBase.add(p);        
    }
    cout <<filename << " read in ... new size =" << dataBase.getDB_size()<<endl;
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
    set<int> results; // initially empty
    bool resultsComputed = false;
// ***************************************
// Filter by Count if necessary
// ***************************************
    cout <<"****************************************************"<<endl;

    const int BIG_NUMBER=100000000;
    string *pstartCount = parms.getParameter("startCount");
    string *pendCount = parms.getParameter("endCount");
    int startCount=0, endCount=BIG_NUMBER;
    if (pstartCount != NULL && pstartCount->length() >0)
        startCount = atol(pstartCount->c_str());
    
    if (pendCount != NULL && pendCount->length() >0)
        endCount = atol(pendCount->c_str());

    if (startCount != 0 || endCount != BIG_NUMBER)
    {        
        results =dataBase.getCountRange(startCount, endCount);        
        resultsComputed = true;
        cout << "getCountRange("<<startCount<<","<< endCount<<") size="<<
            results.size() << endl;
    }

// ***************************************
// Filter by Name ... If no filters have occurred               
//                    then we need to request all Persons
// ***************************************
    string *pstartName = parms.getParameter("startName");
    string *pendName = parms.getParameter("endName");
    string startName, endName;
    if (pstartName!=NULL )
        startName = *pstartName;
    if (pendName !=NULL)
        endName = *pendName;

    if (!resultsComputed)
    {
        // Note that in this run, we have no count filter and 
        // if there is no name filter, then startName and endName will 
        // have a length of 0 which will result in all Persons showing up 
        // in result.
        results =dataBase.getNameRange(startName, endName);
        cout << "getNameRange("<<startName << "," << endName <<") size="<<
            results.size()<<endl;
    }
    else
    { 
        if (startName.length() > 0 || endName.length() > 0)
        {
            set<int> results2; 
            
            results2 =dataBase.getNameRange(startName, endName);
            cout << "getNameRange("<<startName << "," << endName <<")  results2 size="<<
                results2.size() <<endl;
            // Apparently we have filtered by count and name, so 
            // do a Set intersection of the results. 
            results = results * results2;
            cout << "Intersection size=" << results.size() << endl;
        }
    }
// ***************************************
// Filter desired Gender
// ***************************************
    cout << "Current results size = " << results.size() << endl;
  
    string *pgenderType = parms.getParameter("genderType");
    if (pgenderType != NULL && *pgenderType != "All")
    {
        set<int>::iterator iter=results.begin();
        GENDER gender = FEMALE; 
        if (*pgenderType=="Male") gender = MALE;

        // Now eliminate all Persons which don't match the gender type
        while(iter != results.end())
        {
            Person * p=dataBase.getPerson(*iter);
            if (p->m_gender != gender)
                results.erase(iter++);
            else
                iter++;
        }
        cout << "After gender filtering, size="<< results.size()<<endl;
    }
    // Ready to generate output
    setHeader(TEXT);
    
// ***************************************
// Find the sort type and generate output
// ***************************************
    CStringOut buff;
    ostream * ostr = buff.getOstream();

    string *psortType = parms.getParameter("sortType");
    if (psortType != NULL && *psortType == "Name")
    {
        // Sort output by Name
        multiset<sort_name> sortedResults = dataBase.sortByName(results);
        multiset<sort_name>::iterator iter=sortedResults.begin();
        while (iter != sortedResults.end())
        {
            (*iter).person->print(*ostr);
            iter++;
        }
    }
    else if (psortType != NULL && *psortType == "Count")
    {
        // Sort output by Count
        multiset<sort_count> sortedResults = dataBase.sortByCount(results);
        multiset<sort_count>::iterator iter=sortedResults.begin();
        while (iter != sortedResults.end())
        {
            (*iter).person->print(*ostr);
            iter++;
        }
    }
    else // No sorting
    {
        set<int>::iterator iter= results.begin();
        while (iter != results.end())
        {
            Person * p = dataBase.getPerson(*iter);
            p->print(*ostr);
            iter++;
        }
    }

    write_to_socket(buff.c_str());
}




int main ( int argc, const char* argv[] )
{
#ifndef LINUX
    oneTimeSocketInitialization();
#endif
    readInFile("boys_names.txt", MALE);
    readInFile("girls_names.txt", FEMALE);


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


