/*

E
D E
C D E
B C D E 
A B C D E

*/

#include<iostream>
using namespace std;

void inverse_alpha_triangle(int n)
{
    for(int i=1; i<=n; ++i)
    {
        for(char j='A'+n-i; j<='A'+n-1; ++j)
        {
            cout<<j<<" ";
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
        inverse_alpha_triangle(n);
    }
    return 0;
}