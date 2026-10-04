/*

** RECURSION:-

- When a function calls itself until a specified condition is met.
    void print() // Infinite recursion call with stack overflow
    {
        cout<<1<<endl;
        print();
    }
    int main()
    {
        print();
        return 0;
    }

- Whenver function call keeps happening, the stack keeps overloading, with previous 
  stack waiting for the current call.

- Now, base condition is where the call stops. The current function call value is returned
  to the function calls stacked already.
    cnt = 0;
    void f()
    {
        if(cnt == 4) // Base Condition
            return;
        cnt++;
        cout<<cnt;
        f();
    }
    int main()
    {
        f();
    }

*/

#include<iostream>
using namespace std;

int cnt = 0;
void recursion_intro() // Function
{
    if(cnt == 3) // Base Condition
    {
        return;
    }
    cnt++;
    cout<<cnt;
    recursion_intro(); // Recursion call forming recursion tree
}

int main()
{
    recursion_intro();
    return 0;
}