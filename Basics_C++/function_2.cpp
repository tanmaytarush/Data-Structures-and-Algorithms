// Function pass by reference

#include<iostream>
using namespace std;

void doSomething(string &s) // Getting the address of the original string 
{
    s[0] = 'w';
    cout<<s<<endl;
}

int main()
{
    string s = "tanmay";
    doSomething(s);
    cout<<s<<endl;
    return 0;
}