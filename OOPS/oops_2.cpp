/*

Encalsulation :-
Encapsulation is wrapping up data & members functions into a single unit called
class. It is a capsule of data properties and member functions, which in turn is
a class only. Matter of concept is what it defines. It helps in data hiding, meaning 
hiding sensitive information in private access.

Four main pillers of OOPS:-
1. Encapsulation
2. Abstraction
3. Inheritance
4. Polymorphsim

Constructor:-
Constructor is a special method which is invoked automatically when an object
is created. Used for initialization.
- Same name as class
- Consturctor doesn't have a return type
- Only once called (automatically), at object creation
- Memory allocation happens once the constructor is called

*/

#include<iostream>
using namespace std;

class Account{
private:
    double balance;
    string password;  // data hiding

public:
    Account()
    {
        cout<<"Hi! I am a constructor called...\n"; // Constructor called
    }
    string accountID;
    string username;

    void setBalance(int b)
    {
        balance = b;
    }

    int getBalance()
    {
        return balance;
    }
};

int main()
{
    Account a1;  // Constructor call
    a1.accountID = "542365334";
    a1.username = "John";
    cout<<a1.accountID<<endl;
    cout<<a1.username<<endl;
    a1.setBalance(25000);
    cout<<a1.getBalance()<<endl;
    return 0;
}