/*

Sample Class Description :-

Access Modifier :-
1. Private - Attributes accessible inside the class
2. Public - Attributes accessible inside and outside the class
3. Protected - Attributes accessible inside a class and it's derived class

*/

#include<iostream>
#include<string>
using namespace std;

class Teacher{
    // private:
    // attributes or properties
private:
    double salary; // Private attribute

public:  // Public attributes below this file
    string name;
    string dept;
    string subject;

    // methods or member functions
    void changeDept(string newDept)
    {
        dept = newDept;
    }

    void setSalary(int s)  // Setter function to set private variable values
    {
        salary = s;
    }

    double getSalary()  // Getter function to get the value in main function
    {
        return salary;
    }
};

class Student{
    string name;
    int rollno;
    int age;
};

int main()
{
    Teacher t1;
    t1.name = "Tanmay";
    t1.subject = "C++";
    t1.dept = "Computer Science";
    // t1.salary = 25000;  // Line shows error because it is a private member

    t1.setSalary(25000);
    cout<<t1.name<<endl;
    cout<<t1.getSalary()<<endl;  // Now accessible through getter and setter

    // Teacher t2;
    // Teacher t3;
    // Teacher t4;
    return 0;
}

