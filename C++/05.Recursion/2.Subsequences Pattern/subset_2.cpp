/*QUESTION:
Given an integer array nums that may contain duplicates, return all possible subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.

Example:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example:
Input: nums = [0]
Output: [[],[0]]

Approach:
To find all possible subsets without duplicates, we can use a recursive backtracking approach.
1. Sort the input array nums in non-decreasing order to handle duplicates.
2. Create a helper function called 'solve' that takes the current index, the array nums, a temporary vector to store the current subset, and a vector of vector to store all subsets as parameters.
3. In the 'solve' function:
   - Add the current subset to the vector of subsets.
   - Iterate from the current index to the end of the array:
     - If the current index is greater than the starting index and the current element is the same as the previous element, skip the iteration to avoid duplicates.
     - Add the current element to the current subset.
     - Recursively call the 'solve' function with the updated index, the array nums, the current subset, and the vector of subsets.
     - Remove the last added element from the current subset (backtracking).
4. Create the main function called 'subsetsWithDup' that calculates and returns the vector of subsets without duplicates.
   - Sort the input array nums.
   - Initialize an empty vector to store the subsets.
   - Call the 'solve' function with the initial index as 0, the array nums, an empty temporary vector, and the vector of subsets.
   - Return the vector of subsets.

Time Complexity: O(2^N), where N is the size of the input array nums. This is because there are 2^N possible subsets.
Space Complexity: O(N), where N is the size of the input array nums. This is the space required to store the subsets.

CODE:*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void solve(int index, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    ans.push_back(ds);

    for(int i=index; i<arr.size(); ++i)
    {
        if(i != index && arr[i] == arr[i-1]) continue;

        //pick up the element
        ds.push_back(arr[i]);
        solve(i + 1, arr, ans, ds); // no value reduction like sum, so only one call
        ds.pop_back();
    }
}

vector<vector<int>> subsetSum(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    solve(0, arr, ans, ds);
    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    vector<vector<int>> result = subsetSum(arr);

    for(auto nums : result)
    {
        for(auto it : nums)
        {
            cout<<it<<" ";
        }   
        cout<<endl;
    }

    return 0;
}
