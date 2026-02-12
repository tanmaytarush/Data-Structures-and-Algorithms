/*
Problem Statement: Given an integer array nums, which can have duplicate entries, provide the power set. Duplicate subsets cannot exist in the solution set. Return the answer in any sequence.

Examples
Input: array[] = [1,2,2]
Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]
Explanation: We can have subsets ranging from  length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.

Input: array[] = [1]
Output: [ [ ], [1] ]
Explanation: Only two unique subsets are available.
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;

void subsetSum(int index, vector<int>&arr, vector<vector<int>>&ans, vector<int>&ds)
{
    ans.push_back(ds);
    for(int i=index; i<arr.size(); ++i)
    {
        if(i != index && arr[i] == arr[i-1]) continue;
        ds.push_back(arr[i]);
        subsetSum(i+1, arr, ans, ds);
        ds.pop_back(); 
    }
}

vector<vector<int>> subsetSum(vector<int>&arr, int n)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    subsetSum(0, arr, ans, ds);
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

    vector<vector<int>> result = subsetSum(arr, n);
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