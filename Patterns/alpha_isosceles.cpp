/*

    A
   ABA
  ABCBA
 ABCDBCA
ABCDEDCBA

*/

#include<iostream>
using namespace std;

void alpha_isosceles(int n)
{
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n-i; ++j)
        {
            cout<<" ";
        }
        for(char k='A'; k<='A'+i-1; ++k)
        {
            cout<<k;
        }
        for(char l='A'+i-2; l>='A'; --l)
        {
            cout<<l;
        }
        cout<<endl;
    }
}

// It's always better to go with zero based indexing when working with spaces
void alpha_isosceles_2(int n)
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n-i-1; ++j)
        {
            cout<<" ";
        }

        char ch = 'A';
        int breakpoint = (2*i+1)/2;
        for(int j=1; j<=2*i+1; j++)
        {
            cout<<ch;
            if(j<=breakpoint) ch++;
            else ch--;
        }

        for(int j=0; j<n-i-1; ++j)
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
        alpha_isosceles(n);
        alpha_isosceles_2(n);
    }
    return 0;
}