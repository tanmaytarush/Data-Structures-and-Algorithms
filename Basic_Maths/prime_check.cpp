/*

You are given an integer n. You need to check if the number is prime or not. Return true if it is a prime number, otherwise return false.
A prime number is a number which has no divisors except 1 and itself.


Examples:
Input: n = 5

Output: true

Explanation: The only divisors of 5 are 1 and 5 , So the number 5 is prime.

Input: n = 8

Output: false

Explanation: The divisors of 8 are 1, 2, 4, 8, thus it is not a prime number.

*/

#include<iostream>
using namespace std;

class Prime{
public:
    int check_prime_bf(int n) // O(N) complexity
    {
        int cnt = 0;
        for(int i=1; i<=n; ++i)
        {
            if(n%i == 0)
            {
                cnt++;
            }
        }
        if(cnt == 2){
            return true;
        }
        else{
            return false;
        }
    }

    int check_prime_opt(int n)
    {
        int cnt=0;
        for(int i=1; i*i<=n; ++i)
        {
            if(n%i==0)
            {
                cnt++;
                if((n/i)!=i)
                {
                    cnt++;
                }
            }
        }
        if(cnt == 2){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    Prime p1;
    int t;
    cin>>t;
    for(int i=0; i<t; ++i)
    {
        int n;
        cin>>n;
        bool prime1 = p1.check_prime_bf(n);
        bool prime2 = p1.check_prime_opt(n);
        cout<<prime1<<" "<<prime2;
    }
    return 0;
}