/*

Problem Statement: Given an integer N. Print the Fibonacci series up to the Nth term.

Examples:

Example 1:
Input: N = 5
Output: 0 1 1 2 3 5
Explanation: 0 1 1 2 3 5 is the fibonacci series up to 5th term.(0 based indexing)

Example 2:
Input: 6

Output: 0 1 1 2 3 5 8
Explanation: 0 1 1 2 3 5 8 is the fibonacci series upto 6th term.(o based indexing)

*/

#include<iostream>
using namespace std;

class Fibonacci{
public:
    int fibonacci_iterative(int n) // O(N) time complexity
    {
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;

        int a = 0;
        int b = 1;
        int c = 0;
        int i = 2;
        while(i<=n)
        {
            c = a+b;
            a = b;
            b = c;
            i++;
        }
        return c;
    }

    int fibonacci_recursive(int n) // O(2^N) time complexity
    {
        if(n<=1)
            return n;
        int last = fibonacci_recursive(n-1);
        int slast = fibonacci_recursive(n-2);
        return last + slast;
    }
};

int main()
{
    Fibonacci f1;
    int n;
    cin>>n;
    cout<<f1.fibonacci_iterative(n)<<endl;
    cout<<f1.fibonacci_recursive(n)<<endl;
    return 0;
}