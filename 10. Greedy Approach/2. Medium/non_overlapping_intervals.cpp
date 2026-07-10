/*
Question:
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Approach:
- We sort the intervals based on the end time in ascending order.
- We initialize a count variable to keep track of the number of intervals that need to be removed.
- We initialize the end variable to store the end time of the first interval.
- Then, we iterate through the intervals starting from the second interval.
- If the start time of the current interval is less than the end time of the previous interval, it means there is an overlap.
- In that case, we increment the count variable since we need to remove this interval to make the rest non-overlapping.
- Otherwise, if there is no overlap, we update the end variable to the end time of the current interval.
- Finally, we return the count variable, which represents the minimum number of intervals to remove.

Complexity Analysis:
- The time complexity of this approach is O(NlogN), where N is the number of intervals.
- Sorting the intervals takes O(NlogN) time, and iterating through the intervals takes O(N) time.
- The space complexity is O(1) as we are not using any additional data structures.

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
    // use static because no object required to access, can be done directly
    static bool compare(const vector<int>&a, const vector<int>&b)
    {
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }

    int nonOverlapping(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if(n==0) return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int kept = 1;
        int end = intervals[0][1];

        for(int i=1; i<n; i++)
        {
            if(intervals[i][0] >= end)
            {
                kept++;
                end = intervals[i][0];
            }
        }

        return n - kept;
    }
};

int main()
{
    Solution sol;
    int n;
    cin>>n;

    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2; j++)
        {
            cin>>intervals[i][j];
        }
    }

    int result = sol.nonOverlapping(intervals);

    cout<<result<<endl;

    return 0;
}
