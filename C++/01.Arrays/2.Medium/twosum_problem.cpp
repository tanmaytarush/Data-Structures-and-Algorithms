/*
QUESITON:-
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
*/

/*
Approach:

-> Create an empty map to store the elements and their corresponding indices.
>  Iterate through the input array, nums, and for each element:
    Calculate the complement by subtracting the current element from the target value.
    Check if the complement exists in the map.
    If the complement exists, return the indices of the current element and the complement.
    If the complement does not exist, add the current element and its index to the map.
-> If no solution is found, return an empty vector or a message indicating no solution exists.
*/

// CODE:-
#include<iostream>
using namespace std;
#include<map>
#include<vector>
#include<string>

vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
    sort(arr.begin(), arr.end()); // sort() now recognized
    int left = 0, right = n - 1;
    vector<pair<int,int>> result;

    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            result.push_back({arr[left], arr[right]});
            left++;
            right--;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    if (result.empty())
        result.push_back({-1, -1});

    return result;
}


vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> mpp;
    int n = nums.size();
    for(int i=0; i<n; ++i)
    {
        int sum = nums[i];
        int rem = target - sum;
        if(mpp.find(rem) != mpp.end())
        {
            return {mpp[rem], i};
        }
        mpp[sum] = i;
    }
    return {-1};
}


int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;

    // Using the optimal map-based approach (returns indices)
    vector<int> res = twoSum(nums, target);
    if(res.size() == 2 && res[0] != -1)
        cout << "[" << res[0] << ", " << res[1] << "]" << endl;
    else
        cout << "No solution exists" << endl;

    // If you want to use the pair-value approach (returns values, not indices)
    // vector<pair<int,int>> res2 = twoSum(nums, target, n);
    // for(auto &p : res2)
    //     cout << "[" << p.first << ", " << p.second << "]" << endl;

    return 0;
}

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(N)