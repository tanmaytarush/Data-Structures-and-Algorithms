/*

Static Keyword :-

Variables declared as static are instantiated once and initialized once for the complete
lifetime of the program.

Static variables are created and instantiated once. They are shared by all objects of 
the class.

*/

#include<iostream>
using namespace std;

void func()
{
    static int x = 0;
    cout<<"x : "<<x<<endl;
    x++;   // Increments because static keyword remains in stack for complete duration
}

class A{
public:
    int x;
    void incX()
    {
        x++;   // Incrementing the value
    }
};

int main()
{
    func();
    func();
    func();

    A obj1;
    obj1.x = 0;
    cout<<obj1.x<<endl;
    obj1.incX();    // Class value stacked from static keyword
    cout<<obj1.x<<endl;

    return 0;
}