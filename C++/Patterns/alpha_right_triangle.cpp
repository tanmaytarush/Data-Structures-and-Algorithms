/*

A
A B
A B C
A B C D
A B C D E

*/

#include<iostream>
using namespace std;

void alpha_right_triangle(int n)
{
    for(int i=0; i<n; ++i)
    {
        for(char ch = 'A'; ch<='A'+i; ch++)
        {
            cout<<ch;
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
        alpha_right_triangle(n);
    }
    return 0;
}