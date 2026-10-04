/*
Problem Statement: Given an array nums of length n, every integer in the array appears twice except for two integers. Identify and return the two integers that appear only once in the array. Return the two numbers in ascending order.

For example, if nums = [1, 2, 1, 3, 5, 2], the correct answer is [3, 5], not [5, 3].

Examples
Example 1:
Input:
 nums = [1, 2, 1, 3, 5, 2]
Output:
 [3, 5]
Explanation:

The integers 3 and 5 have appeared only once.

Example 2:
Input:
 nums = [-1, 0]
Output:
 [-1, 0]
Explanation:

The integers -1 and 0 have appeared only once.
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> singleNumberBF(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mpp;
    vector<int> ans;

    for(int i=0; i<n; ++i)
    {
        mpp[nums[i]]++;
    }

    for(auto it : mpp)
    {
        if(it.second == 1)
        {
            ans.push_back(it.first);
        }
    }
    
    return ans;
}

vector<int> singleNumberOpt(vector<int> &nums)
{
    int n = nums.size();
    int xorr = 0;

    for(int i=0; i<n; ++i)
    {
        xorr = xorr ^ nums[i];
    }

    int singleBit = (xorr & (xorr - 1)) ^ xorr;
    int b1=0;
    int b2=0;

    for(int i=0; i<n; ++i)
    {
        if(nums[i] & singleBit)
        {
            b1 = b1 ^ nums[i];
        }
        else
        {
            b2 = b2 ^ nums[i];
        }
    }

    return {b1, b2};
}

int main()
{
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; ++i)
    {
        cin>>nums[i];
    }

    vector<int> ans1 = singleNumberBF(nums);
    vector<int> ans2 = singleNumberOpt(nums);

    for(auto it : ans1)
    {
        cout<<it<<" ";
    }

    for(auto it : ans2)
    {
        cout<<it<<" ";
    }

    return 0;
}

