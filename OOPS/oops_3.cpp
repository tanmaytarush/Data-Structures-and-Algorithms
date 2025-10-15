/*

Constructor:-
- Non-parameterized constructor
- Parameterized constructor
- Copy constructor

The phenomenon by which the second parameterized constructor is called 
automatically in the main function is called constructor overloading, which
in turn is an example of polymorphism.

*/

#include<iostream>
using namespace std;

class Teacher{
private:
    double salary;

public:
    // Non-parameterized constructor
    Teacher()
    {
        cout<<"Hi!, Constructor called...\n";
    }

    // Parameterized constructor
    Teacher(string n, string d, string s, double sal)
    {
        name = n;
        dept = d;
        subject = s;
        salary = sal;
    }

    string name;
    string dept;
    string subject;

    void setDept(string d)
    {
        dept = d;
    }

    string getDept()
    {
        return dept;
    }

    void getInfo()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Department : "<<dept<<endl;
    }
};

int main()
{
    Teacher t1;
    Teacher t2("Shraddha", "Electronics", "C++", 25000);
    t1.name = "Lady Gaga";
    t1.dept = "Computer Science";
    t1.subject = "Design Principles";
    cout<<t1.name<<endl<<t1.dept<<endl<<t1.subject<<endl;
    t1.setDept("ECE");
    cout<<t1.getDept()<<endl;
    t2.getInfo();
    return 0;
}

