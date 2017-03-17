
#include <fstream>
#include "DataBase.h"
#include "d_setops.h"
#include "WebServerInc.h"

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
// Filter by Weight if necessary
// ***************************************
    cout <<"****************************************************"<<endl;

    const int BIG_NUMBER=100000000;
    string *pstartWeight = parms.getParameter("startWeight");
    string *pendWeight = parms.getParameter("endWeight");
    int startWeight=0, endWeight=BIG_NUMBER;
    if (pstartWeight != NULL && pstartWeight->length() >0)
        startWeight = atol(pstartWeight->c_str());
    
    if (pendWeight != NULL && pendWeight->length() >0)
        endWeight = atol(pendWeight->c_str());

    if (startWeight != 0 || endWeight != BIG_NUMBER)
    {        
        results =dataBase.getWeightRange(startWeight, endWeight);        
        resultsComputed = true;
        cout << "getWeightRange("<<startWeight<<","<< endWeight<<") size="<<
            results.size() << endl;
    }

// ***************************************
// Filter by Height if necessary
// ***************************************
    cout <<"****************************************************"<<endl;

    string *pstartHeight = parms.getParameter("startHeight");
    string *pendHeight = parms.getParameter("endHeight");
    int startHeight=0, endHeight=BIG_NUMBER;
    if (pstartHeight != NULL && pstartHeight->length() >0)
        startHeight = atol(pstartHeight->c_str());
    
    if (pendHeight != NULL && pendHeight->length() >0)
        endHeight = atol(pendHeight->c_str());

	if ((!resultsComputed)&&(startHeight != 0 || endHeight != BIG_NUMBER))
    {
        results =dataBase.getHeightRange(startHeight, endHeight);        
        resultsComputed = true;
        cout << "getHeightRange("<<startHeight<<","<< endHeight<<") size="<<
            results.size() << endl;
    }
    else
    { 
        if (startHeight != 0 || endHeight != BIG_NUMBER)
        {
            set<int> results2; 
            
            results2 =dataBase.getHeightRange(startHeight, endHeight);
            cout << "getHeightRange("<<startHeight << "," << endHeight <<")  results2 size="<<
                results2.size() <<endl;
            // Apparently we have filtered by count and name, so 
            // do a Set intersection of the results. 
            results = results * results2;
            cout << "Intersection size=" << results.size() << endl;
        }
    }

// ***************************************
// Filter by Beauty if necessary
// ***************************************
    cout <<"****************************************************"<<endl;

    string *pstartBeauty = parms.getParameter("startBeauty");
    string *pendBeauty = parms.getParameter("endBeauty");
    int startBeauty=0, endBeauty=BIG_NUMBER;
    if (pstartBeauty != NULL && pstartBeauty->length() >0)
        startBeauty = atol(pstartBeauty->c_str());
    
    if (pendBeauty != NULL && pendBeauty->length() >0)
        endBeauty = atol(pendBeauty->c_str());

	if ((!resultsComputed)&&(startBeauty != 0 || endBeauty != BIG_NUMBER))
    {
        results =dataBase.getBeautyRange(startBeauty, endBeauty);        
        resultsComputed = true;
        cout << "getBeautyRange("<<startBeauty<<","<< endBeauty<<") size="<<
            results.size() << endl;
    }
    else
    { 
        if (startBeauty != 0 || endBeauty != BIG_NUMBER)
        {
            set<int> results2; 
            
            results2 =dataBase.getBeautyRange(startBeauty, endBeauty);
            cout << "getBeautyRange("<<startBeauty << "," << endBeauty <<")  results2 size="<<
                results2.size() <<endl;
            // Apparently we have filtered by count and name, so 
            // do a Set intersection of the results. 
            results = results * results2;
            cout << "Intersection size=" << results.size() << endl;
        }
    }

// ***************************************
// Filter by Intelligence if necessary
// ***************************************
    cout <<"****************************************************"<<endl;

    string *pstartIntell = parms.getParameter("startIntelligence");
    string *pendIntell = parms.getParameter("endIntelligence");
    int startIntell=0, endIntell=BIG_NUMBER;
    if (pstartIntell != NULL && pstartIntell->length() >0)
        startIntell = atol(pstartIntell->c_str());
    
    if (pendIntell != NULL && pendIntell->length() >0)
        endIntell = atol(pendIntell->c_str());

	if ((!resultsComputed)&&(startIntell != 0 || endIntell != BIG_NUMBER))
    {
        results =dataBase.getIntellRange(startIntell, endIntell);        
        resultsComputed = true;
        cout << "getIntellRange("<<startIntell<<","<< endIntell<<") size="<<
            results.size() << endl;
    }
    else
    { 
        if (startIntell != 0 || endIntell != BIG_NUMBER)
        {
            set<int> results2; 
            
            results2 =dataBase.getIntellRange(startIntell, endIntell);
            cout << "getIntellRange("<<startIntell << "," << endIntell <<")  results2 size="<<
                results2.size() <<endl;
            // Apparently we have filtered by count and name, so 
            // do a Set intersection of the results. 
            results = results * results2;
            cout << "Intersection size=" << results.size() << endl;
        }
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
  
    string *pgenderType = parms.getParameter("Gender");
    if (pgenderType != NULL && *pgenderType != "all")
    {
        set<int>::iterator iter=results.begin();
        GENDER gender = FEMALE; 
        if (*pgenderType=="male") gender = MALE;

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
    if (psortType != NULL && *psortType == "height")
    {
        // Sort output by Height
        multiset<sort_height> sortedResults = dataBase.sortByHeight(results);
        multiset<sort_height>::iterator iter=sortedResults.begin();
        while (iter != sortedResults.end())
        {
            (*iter).person->print(*ostr);
            iter++;
        }
    }
    else if (psortType != NULL && *psortType == "weight")
    {
        // Sort output by Weight
        multiset<sort_weight> sortedResults = dataBase.sortByWeight(results);
        multiset<sort_weight>::iterator iter=sortedResults.begin();
        while (iter != sortedResults.end())
        {
            (*iter).person->print(*ostr);
            iter++;
        }
    }
	else if (psortType != NULL && *psortType == "beauty")
    {
        // Sort output by Beauty
        multiset<sort_beauty> sortedResults = dataBase.sortByBeauty(results);
        multiset<sort_beauty>::iterator iter=sortedResults.begin();
        while (iter != sortedResults.end())
        {
            (*iter).person->print(*ostr);
            iter++;
        }
    }
	else if (psortType != NULL && *psortType == "intell")
    {
        // Sort output by Intelligence
        multiset<sort_intell> sortedResults = dataBase.sortByIntell(results);
        multiset<sort_intell>::iterator iter=sortedResults.begin();
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
    readInFile("men_names.txt", MALE);
    readInFile("women_names.txt", FEMALE);


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
