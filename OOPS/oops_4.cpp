/*

this pointer:-

- this is a special pointer that points to the current object.
- this->prop is same as *(this).prop

Consider the below working scenario:

Suppose there is a pointer which stores the address of an integer, 
int x = 10;
int *ptr = &x;

Later when we dereference this operator, we get the exact value.
Now similarly suppose a pointer variable 'this' is pointing to an 
object location. Similar to how we access object property with 
obj.prop, the same can be done via pointer as (*this).prop or C++ 
provides arrow operator to make this easier as this->prop.


Copy constructor:-

Special constructor (default) used to copy properties of one 
object into another.

*/

#include<iostream>
using namespace std;

class Teacher{
private:
    double salary;

public:
    string name;
    string dept;
    string subject;

    // Non parameterized constructor
    Teacher() {
        cout<<"Hi! The default constructor called...\n";
    }

    // Parameterized constructor
    Teacher(string name, string dept, string subject, double salary)
    {
        cout<<"Hi! Parameterized constructor called... \n";
        this->name = name;  // Left object is the class object, and right one is constructor
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    // Copy constructor
    Teacher(Teacher &orgObj)   // Pass by reference
    {
        cout<<"I am custom copy constructor! \n";
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->subject = orgObj.subject;
        this->salary = orgObj.salary;
    }

    void setSalary(double updatedSalary)
    {   
        salary = updatedSalary;
    }

    double getSalary()
    {
        return salary;
    }

    void getInfo()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Department : "<<dept<<endl;
        cout<<"Subject : "<<subject<<endl;
        cout<<"Salary : "<<salary<<endl;
    }
};


int main()
{
    Teacher t1;  // Non parameterized constructor
    t1.name = "Tanmay Dikshit";
    t1.dept = "ECE";
    t1.subject = "C++";
    t1.setSalary(25000);
    cout<<t1.name<<endl;
    cout<<t1.dept<<endl;
    cout<<t1.subject<<endl;
    cout<<t1.getSalary()<<endl;

    Teacher t2("Prantik", "IT", "C++", 25000);  // Parameterized constructor
    t2.getInfo();

    Teacher t3(t2);  // Copy constructor
    t3.getInfo();
    return 0;
}