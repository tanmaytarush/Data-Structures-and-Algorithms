/*

Inverted Pyramid (7,5,3,1)

*/

#include<iostream>
using namespace std;

void inverted_pyramid(int n)
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<i; ++j)
        {
            cout<<" ";
        }
        for(int k=0; k<(2*(n-i)-1); ++k)
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
        inverted_pyramid(n);
    }
    return 0;
}