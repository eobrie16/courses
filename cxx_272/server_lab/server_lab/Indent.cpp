#include <iostream>
#include <string>
#include <stack>

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
