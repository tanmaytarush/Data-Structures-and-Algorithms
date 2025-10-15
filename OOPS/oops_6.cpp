/*

Destructors:-

Whenever an object in the memory is allocated dynamically, it needs to be deallocated
in the same manner dynamically. If 'new' keyword is used to allocate a new memory in
heap, 'delete' keyword is used to deallocate that heap memory, basically the 
constructor.

*/

#include<iostream>
using namespace std;

class Student{
public:
    string name;
    double *cgpaPtr;
    
    // Constructor
    Student(string name, double cgpa)
    {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    // Destructor (Called automatically if not assigned)
    ~Student()
    {
        cout<<"Hi! Everything deleted \n";
        delete cgpaPtr;
    }

    void getInfo()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"CGPA : "<<*cgpaPtr<<endl;
    }
};

int main()
{
    Student s1("Rahul", 8.6);
    s1.getInfo();
    return 0;
}