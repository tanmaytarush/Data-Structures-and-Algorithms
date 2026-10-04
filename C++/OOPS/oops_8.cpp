/*

Types of Inheritance:-

1. Single Inheritance - When properties are passed on from one base class to only
   one child class, in that case we perform single inheritance in our system.
   For example - class Person -> class Student transfer.

2. Multilevel Inheritance - When properties are passed from one base class to 
   multiple child classes, in that case we term the process as multilevel 
   inheritance. For example - class Person -> class Student -> class GradStudent.

3. Multiple Inheritance - When properties are passed from multiple base class 
   to a single child class, in that case we term the process as multiple 
   inheritance. For example - (class Base1 && class Base2) -> class Child.

4. Hierarchical Inheritance - When multiple child classes inherit properties from
   a single base class, in that case we term the process as hierarchical 
   inheritance. For example - class Base -> (class Child1 && class Child 2).

5. Hybrid Inheritance - A mix of all kind of inheritance basically. 

*/

#include<iostream>
#include<string>
using namespace std;

class Person{
public:
    string name;
    int age;
};

class Teacher{
public:
    string designation;
    int year;
};

class Student : public Person{   // Multi-level Inheritance 
public:
    int rollno;
};

class GradStudent : public Student{    // Multi-level Inheritance
public:
    int researchArea;
};

class TA : public Teacher, public Person{   // Multiple Inheritance (only from Base Class)
public:
    int salary;
};

int main()
{
    GradStudent s1;
    s1.name = "Tony Stark";
    s1.age = 50;
    cout<<s1.name<<" -> "<<s1.age<<endl;

    TA t1;
    t1.name = "Michael Jordan";
    t1.age = 28;
    t1.designation = "VLSI Design";
    cout<<t1.name<<"->"<<t1.age<<"->"<<t1.designation<<endl;
    return 0;
}