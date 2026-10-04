/*

Polymorphism (Multi-forms) :- Constructor overloading is a prime example

Polymorphism is the ability of the objects to take on different forms or behave in 
different ways depending upon the context in which it is used.

1. Compile-time polymorphism (Constructor overloading, Function overloading) -> Similar to 
   constructor overloading, when the name of the function/constructor is same, but the 
   function parameters are different (type/number), then it is a compile time polymorphism.

2. Run-time (Dynamic) polymorphism -> Parent and Child both contain the same function with different
   implementation. The parent class is said to be overridden. Example - Function overriding
   (based on the concept of inheritance). Similarly a virtual function is a member
   function that you expect to be redefined in derived class. It can be implement using 
   the 'virtual' keyword before any of the function name.

* Virtual Functions 
    - Virtual functions are dynamic in nature.
    - Defined by the keyword 'virtual' inside a base class and are always declared with 
      a base class and overridden in the child class.
    - Virtual function is called during runtime.
 
*/

#include<iostream>
using namespace std;

class Print{
public:
    void show(int x)
    {
        cout<<"Integer : "<<x<<endl;  // Polymorphism basics
    }
    void show(char ch)
    {
        cout<<"Character : "<<ch<<endl;  // Polymorphism basics
    }

    void getInfo()
    {
        cout<<"Hello from base class"<<endl; // Function overloading
    }
    virtual void hello()
    {
        cout<<"Parent virtual called"<<endl;  // Function overriding
    }
};

class Child : public Print{
public:
    void getInfo()
    {
        cout<<"Hello from child class"<<endl;  // Function overloading
    }
    void hello()
    {
        cout<<"Child virtual called"<<endl;  // Function overriding
    }
};

int main()
{
    Print p1;
    p1.show(10); // Integer value overloaded
    p1.show('t'); // Character value overloaded
    p1.getInfo(); // Parent called by function overloading
    p1.hello(); // Child called through virtual function

    Child c1;
    c1.getInfo(); // Child called by function overloading 
    c1.hello(); // Child called through virtual function

    return 0;
}