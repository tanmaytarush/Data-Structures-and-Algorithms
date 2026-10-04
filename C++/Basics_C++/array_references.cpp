/*
Arrays in C++ always goes through references
*/


#include<iostream>
using namespace std;

void doSomething(int arr[], int n)
{
    arr[0]+=100;
    cout<<"Value inside function : "<<arr[0]<<endl;
}

int main()
{
    int n=5;
    int arr[5];
    for(int i=0; i<5; ++i)
    {
        cin>>arr[i];
    }

    doSomething(arr, n);
    cout<<"Value inside main : "<<arr[0]<<endl;
    return 0;
}

