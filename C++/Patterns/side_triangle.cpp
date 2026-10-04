/*
Side triangle rotated by 90 degrees right
*/

#include<iostream>
using namespace std;

void side_triangle(int n)
{
    for(int i=1; i<=2*n-1; ++i)
    {
        int stars = i;
        if(i>n) stars = 2*n-i;
        for(int j=1; j<=stars; ++j)
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
        side_triangle(n);
    }
    return 0;
}