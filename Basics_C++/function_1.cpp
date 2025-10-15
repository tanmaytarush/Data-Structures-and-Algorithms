/*
1. Functions are a set of code which performs something for you
2. Functions are used to modularize code
3. Functions are used to increase readability
4. Functions are used to use same code multiple times

Types:
1. void -> which doesn't return anything
2. return -> 
3. parameterized
4. non-parameterized
*/

#include<iostream>
using namespace std;

// Pass by Value
void doSomething(int num)
{
    cout<<num<<endl;
    num += 5;
    cout<<num<<endl;
    num += 5;
    cout<<num<<endl;
}

int main()
{
    int num = 10;
    doSomething(num); // A copy goes to the function
    cout<<num<<endl; // Gets the original local value
    return 0;
}