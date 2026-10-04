/*QUESTION:
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

APPROACH:
To calculate the trapped water, we can use the two-pointer approach. We initialize two pointers, one at the beginning of the array (`left`) and another at the end of the array (`right`). We also maintain two variables, `leftMax` and `rightMax`, to keep track of the maximum bar height encountered from the left and right side, respectively.

1. Initialize `left` to 0 and `right` to the last index of the array.
2. Initialize `leftMax` and `rightMax` to the minimum integer value (`INT_MIN`).
3. Initialize `ans` (trapped water) to 0.
4. Iterate while `left` is less than or equal to `right`:
    a. If `height[left]` is less than `height[right]`:
        - Update `leftMax` if `height[left]` is greater than the current `leftMax`.
        - Calculate the amount of water trapped at the current `left` index by subtracting `height[left]` from `leftMax` and add it to `ans`.
        - Increment `left` by 1.
    b. Else:
        - Update `rightMax` if `height[right]` is greater than the current `rightMax`.
        - Calculate the amount of water trapped at the current `right` index by subtracting `height[right]` from `rightMax` and add it to `ans`.
        - Decrement `right` by 1.
5. Return the final value of `ans`.

CODE:*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

class Solution
{
    public:

    // Time Complexity -> O(3N)
    // Space Complexity -> O(2N)
    int trappingRainwaterBF(vector<int> &arr) 
    {
        int n = arr.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = arr[0];
        for(int i=1; i<n; ++i)
        {
            leftMax[i] = max(leftMax[i-1], arr[i]);
        }

        rightMax[n-1] = arr[n-1];
        for(int i=n-2; i>=0; --i)
        {
            rightMax[i] = max(rightMax[i+1], arr[i]);
        }

        int total = 0;
        for(int i=0; i<n; ++i)
        {
            if(arr[i] < leftMax[i] && arr[i] < rightMax[i])
            {
                total += min(leftMax[i], rightMax[i]) - arr[i];
            }
        }

        return total;
    }  

    // Time Complexity -> O(N)
    // Space Complexity -> O(1)
    int trappingRainwaterOptimal(vector<int>& height) {
        int n = height.size();
        int rMax = 0;
        int lMax = 0;
        int total = 0;

        int l = 0;
        int r = n-1;

        while(l < r)
        {
            if(height[l] < height[r])
            {
                if(lMax > height[l])
                {
                    total += lMax - height[l];
                }
                else
                {
                    lMax = height[l];
                }
                l++;
            }
            else
            {
                if(rMax > height[r])
                {
                    total += rMax - height[r];
                }
                else
                {
                    rMax = height[r];
                }
                r--;
            }
        }
        return total;
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
    
    int totalWater1 = sol.trappingRainwaterBF(arr);
    int totalWater2 = sol.trappingRainwaterOptimal(arr);

    cout<<totalWater1<<endl;
    cout<<totalWater2<<endl;

    return 0;
}

/*
COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(N), where N is the number of elements in the `height` array. We iterate through the array once.
- The space complexity is O(1) as we only use a constant amount of extra space to store variables.
*/


