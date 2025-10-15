/*

** PARAMETERIZED AND FUNCTIONAL RECURSION :- 

- Parameterized recursion refers to the process in which the return is simply specific to
  the parameters of the functions. For example - func(i+1, n-1) .On the other hand, Functional recursion refers to 
  actual operations in the internal function calls. For example - n + func(n-1).

Q.) Problem statement: Given a number ‘N’, find out the sum of the first N natural numbers.

Examples:

Example 1:
Input: N=5
Output: 15
Explanation: 1+2+3+4+5=15

Example 2:
Input: N=6
Output: 21
Explanation: 1+2+3+4+5+6=15


Q.) Factorial of a Number : Iterative and Recursive

Problem Statement: Given a number X,  print its factorial.

To obtain the factorial of a number, it has to be multiplied by all the whole numbers preceding it. More precisely X! = X*(X-1)*(X-2) … 1.

Note: X  is always a positive number. 


*/

#include<iostream>
using namespace std;

class RecursionExamples{
public:
    void sum_n_naturals1(int i, int sum, int n)
    {   
        if(i>n)
        {
            cout<<sum<<endl;
            return;
        }
        sum_n_naturals1(i+1, sum+i, n);
    }

    void sum_n_naturals2(int i, int sum, int n)
    {
        if(i<1)
        {
            cout<<sum<<endl;
            return;
        }
        sum_n_naturals2(i-1, sum+i, n);
    }

    void factorial_numbers1(int i, int fact, int n)
    {
        if(i>n)
        {
            cout<<fact<<endl;
            return;
        }
        factorial_numbers1(i+1, fact*i, n);
    }

    void factorial_numbers2(int i, int fact, int n)
    {
        if(i<1)
        {
            cout<<fact<<endl;
            return;
        }
        factorial_numbers2(i-1, fact*i, n);
    }
};


int main()
{
    RecursionExamples r1;
    int n;
    cin>>n;
    r1.sum_n_naturals1(0, 0, n);
    r1.sum_n_naturals2(n, 0, n);
    r1.factorial_numbers1(1, 1, n);
    r1.factorial_numbers2(n-1, n, n);
}