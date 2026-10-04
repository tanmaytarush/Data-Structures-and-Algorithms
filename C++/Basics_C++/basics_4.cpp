// String and Getline for storing string variables

/* 
When using cin directly with the string variable it only considers string
value which is before space. For example :- for "ABC DEF" it only prints
ABC. So to handle this case we use getline() function.
*/

#include<iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    cout<<s;

    getline(cin, s);
    cout<<s;
}