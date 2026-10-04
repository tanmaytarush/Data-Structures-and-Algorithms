/*

A B C D E
A B C D
A B C
A B
A

*/

#include<iostream>
using namespace std;

void inverted_alpha_triangle(int n)
{
    for(int i=1; i<=n; ++i)
    {
        char s = 'A';
        for(int j=1; j<=n-i+1; ++j)
        {
            cout<<s;
            s = s + 1;
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
        inverted_alpha_triangle(n);
    }
    return 0;
}