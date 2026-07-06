/*

1288 :  Remove Covered Intervals
Link -> https://leetcode.com/problems/remove-covered-intervals/description/?envType=daily-question&envId=2026-07-06

Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.

 

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1

Constraints:

1 <= intervals.length <= 1000
intervals[i].length == 2
0 <= li < ri <= 105
All the given intervals are unique.

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Pair
{
    public:
    int first;
    int second;

    Pair(int first, int second)
    {
        this->first = first;
        this->second = second;
    }
};

bool compare(Pair p1, Pair p2)
{
    if(p1.first == p2.first) return p1.second > p2.second;
    return (p1.first < p2.first);
}

class Solution
{
    public:
    int removeIntervals(vector<Pair>&nums)
    {
        int n = nums.size();
        int count = 0;
        int maxEnd = -1;
        sort(nums.begin(), nums.end(), compare);

        for(auto &it : nums)
        {
            if(it.second > maxEnd)
            {
                count++;
                maxEnd = it.second;
            }
        }
        return count;
    }
};  

int main()
{
    Solution sol;
    int n;
    cin>>n;

    vector<Pair>nums;
    for(int i=0; i<n; ++i)
    {
        int first, second;
        cin>>first>>second;
        nums.push_back(Pair(first, second));
    }

    int ans = sol.removeIntervals(nums);

    cout<<ans<<endl;

    return 0;
}