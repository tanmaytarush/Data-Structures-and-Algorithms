/*
School has a following grading system:-

a. Below 25 - F
b. 25 to 44 - E
c. 44 to 49 - D
d. 50 to 59 - C
e. 60 to 79 - B
f. 80 and above - A

Ask user to enter marks and give relevant grades
*/

#include<iostream>
using namespace std;

int main()
{
    int marks;
    cin>>marks;

    if(marks < 25)
    {
        cout<<"F"<<endl;
    }

    else if(marks>=25 && marks<44)
    {
        cout<<"E"<<endl;
    }

    else if(marks>=44 && marks<=49)
    {
        cout<<"D"<<endl;
    }

    else if(marks>=50 && marks<60)
    {
        cout<<"C"<<endl;
    }

    else if(marks>=60 && marks<80)
    {
        cout<<"B"<<endl;
    }

    else
    {
        cout<<"A"<<endl;
    }

    return 0;
}
