/*
QUESTION:
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
- 0 <= a, b, c, d < n
- a, b, c, and d are distinct.
- nums[a] + nums[b] + nums[c] + nums[d] == target

Example:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

APPROACH:
To find the unique quadruplets that sum up to the target, we can use a similar approach as the threeSum problem. We will fix two elements (nums[a] and nums[b]) and use two pointers to find the remaining two elements (nums[c] and nums[d]) that sum up to the target.

1. Sort the input array nums in ascending order.
2. Iterate through the array with two pointers: a and b.
3. For each pair of elements nums[a] and nums[b], use two pointers c and d to find the remaining two elements that sum up to the target.
   - Initialize c as b + 1 and d as the last index of the array.
   - Calculate the target sum as trgt = target - (nums[a] + nums[b]).
   - While c < d, compare the sum of nums[c] and nums[d] with the target sum.
     - If the sum is equal to the target sum, we found a quadruplet. Add it to the answer and move the pointers c and d.
       - Important: Skip any duplicate elements while moving c and d.
     - If the sum is greater than the target sum, decrement d.
     - If the sum is less than the target sum, increment c.
4. Skip any duplicate elements for pointers a and b to avoid duplicate quadruplets.
5. Return the answer array containing unique quadruplets.


CODE:
*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<set>

vector<vector<int>> fourSumBF(vector<int> &arr, int target)
{
    int n = arr.size();
    set<vector<int>> st;
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            for(int k=j+1; k<n; ++k)
            {
                for(int l=k+1; l<n; ++l)
                {
                    if(arr[i]+arr[j]+arr[k]+arr[l] == target)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


vector<vector<int>> fourSumBetter(vector<int> &arr, int target)
{
    set<vector<int>> st;
    int n = arr.size();
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            set<int> hashset;
            for(int k=j+1; k<n; ++k)
            {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                int fourth = target-(sum);
                if(hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> fourSumOptimal(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; ++i)
    {
        if(i>0 && arr[i] == arr[i-1]) continue;
        for(int j=i+1; j<n; ++j)
        {
            if(j>i+1 && arr[j] == arr[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l)
            {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                sum += arr[l];
                if(sum == target)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    while(k<l && arr[k]==arr[k-1]) k++;
                    while(k<l && arr[l]==arr[l+1]) l--;
                }

                else if(sum < target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    
    int target;
    cin>>target;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    vector<vector<int>> result1 = fourSumBF(arr, target);
    vector<vector<int>> result2 = fourSumBetter(arr, target);
    vector<vector<int>> result3 = fourSumOptimal(arr, target);

    cout<<"Brute Force : "<<endl;
    for(auto it = result1.begin(); it!=result1.end(); ++it)
    {
        for(auto jt = it->begin(); jt!=it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    cout<<"Better Solution : "<<endl;
    for(auto it = result2.begin(); it!=result2.end(); ++it)
    {
        for(auto jt = it->begin(); jt!=it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    cout<<"Optimal Solution : "<<endl;
    for(auto it = result3.begin(); it!=result3.end(); ++it)
    {
        for(auto jt = it->begin(); jt!=it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }
}

/*
TIME COMPLEXITY: O(n^3), where n is the size of the input array nums.
SPACE COMPLEXITY: O(1), as we are using a constant amount of extra space.
*/
