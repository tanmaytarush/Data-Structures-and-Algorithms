/*

Divisors of a Number :-

You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order.
A number which completely divides another number is called it's divisor.

Examples:
Input: n = 6

Output = [1, 2, 3, 6]

Explanation: The divisors of 6 are 1, 2, 3, 6.

Input: n = 8

Output: [1, 2, 4, 8]

Explanation: The divisors of 8 are 1, 2, 4, 8.

*/

#include<iostream>
#include<vector>
using namespace std;

class Divisors{
public:
    void print_divisors(int n) // O(N) complexity
    {
        for(int i=1; i<=n; ++i)
        {
            if(n%i==0)
            {
                cout<<i<<" ";
            }
        }
    }

    void divisors_opt(int n)  // O(sqrt(N)) complexity
    {
        for(int i=0; i<=sqrt(n); ++i)  // O(sqrt(N))
        {
            if(n%i==0)
            {
                cout<<i<<" ";
                if((n/i) != i)  
                {
                    cout<<(n/i)<<" ";
                }
            }
        }
    }

    void divisors_vector(int n)
    {
        // Total complexity -> [O(sqrt(N)) + O(N*logN) + O(N)]
        vector<int> ls;
        for(int i=0 ; i<=sqrt(n); ++i) // O(sqrt(N))
        {
            if(n%i==0)
            {
                ls.push_back(i); // O(N*logN)
                if(n/i != i)
                {
                    ls.push_back(n/i);
                }
            }
        }
        sort(ls.begin(), ls.end()); // O(N)
        for(auto it : ls)
        {
            cout<<it<<" ";
        }
    }
};

int main()
{
    Divisors d1;
    int t;
    cin>>t;

    for(int i=0; i<t; ++i)
    {
        int n;
        cin>>n;
        d1.print_divisors(n);
        d1.divisors_opt(n);
        d1.divisors_vector(n);
    }
    return 0;
}