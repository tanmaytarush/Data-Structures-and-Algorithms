/*

*        *
**      **
***.   ***
****  ****
**********
****. ****
***.   ***
**.     **
*.       *

*/

#include<iostream>
using namespace std;

void butterfly(int n)
{
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=i; ++j)
        {
            cout<<"*";
        }
        for(int j=1; j<=2*(n-i); ++j)
        {
            cout<<" ";
        }
        for(int j=1; j<=i; ++j)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i=1; i<=n-1; ++i)
    {
        for(int j=1; j<=n-i; ++j)
        {
            cout<<"*";
        }
        for(int j=1; j<=2*i; ++j)
        {
            cout<<" ";
        }
        for(int j=1; j<=n-i; ++j)
        {
            cout<<"*";
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
        butterfly(n);
    }
    return 0;
}