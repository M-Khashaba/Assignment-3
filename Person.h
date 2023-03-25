#include <iostream>
using namespace std;

class Person
{
private:
    string name;
    string ID;
    int age;
public:
    Person()
    {}
    void setname(string s);
    string getname();
    void setid(string i);
    string getid();
    void setage(int a);
    int getage();
    virtual void print();

    struct Appointment
    {
        int hours;
        int minutes;
    };

};

void Person::setname(string s)
{
    name = s;
}
string Person::getname()
{
    return name;
}
void Person::setid(string i)
{
    ID = i;
}
string Person::getid()
{
    return ID;
}
void Person::setage(int a)
{
    age = a;
}
int Person::getage()
{
    return age;
}
void Person::print()
{
    cout << "Name: " << name << endl;
    cout << "ID: " << ID << endl;
    cout << "Age: " << age << endl;
}