#include <iostream>
#include <fstream>
using namespace std;
#include <string>
#include <stack>

// Store location of beginning character
class LeftSymbol
{
public:
    void setLeftSymbol(char chr, int lineNum, int colNum)
    {
      m_chr = chr;
      m_lineNum = lineNum;
      m_colNum = colNum;
    }
    bool checkRightSymbol(char chr)
    {
        return chr == m_chr;
    }
    void getLoc(int & lineNum, int & colNum)
    {
        lineNum = m_lineNum;
        colNum = m_colNum;
    }
private:
    char m_chr;
    int m_lineNum;
    int m_colNum;
};

class BalanceSymbols
{
public:
    // Called at the end of processing lines to make sure
    // the stack is empty
    void checkEnd();

    // Called for every input line to check for 
    //    balancing (..), [..], and {..}
    void processLine(string &line, int lineNum);

private:
    stack<LeftSymbol> m_symbols;
};
