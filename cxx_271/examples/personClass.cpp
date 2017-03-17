#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
	double weight;
	string name;
public:
	Person(double w, string & n);
	double getWeight()
	{
		return weight;
	}
	string & getName()
	{
		return name;
	}
	void sleeping()
	{
		cout << name << " sleeping" << endl;
	}
};

class Marriage
{
private:
	Person man;
	Person woman;
public:
	Marriage(Person & m, Person & w);
};

Marriage::Marriage(Person & m, Person & w):
	man(m.getWeight(), m.getName()), woman(w.getWeight(), w.getName())
{
}

class Model : public Person
{
protected:
	string sponsor;
public:
	Model(string & s, double w, string & n);
};

class FPlayer : public Person
{
protected:
	string position;
public:
	FPlayer (string & p, double w, string & n);
};
class QB : public FPlayer
{
private:
	int TDs;
	int pyardage;
public:
	QB(int t, int y, double w, string &n);
};


Model::Model(string & s, double w, string & n):Person(w, n), sponsor(s)
{

}
Person::Person(double w, string & n): name(n)
{
	weight = w;
}
FPlayer::FPlayer (string & p, double w, string & n):Person(w,n), position(p)
{

}
QB::QB(int t, int y, double w, string &n):FPlayer(string("QB"), w, n), TDs(t), pyardage(y)
{

}

int main()
   {
	   QB Brady(50, 4000, 220, string("Brady"));
	   Model Gissel(string("Victoria Secret"), 105, string("Gissel"));

	   Brady.sleeping();
	   Gissel.sleeping();

	   Marriage m(Brady, Gissel);
   return 0;
   }

