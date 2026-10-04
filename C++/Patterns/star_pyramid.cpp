/*

Pyramid Pattern (1,3,5,7,9)

*/

#include<iostream>
using namespace std;

void star_pyramid(int n)
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n-i; ++j)
        {
            cout<<" ";
        }
        for(int k=0; k<(2*i)+1; ++k)
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
        star_pyramid(n);
    }
    return 0;
}
