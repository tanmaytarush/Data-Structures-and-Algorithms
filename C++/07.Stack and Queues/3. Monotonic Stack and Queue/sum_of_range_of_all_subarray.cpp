/*QUESTION:
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray. Return the sum of all subarray ranges of nums.

APPROACH:
To find the sum of all subarray ranges, we can use the concept of previous smaller, next smaller, previous greater, and next greater elements for each element in the array.
1. Define four helper functions:
   - `prevSmaller(arr)`: Returns an array that contains the index of the previous smaller element for each element in `arr`. If no smaller element exists, the index is set to -1.
   - `nextSmaller(arr)`: Returns an array that contains the index of the next smaller element for each element in `arr`. If no smaller element exists, the index is set to the length of the array.
   - `prevGreater(arr)`: Returns an array that contains the index of the previous greater element for each element in `arr`. If no greater element exists, the index is set to -1.
   - `nextGreater(arr)`: Returns an array that contains the index of the next greater element for each element in `arr`. If no greater element exists, the index is set to the length of the array.
2. Initialize a variable `ans` to 0 to store the final sum.
3. Iterate over each element `arr[i]` in the array:
   a. Calculate the number of subarrays where `arr[i]` is the minimum element:
      - The number of subarrays with `arr[i]` as the minimum element on the left side is `i - prevS[i]`.
      - The number of subarrays with `arr[i]` as the minimum element on the right side is `nextS[i] - i`.
   b. Calculate the number of subarrays where `arr[i]` is the maximum element:
      - The number of subarrays with `arr[i]` as the maximum element on the left side is `i - prevG[i]`.
      - The number of subarrays with `arr[i]` as the maximum element on the right side is `nextG[i] - i`.
   c. Update `ans` by adding `(maxleftElements * maxrightElements * arr[i]) - (minleftElements * minrightElements * arr[i])`.
4. Return the final value of `ans` as the sum of all subarray ranges.

*/

// NOTE:- The code could be more concise if done in double traversal but I find this more intuitive

/*

INTUITION BRUTE FORCE :-

1. Generate all subarrays by iterating over inner loops.
2. Get the maximum and minimum of each subarray.
3. Subtract maximum and minimum in the subarray.
4. Return the final result.


INTUITION OPTIMAL :-

1. Consider an array -> [1 4 6 7 3 7 8 1], now at an index where 3 is present there are 4 elements at the 
   back with greater elements and 3 at the front which are greater. So, total subarrays are 4x3 = 12. Now, 
   since total addition is required, so total is 12x3 = 36.

2. So, for an element if we could figure out total NSE (Next Smaller Element) and PSE (Previous Smaller Element),
   then we could probably find total additions on O(2N) complexity.

3. Now, an edge case which arises is, what if there equal elements in an array like [1 1], then subarrays will
   be considered twice since we are only considering Next-Smaller and Previous-Smaller. So we should eliminate
   either the previous smaller / next smaller with an equality element check.

4. Finally, if no smaller element lies previous of current-element, then PSEE = -1. Similarly, if no smaller
   element lies next to current-element, then set NSE = n hypothetically.

5. On a similar note, generate NGE (Next Greater Element) and PGEE (Previous Greater/Equal Element), and find 
   for the subarray sums with maximums and finally subtract the final answers for the both.

6. Time Complexity -> O(2*N) and Space Complexity -> O(1).

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

class Solution
{
    public:
    int subArrayRangeBF(vector<int> &nums)
    {
        int n = nums.size();
        long long total = 0;
        
        for(int i=0; i<n; ++i)
        {
            int maximum = nums[i];
            int minimum = nums[i];

            for(int j=i; j<n; ++j)
            {
                minimum = min(minimum, nums[j]);
                maximum = max(maximum, nums[j]);

                total += (maximum - minimum);
            }
        }
        return total;
    }

    vector<int> findPSEE(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> psee(n);
        stack<int> st;

        for(int i=0; i<n; ++i)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }

            psee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return psee;
    }

    vector<int> findPGEE(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pgee(n);
        stack<int> st;

        for(int i=0; i<n; ++i)
        {
            while(!st.empty() && nums[st.top()] <= nums[i])
            {
                st.pop();
            }

            pgee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return pgee;
    }

    vector<int> findNGE(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        for(int i=n-1; i>=0; --i)
        {
            while(!st.empty() && nums[st.top()] < nums[i])
            {
                st.pop();
            }

            nge[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nge;
    }

    vector<int> findNSE(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i=n-1; i>=0; --i)
        {
            while(!st.empty() && nums[st.top()] > nums[i])
            {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> pse = findPSEE(nums);
        vector<int> nse = findNSE(nums);
        vector<int> pge = findPGEE(nums);
        vector<int> nge = findNGE(nums);

        long long minSum = 0, maxSum = 0;

        for (int i = 0; i < n; i++) {
            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;
            minSum += leftMin * rightMin * nums[i];

            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;
            maxSum += leftMax * rightMax * nums[i];
        }
        return maxSum - minSum;
    }

};

int main()
{
    Solution sol;

    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; ++i)
    {
        cin>>nums[i];
    }

    int result1 = sol.subArrayRangeBF(nums);

    int result2 = sol.subArrayRanges(nums);

    cout<<result1<<endl;
    cout<<result2<<endl;

    return 0;
}

/*
COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(N), where N is the number of elements in the array `arr`. We iterate through the array multiple times to calculate the previous smaller, next smaller, previous greater, and next greater elements.
- The space complexity is O(N) as we use additional space to store the previous smaller, next smaller, previous greater, and next greater elements.
*/

