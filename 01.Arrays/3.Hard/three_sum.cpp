/*
QUESTION:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Example:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/

/*
APPROACH:
To find all triplets that sum up to zero, we can follow these steps:
1. Sort the input array in non-decreasing order.
2. Iterate through the array and fix the first element as nums[k] (where k = 0 to n-1).
3. Use two pointers (i and j) to find the other two elements such that nums[i] + nums[j] = -nums[k].
4. Move the pointers accordingly to find all possible triplets.
5. Skip duplicate elements to avoid duplicate triplets.
6. Return the resulting triplets.
*/

//CODE:-

#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<set>

vector<vector<int>> threeSumBF(vector<int> &arr)
{
    set<vector<int>> st;
    int n = arr.size();
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            for(int k=j+1; k<n; ++k)
            {
                if(arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> ans = {arr[i], arr[j], arr[k]};
                    sort(ans.begin(), ans.end());
                    st.insert(ans);
                }
            }
        }
    }
    vector<vector<int>> final(st.begin(), st.end());
    return final;
}

vector<vector<int>> threeSumBetter(vector<int> &arr)
{
    int n = arr.size();
    set<vector<int>> st;
    for(int i=0; i<n; ++i)
    {
        set<int> hashset;
        for(int j=i+1; j<n; ++j)
        {
            int third = -(arr[i] + arr[j]);
            if(hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> threeSumOptimal(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end()); // Only valid for sorted arrays
    for(int i=0; i<n-2; ++i)
    {
        if(i>0 && arr[i]==arr[i-1]) continue;
        if(arr[i] > 0) break;
        int j = i+1;
        int k = n-1;
        while(j<k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0)
            {
                j++;
            }
            else if(sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;

                while(j<k && arr[j]==arr[j-1]) j++;
                while(j<k && arr[k]==arr[k+1]) k--;
            }
        }
    }
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

    vector<vector<int>> result1 = threeSumBF(arr);
    vector<vector<int>> result2 = threeSumBetter(arr);
    vector<vector<int>> result3 = threeSumOptimal(arr);

    for(vector<vector<int>>:: iterator it = result1.begin(); it!=result1.end(); ++it)
    {
        for(vector<int>:: iterator jt = it->begin(); jt != it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    for(vector<vector<int>>:: iterator it = result2.begin(); it!=result2.end(); ++it)
    {
        for(vector<int>:: iterator jt = it->begin(); jt != it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    for(vector<vector<int>>:: iterator it = result3.begin(); it!=result3.end(); ++it)
    {
        for(vector<int>:: iterator jt = it->begin(); jt != it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    return 0;
}

/*
TIME COMPLEXITY: O(n^2), where n is the size of the input array.
The sorting step takes O(n log n), and the two-pointer traversal takes O(n^2) in the worst case.
Hence, the overall time complexity is O(n^2).

SPACE COMPLEXITY: O(1), as we are using a constant amount of extra space for storing the output and variables.
*/
