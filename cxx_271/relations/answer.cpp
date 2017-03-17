/////////////////////////////////////
// relations.h
/////////////////////////////////////

// ************************************************
// Person Class
// ************************************************

enum T_GENDER {male=0, female=1};


class Person
{
public:

 Person(T_GENDER g=female, string n="unknown", int age=0 ) : gender(g), name(n), age(0) {};

 void createPerson()
 {
        int temp;
  cout << "Name: ";
  cin  >> name;

  cout << "Gender (0 for male, 1 for female): ";
  cin  >> temp;
        if (temp == (int)male || temp==(int)female) gender = (T_GENDER)temp;
        else gender = female;

  cout << "Age: ";
  cin  >> age;
 }
 void eat() const              {cout<< name << " is eating."<<endl;}
 void sleep() const            {cout<< name << " is sleeping."<<endl;}
 void setAge(int number)       {age=number;}
 void setGender(T_GENDER g)
 {  
  gender = g;
 }
 char getGender()              {return gender;}
 void setName(string appelation) {name = appelation;}
 int  getAge() const           {return age;}
 string getName() const        {return name;}

protected:
 string name;
 int    age;
 T_GENDER gender;
};



// ************************************************
// Marriage Class
// ************************************************


class Marriage
{
public:
 Marriage()
 {
  cout << "Marriage unites a man and a woman." << endl;
        cout << " Enter in information about the man: " << endl;
        male.createPerson();
        cout << " Enter in information about the female: " << endl;
        female.createPerson();
 };

    /* See if you can figure out how to do this one
 Marriage(Person man, Person woman) 
    */
 
 void printNames()
 {
  cout << "Man:   " << male.getName() << endl;
  cout << "Woman: " << female.getName() << endl;
 }
private:
 Person male;
 Person female;
};

// ************************************************
// Family Class
// ************************************************
class Family
{
public:
    Family()
    {
    }
    /*
    See if you can figure out how to do the following:
    Family(int num, Person p[]);
    Family(int num, Person * p[]);
    */
    Family (int num)
    {
        m_num = num;
        m_family = new Person * [num]; 
        for (int i=0; i < num; i++)
        {
            Person * p = new Person();
            p->createPerson();
            m_family[i] = p;
        }
    }
    void eatDinner()
    {
        for (int i=0; i < m_num; i++)
        {
            m_family[i]->eat();
        }
    }
    ~Family()
    {
        for (int i=0; i < m_num; i++)
        {
            delete m_family[i];
        }
        delete [] m_family;
    }
private:
    int m_num;
    Person ** m_family;
};

// ********************************************
// Student Class
// ********************************************


const int MAX_CLASSES = 7;

struct Course
{
 string name;
 double   grade;
};

class Student : public Person
{
public:
 Student() : GPA(0), major("Undeclared"), numclasses(0) {};
 void   createStudent()
 {
  this->createPerson();

  cout << "GPA: ";
  cin  >> GPA;
  cout << "Major: ";
  cin  >> major;
  setClasses();
 }

 void   setGPA(float gpa)    {GPA = gpa;}
 float  getGPA(void)         {return GPA;}
 void   setMajor(string maj) {major = maj;}
 string getMajor(void)       {return major;}

 void   setClasses(void)     
 {
  int num;
  cout << "How many classes?" << endl;
  cin  >> num;
  if(num>MAX_CLASSES)
  {
   cout << "Max number of classes is " << MAX_CLASSES << "." << endl;
      num = MAX_CLASSES;
  }
  if(num<1)
  {
   cout << "Must have at least one class." << endl;
   num = 1;
  }
  for(int k=0;k<num;k++)
  {
   cout << "Class name: ";
   cin  >> classes[k].name;
            cout << "Grade: (double: i.e. 3.3)";
   cin  >> classes[k].grade;
  }
  numclasses = k;
 }
 void printClasses()
 {
  cout << name << "'s Report Card" << endl << endl;
  for(int k=0;k<numclasses;k++)
   cout << classes[k].name << " = " << classes[k].grade << endl;
  cout << endl;
 }
protected:
 float  GPA;
 string major;
 Course classes[MAX_CLASSES];
 int    numclasses;
};



// ************************************************
class GradStudent : public Student
{
protected:
 string degree;
 string thesis;
public:
 GradStudent() : degree("CS"), thesis("Beyond good, evil, and software.") {};
 void createGradStudent()
 {
  this->createStudent();

  cout << "Degree: ";
  cin  >> degree;
  cout << "Thesis: ";
  cin  >> thesis;
 }
};

/////////////////////////////////////
// main.cpp
/////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;

#include "relations.h"

int main()
{
    Person p(male, "Fred", 40);
    Person p2(female, "Wilma");
    Person p3(male);
    p.eat();
 p.sleep();
 p.setAge(24);
 cout << p.getName() << " is " << p.getAge() << " years old." << endl;
    
 cout << "Marriage /////////////" << endl;
 Marriage happy;
 happy.printNames();

    cout << endl << "Family ///////////////" << endl;
 Family fam(3);
 fam.eatDinner();

 cout << "Grad Student ///////" << endl;
 GradStudent gary;
 gary.createGradStudent();
 gary.printClasses();
 cout << gary.getName() << " is " << gary.getAge() << " years old." << endl;

 }

