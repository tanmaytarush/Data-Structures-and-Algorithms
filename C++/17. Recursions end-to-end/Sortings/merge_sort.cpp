/*

Merge Sort algorithm

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    void merge(vector<int>&nums, int low, int mid, int high)
    {
        int i = low;
        int j = mid+1;
        vector<int> temp;

        while(i<=mid && j<=high)
        {
            if(nums[i]<=nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }

            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid) 
        {
            temp.push_back(nums[i]); 
            i++;
        }

        while(j<=high)
        { 
            temp.push_back(nums[j]); 
            j++; 
        }

        for(int k=low; k<=high; k++)
        {
            nums[k] = temp[k-low];
        }
    }

    void mergeSort(vector<int>&nums, int low, int high)
    {
        if(low >= high)
        {
            return;
        }

        int mid = (low + high)/2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
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

    sol.mergeSort(nums, 0, n-1);

    for(int i=0; i<n; i++)
    {
        cout<<nums[i]<<" ";
    }

    return 0;
}