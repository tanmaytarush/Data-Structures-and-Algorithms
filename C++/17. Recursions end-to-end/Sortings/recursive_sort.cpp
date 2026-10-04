/*

Recursive Bubble and Insertion sorting

*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution
{
    public:
    void recBubble(vector<int>&nums, int n)
    {
        if(n==1) return;

        for(int i=0; i<n-1; i++)
        {
            if(nums[i]>nums[i+1])
            {
                int temp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = temp;
            }
        }
        recBubble(nums, n-1);
    }

    void recInsertion(vector<int>&nums, int i, int n)
    {
        if(i==n) return;

        int j=i;
        while(j>0 && nums[j]<nums[j-1])
        {
            int temp = nums[j-1];
            nums[j-1] = nums[j];
            nums[j] = temp;
            j--;
        }

        recInsertion(nums, i+1, n);
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

    sol.recBubble(nums, n);
    sol.recInsertion(nums, 0, n);

    for(int i=0; i<n; i++)
    {
        cout<<nums[i]<<" ";
    }

    return 0;
}