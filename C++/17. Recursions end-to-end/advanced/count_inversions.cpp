/*

Count Inversions in an array.

For a nums array calculate count of pairs of elements on left greater than right.

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
    int countInversionsBF(vector<int>&nums)
    {
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[i] > nums[j])
                {
                    count++;
                }
            }
        }
        return count;
    }

    int countInversionOptimal(vector<int>&nums, int n)
    {
        return mergeSort(nums, 0, n-1);
    }

    int mergeSort(vector<int>&nums, int low, int high)
    {
        int count=0;
        int mid = (low + high)/2;
        if(low >= high) return count;
        count += mergeSort(nums, 0, mid);
        count += mergeSort(nums, mid+1, high);
        count += merge(nums, low, mid, high);
        return count;
    }

    int merge(vector<int>&nums, int low, int mid, int high)
    {
        int count = 0;
        int i = low;
        int j = mid+1;
        vector<int> temp;

        while(i<=mid && j<=high)
        {
            // left
            if(nums[i] < nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            // right
            else
            {
                temp.push_back(nums[j]);
                count += (mid - i + 1); // all right ones are in the count
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= high)
        {
            temp.push_back(nums[j]);
            j++;
        }

        for(int i=low; i<=high; i++)
        {
            nums[i] = temp[i-low];
        }

        return count;
    }
};

int main()
{
    Solution sol;

    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }

    int res1 = sol.countInversionsBF(nums);
    cout<<res1<<endl;

    int res2 = sol.countInversionOptimal(nums, n);
    cout<<res2<<endl;

    return 0;
}