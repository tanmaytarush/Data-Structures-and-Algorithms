/*
Question:
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Example:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

Approach:
- We iterate through the intervals and compare them with the newInterval.
- There are three possible cases:
  1. The newInterval is before the current interval: We add the newInterval and update the newInterval to the current interval.
  2. The newInterval is after the current interval: We add the current interval to the result.
  3. The newInterval overlaps with the current interval: We update the newInterval to cover the merged interval.

Complexity Analysis:
- The time complexity of this approach is O(N), where N is the number of intervals.
- We iterate through the intervals once.
- The space complexity is O(1) as we are using a constant amount of additional space.

Code:
*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    vector<vector<int>> insertIntervals(vector<vector<int>>&intervals, vector<int>&newInterval)
    {   
        int n = intervals.size();
        vector<vector<int>> result;

        int i=0;
        while(i<n && intervals[i][1] < newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }

        // for the corresponding merge intervals
        while(i<n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);

            i++;
        }
        result.push_back(newInterval);

        // for the remaining ones
        while(i < n)
        {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    int n;
    cin>>n;

    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<2; ++j)
        {
            cin>>intervals[i][j];
        }
    }

    vector<int> newInterval(2);
    for(int i=0; i<2; ++i)
    {
        cin>>newInterval[i];
    }

    vector<vector<int>> result = sol.insertIntervals(intervals, newInterval);

    cout<<endl;

    for(vector<vector<int>>::iterator it = result.begin(); it != result.end(); ++it)
    {
        for(vector<int>::iterator jt = it->begin(); jt != it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    return 0;
}