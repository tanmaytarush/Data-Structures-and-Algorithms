/*

Inheritance :-

When properties and member functions of base class are passed on to derived class.
- Code Reusability
- Parent class is Base class
- Child class is Derived class

For any object created inside the main, firstly the base class constructor is 
called followed by the derived class constructor.
Whereas in case of destructors, firstly the child class memory is deallocated, 
followed by parent class destructor.

Private members are never inherited, and access modifiers work hierarchically.

*/

#include<iostream>
using namespace std;

class Person{
public:
    string name;
    int age;

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    Person(){}
};

class Student : public Person{
public:
    int rollno;

    Student() {}

    Student(string name, int age, int rollno) : Person(name, age){ // Parameterized constructor in inheritance
        cout<<"Child called \n";
        this->rollno = rollno;
    }
    
    void getInfo()
    {
        cout<<"Name : "<<name<<endl;  // Inherited variables
        cout<<"Age : "<<age<<endl;  // Inherited variables
        cout<<"Roll No : "<<rollno<<endl;
    }
};

int main()
{
    Student s1;
    s1.name = "Rahul";
    s1.age = 15;
    s1.rollno = 12;
    s1.getInfo();
    Student s2("Rohan", 20, 23);
    s2.getInfo();
    return 0;
}