/*

Shallow Copy / Deep Copy:-

A shallow copy of an object copies all the member values from one object to another.
On the other hand, a deep copy not only copies the member values but also makes 
copies of any dynamically allocated memory, that the members point to.

Shallow copy is an example of copy constructor only in which the member properties 
are imbibed inside the secondary object mapping to the primary object.
Deep copy comes into picture in a scenario in which the memory is dynamically 
allocated inside the memory.

Shallow Copy in general copies the address also in copy constructor. That's why any 
change in the main variable pointer, changes the value for all objects.

On the other hand, a deep copy creates a new memory in heap, and keeps that 
address pointer in the object memory. It can be achieved by simply allocating a
new heap memory inside the constructor.

*/

#include<iostream>
using namespace std;

class Student{
public:
    string name;
    double cgpa;
    double* grade; // Heap Allocation

    // Copy constructor
    Student(Student &orgObj)
    {
        this->name = orgObj.name;
        this->cgpa = orgObj.cgpa;
        grade = new double; // New memory for deep copy
        *grade = *orgObj.grade;   // Deep Copy
        // To run accordingly any of the above/below statement
        this->grade = orgObj.grade;  // Simple this_pointer dynamic memory access (Shallow Copy)
    }

    // Parameterized constructor
    Student(string name, double cgpa, double gradePoint)
    {
        this->name = name;
        this->cgpa = cgpa;
        grade = new double;  // dynamic allocation of memory
        *grade = gradePoint;  // dereferencing and assigning value
    }

    void getInfo()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"CGPA : "<<cgpa<<endl;
        cout<<"Grade : "<<*grade<<endl;
    }
};

int main()
{
    Student s1("Rahul", 8.9, 10);
    cout<<"Parameterized Constructor Values : "<<endl;
    s1.getInfo();
    Student s2(s1);  // Copy constructor
    cout<<"Copy Constructor Values : "<<endl;
    s2.getInfo();
    cout<<"Updating Values : "<<endl;
    *(s2.grade) = 9.2;
    s1.getInfo();
    cout<<"Mapping changes in shallow copy pointing to same memory : "<<endl; // Updates at both position due to same memory
    s2.getInfo();
    return 0;
}