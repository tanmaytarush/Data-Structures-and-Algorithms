/*

1.     1
12.   21
123. 321
12344321

*/

#include<iostream>
using namespace std;

void twin_towers(int n)
{
    // int start = 1;
    for(int i=1; i<=n; ++i)
    {
        // int start = 1;
        for(int j=1; j<=i; ++j)
        {
            cout<<j;
            //start++;
        }
        
        for(int k=1; k<=2*(n-i); ++k)
        {
            cout<<" ";
        }

        //int start2 = 1;
        for(int j=i; j>=1; j--)
        {
            cout<<j;
            //start2++;
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
        twin_towers(n);
    }
    return 0;
}