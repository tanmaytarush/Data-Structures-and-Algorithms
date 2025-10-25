/*
QUESTION:
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals and return an array of non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

APPROACH:
To merge overlapping intervals, we can follow these steps:
1. Sort the intervals based on the start time.
2. Initialize a vector `ans` to store the merged intervals.
3. Add the first interval from the sorted intervals to the `ans` vector.
4. Iterate through the remaining intervals:
   - If the start time of the current interval is less than or equal to the end time of the last interval in the `ans` vector, it means they overlap. Update the end time of the last interval in the `ans` vector if necessary.
   - If the start time of the current interval is greater than the end time of the last interval in the `ans` vector, it means they don't overlap. Add the current interval to the `ans` vector.
5. Return the `ans` vector as the merged non-overlapping intervals.

CODE:
*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>

vector<vector<int>> mergeOverlappingIntervalsBF(vector<vector<int>> &arr)
{
    int n = arr[0].size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; ++i)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        
        if(!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }

        for(int j=i+1; j<n; ++j)
        {
            if(arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

vector<vector<int>> mergeOverlappingIntervalsOptimal(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; ++i)
    {
        if(ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n; 

    vector<vector<int>> arr(n, vector<int>(2));
    for(int i=0; i<n; ++i)
    {
            cin>> arr[i][0] >> arr[i][1];
    }

    vector<vector<int>> ans1 = mergeOverlappingIntervalsBF(arr);
    vector<vector<int>> ans2 = mergeOverlappingIntervalsOptimal(arr);

    cout << "Brute Force Solution:" << endl;
    for(const auto& interval : ans1)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    cout << "Optimal Solution:" << endl;
    for(const auto& interval : ans2)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(nlogn), where n is the number of intervals in the input.
The sorting step takes O(nlogn) time, and the merging step takes O(n) time.
Overall, the time complexity is dominated by the sorting step.
SPACE COMPLEXITY: O(n), where n is the number of intervals in the input.
We are using additional space to store the merged intervals in the `ans` vector.
*/