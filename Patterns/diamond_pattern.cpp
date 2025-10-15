/*

Diamond Pattern

*/

#include<iostream>
using namespace std;

void straight_pyramid(int n)
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n-i-1; ++j)
        {
            cout<<" ";
        }
        for(int k=0; k<2*i+1; ++k)
        {
            cout<<"*";
        }
        for(int l=0; l<n-i-1; ++l)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}

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
        for(int l=0; l<i; ++l)
        {
            cout<<" ";
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
        straight_pyramid(n);
        inverted_pyramid(n);
    }
    return 0;
}