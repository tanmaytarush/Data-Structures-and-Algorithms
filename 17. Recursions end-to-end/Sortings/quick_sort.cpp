/*

Quick Sort Algorithm :-

1. Pick up a pivot element, usually the first element
2. Put it in the correct place. All the smaller elements in the left of pivot and all
   the greater elements in the right of the pivot in correct order.
3. Take,
    pivot = nums[0]
    i = pivot 
    j = nums.length() - 1

4. If ith element grater than pivot and jth element lesser than pivot, then swap.
   Finally swap jth and pivot to bring pivot at correct place.

5. Recursion call on low->pI-1 and pI->high.

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
    int partitionIndex(vector<int>&nums, int low, int high)
    {
        int pivot = low;
        int i = low;
        int j = high;

        while (i <= j)
        {
            while (i <= high && nums[i] <= nums[pivot]) i++;
            while (j >= low && nums[j] > nums[pivot]) j--;
            if (i < j) swap(nums[i], nums[j]);
        }

        swap(nums[j], nums[pivot]);
        return j;
    }

    void sort(vector<int>&nums, int low, int high)
    {
        if(low >= high)
        {
            return;
        }

        int pI = partitionIndex(nums, low, high);
        sort(nums, low, pI - 1);
        sort(nums, pI + 1, high);
    }

    void quickSort(vector<int>&nums, int n)
    {
        sort(nums, 0, n-1);
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

    sol.quickSort(nums, n);

    for(int i=0; i<n; i++)
    {
        cout<<nums[i]<<" ";
    }

    return 0;
}