#include "balance.h"



void BalanceSymbols::processLine(string &str, int lineNum)
{
    int len = str.size();
    int startingCol = 0;

    // Find the location of the first non-blank
    // Assuming no TABs, .... TABs would take a little more work here.
	LeftSymbol temp;
	bool ok;
	string symtype;
    for (int startingCol=0; startingCol < len; startingCol ++)
	{
		if (str[startingCol] == ' ') continue;
        else if (str[startingCol] == '{' || str[startingCol] == '(' || str[startingCol] == '[')
		{
			temp.setLeftSymbol(str[startingCol],lineNum,startingCol);
			m_symbols.push(temp);
		}
		else if (str[startingCol] == '}' || str[startingCol] == ')' || str[startingCol] == ']')
		{
			if (!m_symbols.empty())
			{
				temp = m_symbols.top();
				//Identify type of symbol expected
				if (temp.checkRightSymbol('('))  symtype = "parentheses";
				else if (temp.checkRightSymbol('[')) symtype = "brackets";
				else symtype = "braces";

				if (str[startingCol] == '}') ok = temp.checkRightSymbol('{');
				else if (str[startingCol] == ')') ok = temp.checkRightSymbol('(');
				else  ok = temp.checkRightSymbol('[');
			}
			else
			{
				ok=false;
				symtype = "code";
			}

			if (ok)  m_symbols.pop();
			else 
			{
				//Need to empty stack
				while (!m_symbols.empty())
					m_symbols.pop();
				string error = "Unbalanced ";
				char cbuff[200];
				sprintf(cbuff, "%s at line number %d, column number: %d\r\n", symtype.c_str(), lineNum, startingCol+1);
				error += cbuff;
				throw error;
			}

		}
	}
}

void BalanceSymbols::checkEnd()
{
	if (m_symbols.empty()) return;
	else
	{
				//Need to empty stack
				while (!m_symbols.empty())
					m_symbols.pop();
				string error = "Unbalanced code at End of file!";
				throw error;
	}
}


