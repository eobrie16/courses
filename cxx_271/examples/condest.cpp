#include <iostream>
using namespace std;

class AThing
{
protected:
	char a;
public:
	AThing(char a='a')
	{
		this->a = a;
		cout << "AThing constructor: " << a << endl;
	}
	~AThing()
	{
		cout << "AThing destructor: " << a << endl;
	}
};

class BThing : public AThing
{
public:
	BThing(char x='a'):AThing(x)
	{
		cout << "BThing constructor: " << a << endl;
	}
	~BThing()
	{
		cout << "BThing destructor: " << a << endl;
	}
};

int main()
{
	AThing x,y('y'),z('z');	
	cout << " --------------------" << endl;
	BThing d('d');

	AThing *px = new AThing('p');

	cout << "Middle of program" << endl;
	delete px;
	return 0;
}