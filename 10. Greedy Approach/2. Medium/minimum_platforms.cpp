/*
Question:
Given arrival and departure times of all trains that reach a railway station, find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train, but we can have the arrival time of one train equal to the departure time of another. At any given instance of time, the same platform cannot be used for both the departure of a train and the arrival of another train. In such cases, we need different platforms.

Example:
Input: n = 6
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation:
Minimum 3 platforms are required to safely arrive and depart all trains.

Approach:
- We sort the arrival and departure arrays in non-decreasing order.
- We initialize variables 'i', 'j', 'plat', and 'ans' to 0.
- We iterate over the arrival array using 'i' and departure array using 'j'.
- If the arrival time at index 'i' is less than or equal to the departure time at index 'j', it means a train is arriving and we need an additional platform.
  - So, we increment 'i' and 'plat'.
  - We update 'ans' with the maximum value of 'ans' and 'plat'.
- If the arrival time is greater than the departure time, it means a train has departed and we can free up a platform.
  - So, we increment 'j' and decrement 'plat'.
- Finally, we return 'ans' as the minimum number of platforms required.

Complexity Analysis:
- The time complexity of this approach is O(NlogN), where N is the number of trains.
- We sort the arrival and departure arrays, which takes O(NlogN) time.
- The space complexity is O(1) as we use only a constant amount of extra space.

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
    int minPlatformsBF(vector<int>&arr, vector<int>&dep)
    {
        int n = arr.size();
        int ans = 1;
        for(int i=0; i<n; ++i)
        {
            int count = 1;
            for(int j=i+1; j<n; ++j)
            {
                if((arr[i]>=arr[j] && arr[i]<=dep[j]) || 
                    (arr[j]>=arr[i] && arr[j]<=dep[i]))
                {
                    count++;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }

    int minPlatformsOpt(vector<int>&arr, vector<int>&dep)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int i=0;
        int j=0;
        int count = 0;
        int ans = 0;

        while(i < n)
        {
            if(arr[i] <= dep[j])
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    vector<int> dep(n);
    for(int j=0; j<n; ++j)
    {
        cin>>dep[j];
    }

    int res1 = sol.minPlatformsBF(arr, dep);
    cout<<res1<<endl;

    int res2 = sol.minPlatformsOpt(arr, dep);
    cout<<res2<<endl;

    return 0;
}