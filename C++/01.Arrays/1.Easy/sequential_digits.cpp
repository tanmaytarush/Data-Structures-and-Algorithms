/*
QUESTION:-
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

Example 1:
Input: low = 100, high = 300
Output: [123,234]

Example 2:
Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
*/

/*
APPROACH:-
-> Any sequential digit number must start with a digit from 1 to 9.
-> For each possible starting digit, keep appending the next digit until it is no longer valid.
-> If the generated number lies inside [low, high], add it to the answer.
-> Since the largest sequential digit number is 123456789, the search space is tiny.
*/

// CODE:-
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;

        for(int start = 1; start <= 9; ++start)
        {
            int num = start;
            int nextDigit = start + 1;

            while(num <= high && nextDigit <= 9)
            {
                num = num * 10 + nextDigit;

                if(num >= low && num <= high)
                {
                    ans.push_back(num);
                }

                ++nextDigit;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int low, high;
    cin >> low >> high;

    Solution sol;
    vector<int> ans = sol.sequentialDigits(low, high);

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}

// TIME COMPLEXITY = O(1)
// SPACE COMPLEXITY = O(1)
