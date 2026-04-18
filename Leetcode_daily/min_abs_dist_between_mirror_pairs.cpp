/*

You are given an integer array nums.

A mirror pair is a pair of indices (i, j) such that:

0 <= i < j < nums.length, and
reverse(nums[i]) == nums[j], where reverse(x) denotes the integer formed by reversing the digits of x. Leading zeros are omitted after reversing, for example reverse(120) = 21.
Return the minimum absolute distance between the indices of any mirror pair. The absolute distance between indices i and j is abs(i - j).

If no mirror pair exists, return -1.

 

Example 1:

Input: nums = [12,21,45,33,54]

Output: 1

Explanation:

The mirror pairs are:

(0, 1) since reverse(nums[0]) = reverse(12) = 21 = nums[1], giving an absolute distance abs(0 - 1) = 1.
(2, 4) since reverse(nums[2]) = reverse(45) = 54 = nums[4], giving an absolute distance abs(2 - 4) = 2.
The minimum absolute distance among all pairs is 1.

Example 2:

Input: nums = [120,21]

Output: 1

Explanation:

There is only one mirror pair (0, 1) since reverse(nums[0]) = reverse(120) = 21 = nums[1].

The minimum absolute distance is 1.

Example 3:

Input: nums = [21,120]

Output: -1

Explanation:

There are no mirror pairs in the array.

*/


#define LOG(x) cerr<<#x<<" "<<x<<endl;

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution
{
    public:
    int MinMirrorPairDistance(vector<int> &nums)
    {
        auto reverseNum = [](int x)
        {
            int y = 0;
            while(x > 0)
            {
                int rem = x%10;
                y = y*10 + rem;
                x = x/10;
            }
            return y;
        };

        unordered_map<int, int> prev;
        int n = nums.size();
        int ans = n + 1;

        for(int i=0; i<n; ++i)
        {
            int x = nums[i];
            int reversed = reverseNum(x);

            if(prev.count(x))
            {
                ans = min(ans, abs(prev[x] - i)); // store exact numbers to map, check with reversed one, if found update ans with distance
            }

            prev[reversed] = i;
        }

        return (ans == n+1) ? -1 : ans;
    }
};

int main()
{
    Solution sol;

    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; ++i)
    {
        cin>>nums[i];
    }

    int result = sol.MinMirrorPairDistance(nums);

    cout<<result<<std::endl;

    return 0;
}