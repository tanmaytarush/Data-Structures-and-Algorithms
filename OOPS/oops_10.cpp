/*

Abstraction :-

Hiding all the unnecessary details and showing only the important parts. Handled via 
access modifiers/specifiers. Implemented via private, public and protected.

Abstract Classes:
- Abstract classes are used to provide a base class from which other classes can be derived.
- They cannot be instantiated (no object creation) and can only be inherited.
- Is used to define an interface for derived class.
- No objects are created through the abstract class. Only a blueprint of other classes.
- Abstract class is used only for the purpose of inheritance.

*/

#include<iostream>
using namespace std;

class Shape{  // with pure virtual function, it automatically becomes abstract class
    virtual void draw() = 0;  // pure virtual function
};

class Circle : public Shape {
    public:
        void draw()
        {
            cout<<"Draw a Circle..."<<endl;
        }
};

int main()
{
    Circle c1;  // Only derived class prepares an object
    c1.draw();
    return 0;
}