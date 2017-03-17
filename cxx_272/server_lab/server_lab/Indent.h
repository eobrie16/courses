#include <stack>
#include <string>
using namespace std;

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