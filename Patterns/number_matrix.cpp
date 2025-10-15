/*

4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4 

*/

#include<iostream>
using namespace std;

void number_matrix(int n)
{
    for(int i=0; i<2*n-1; ++i)
    {
        for(int j=0; j<2*n-1; ++j)
        {
            int top = i; // Each element is i length from top
            int left = j; // Each element is j length from left
            int right = 2*(n-1) - j; // Each element is 2*(n-1)-j length from right
            int bottom = 2*(n-1) - i; // Each element is 2*(n-1)-i length from left
            cout<< (n - min(min(top, bottom), min(left, right))); // Final value in matrix is n - min_value
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
        number_matrix(n);
    }
    return 0;
}