/*

* * * *
*     *
*     *
* * * *

*/

#include<iostream>
using namespace std;

void hollow_square(int n)
{
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if((i==1 || i==n) || (j==1 || j==n))
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
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
        hollow_square(n);
    }
    return 0;
}