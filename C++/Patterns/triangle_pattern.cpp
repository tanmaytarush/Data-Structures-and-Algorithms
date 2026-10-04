/*

*
* *
* * *
* * * *

*/

#include<iostream>
using namespace std;

void triangle_pattern(int n)
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            cout<<"* ";
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
        triangle_pattern(n);
    }
    return 0;
}