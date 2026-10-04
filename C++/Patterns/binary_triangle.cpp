/*

1
0 1
1 0 1
0 1 0 1
1 0 1 0 1

*/

#include<iostream>
using namespace std;

void binary_triangle(int n)
{
    int start = 1;
    for(int i=1; i<=n; ++i)
    {
        if(i%2==0)
        {
            start = 0;
        }
        else
        {
            start = 1;
        }
        for(int j=1; j<=i; ++j)
        {
            cout<<start;
            start = 1 - start;
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
        binary_triangle(n);
    }
    return 0;
}
