/*

1
2 3
4 5 6 
7 8 9 10

*/

#include<iostream>
using namespace std;

void number_right_triangle(int n)
{
    int number = 1;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=i; ++j)
        {
            cout<<number<<" ";
            number++;
        }
        cout<<endl;
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; ++i)
    {
        int n;
        cin>>n;
        number_right_triangle(n);
    }
    return 0;
}