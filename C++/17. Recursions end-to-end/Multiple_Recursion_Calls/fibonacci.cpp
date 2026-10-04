/*

Print Fibonacci Series

*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    int fibonacci(int n)
    {
        if(n<=1)
        {
            return n;
        }

        int last = fibonacci(n-1);
        int slast = fibonacci(n-2);

        return last+slast;
    }
};

int main()
{
    Solution sol;
    int n;
    cin>>n;

    int result = sol.fibonacci(n);

    cout<<result<<endl;

    return 0;
}