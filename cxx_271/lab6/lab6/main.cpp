#include <iostream>
using namespace std;
#include <string.h>
////////////////////////////////////////////////////////////////
class Person
{
protected:
	int age;
	double weight;
	string name;
public:
	Person();
	Person(int age, double w, string & n);
	void printInfo();
	void eating();
	void sleeping();
	string getName();
};

class Student : public Person
{
protected:
	double GPA;
	string major;
public:
	Student(double g, string & m, int a, double w, string & n);
	void printInfo();
	void studying();
};

class GradStudent : public Student
{
protected:
	string specialty;
	int pubs;
public:
	GradStudent(string & s, int p, double g, string & m, int a, double w, string & n);
	void printInfo();
	void researching();
};

class Engineer : public Person
{
private:
	string employer;
	int experience;
public:
	Engineer(string & e, int y, int a, double w, string & n);
	void printInfo();
	void working();
	void atLunch();
};


class Marriage : public Person
{
private:
	Person man;
	Person woman;
	int children;
public:
	Marriage(Person & m, Person & w);
	//we assume they eat and sleep together
	void eating();
	void sleeping();
	void printInfo();
	void makeBaby();
};


Person::Person(int a, double w, string & n):age(a), name(n), weight(w)
{
}
Person::Person():age(0), name("unknown"), weight(100)
{
}
void Person::printInfo()
{
	cout << "Name: " << name.c_str() << endl;
	cout << "Age: " << age << endl;
	cout << "Weight: " << weight << endl;
}
string Person::getName()
{
	return name;
}
void Person::eating()
{
	cout << name.c_str() << " is eating!" << endl;
	weight += 1;
}
void Person::sleeping()
{
	cout << name.c_str() << " is sleeping!" << endl;
	weight -= 1;
}
Student::Student(double g, string & m, int a, double w, string & n):Person(a, w, n)
{
	GPA = g;
	major = m;
}
void Student::printInfo()
{
	Person::printInfo();
	cout << "GPA: " << GPA << endl;
	cout << "Major: " << major.c_str() << endl;
}
void Student::studying()
{
	cout << name.c_str() << " is studying." << endl;
}

GradStudent::GradStudent(string & s, int p, double g, string & m, int a, double w, 
						 string & n):Student(g, m, a, w, n)
{
	specialty = s;
	pubs = p;
}
void GradStudent::printInfo()
{
	Student::printInfo();
	cout << "Specialty: " << specialty.c_str() << endl;
	cout << "Number of publications: " << pubs << endl;
}
void GradStudent::researching()
{
	cout << name.c_str() << " is researching." << endl;
}

Engineer::Engineer(string & e, int y, int a, double w, string & n):Person(a, w, n)
{
	employer = e;
	experience = y;
}

void Engineer::printInfo()
{
	Person::printInfo();
	cout << name.c_str() << " is an Engineer." << endl;
	cout << "Employer name: " << employer.c_str() << endl;
	cout << "Years of experience: " << experience << endl;
}
void Engineer::working()
{
	cout << name.c_str() << " is working." << endl;
}
void Engineer::atLunch()
{
	cout << name.c_str() << " is at lunch." << endl;
}

Marriage::Marriage(Person & m, Person & w)
{
	man = m;
	woman = w;
	children = 0;
	cout << man.getName().c_str() << " and " << woman.getName().c_str() << " are now married." << endl;
}
void Marriage::printInfo()
{
	cout << "(Husband Data)" << endl;
	man.printInfo();
	cout << "(Wife Data)" << endl;
	woman.printInfo();
	cout << "They have " << children << " kids." << endl;
}
void Marriage::makeBaby()
{
	children++;
	cout << man.getName().c_str() << " and " << woman.getName().c_str() << " have a new child!" << endl;
}
void Marriage::eating()
{
	man.eating();
	woman.eating();
}
void Marriage::sleeping()
{
	man.sleeping();
	woman.sleeping();
}

int main()
   {
	   string name="Joe";
	   Person joe(30, 160, name);
	   joe.printInfo();
	   cout << endl;

	   string name2="Sally";
	   Person sally(24, 120, name2);
	   sally.printInfo();
	   cout << endl;

	   name = "Bob";
	   Student bob(3.95, string("engineering"), 26, 170, name);
	   bob.printInfo();
	   bob.studying();
	   cout << endl;

	   GradStudent vijay(string("programming"), 8, 3.99, string("computer science"), 32, 144, string("Vijay"));
	   vijay.printInfo();
	   vijay.eating();
	   vijay.eating();
	   vijay.researching();
	   vijay.printInfo();
	   cout << endl;

	   Engineer paul(string("Ford"), 5, 29, 155, string("Paul"));
	   paul.printInfo();
	   paul.atLunch();
	   cout << endl;

	   Marriage smiths(joe, sally);
	   smiths.printInfo();
	   smiths.sleeping();
	   smiths.makeBaby();
	   smiths.eating();
	   smiths.printInfo();	

	   return 0;
   }
