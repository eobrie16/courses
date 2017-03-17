#include <iostream>
#include <string>
using namespace std;

class Parm
{
public:
	string name;
	int frequency;

	Parm(string n, int f): name(n), frequency(f)
	{}

	void print()
	{
		cout << name << " : " << frequency<<endl;
	}
	bool operator < (Parm & p) const
	{
		return (name < p.name);
	}
	bool operator > (Parm & p) const
	{
		return (name > p.name);
	}
	bool operator == (Parm & p) const
	{
		return (name == p.name);
	}
};
