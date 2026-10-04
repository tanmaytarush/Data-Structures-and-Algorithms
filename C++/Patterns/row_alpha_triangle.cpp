/*

A 
B B
C C C
D D D D
E E E E E

*/

#include<iostream>
using namespace std;

void row_alpha_triangle(int n)
{
    for(int i=1; i<=n; ++i)
    {
        char ch = 'A' + i - 1;
        for(int j=1; j<=i; ++j)
        {
            cout<<ch<<" ";
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
        row_alpha_triangle(n);
    }
    return 0;
}