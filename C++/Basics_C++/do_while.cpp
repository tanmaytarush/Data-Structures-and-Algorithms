/*
Executes the complete loop at least once even if the condition doesn't meet 
in the block statement.
*/

#include<iostream>
using namespace std;

int main()
{
    int i=2;
    do
    {
        cout<<"Striver"<<i<<endl;
        i=i+1;
    } while(i<=1);
    cout<<"i at the end : "<<i;
    return 0;
}