// Write a program to check if a person is adult or not

#include<iostream>
using namespace std;

int main()
{
    int age;
    cout<<"Enter age : ";
    cin>>age;

    if(age > 18)
    {
        cout<<"Adult!"<<endl;
    }
    else
    {
        cout<<"Not an Adult!"<<endl;
    }
    return 0;
}