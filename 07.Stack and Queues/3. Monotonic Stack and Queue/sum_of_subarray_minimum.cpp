/*QUESTION:
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

APPROACH:
To find the sum of the minimums of all subarrays, we can use the concept of previous smaller and next smaller elements for each element in the array.
1. Define two helper functions:
   - `prevSmaller(arr)`: Returns an array that contains the index of the previous smaller element for each element in `arr`. If no smaller element exists, the index is set to -1.
   - `nextSmaller(arr)`: Returns an array that contains the index of the next smaller element for each element in `arr`. If no smaller element exists, the index is set to the length of the array.
2. Initialize a variable `ans` to 0 to store the final sum.
3. Iterate over each element `arr[i]` in the array:
   a. Calculate the number of subarrays in which `arr[i]` is the minimum element.
      - The number of subarrays with `arr[i]` as the minimum element on the left side is `i - prevS[i]`.
      - The number of subarrays with `arr[i]` as the minimum element on the right side is `nextS[i] - i`.
   b. Add `(leftElements * rightElements * arr[i]) % mod` to `ans`, where `mod` is `1e9 + 7`.
4. Return the final value of `ans` as the sum of minimums of all subarrays modulo `1e9 + 7`.

CODE:*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution
{
   public:
   vector<int> find_psee(vector<int> &nums)
   {
      int n = nums.size();
      vector<int> psee(n);
      stack<int> st;

      for(int i=0; i<n; i++)
      {
         while(!st.empty() && nums[st.top()]>nums[i])
         {
            st.pop();
         }

         psee[i] = st.empty() ? -1 : st.top(); // if empty next smaller is at hypethetical n index

         st.push(i);
      }

      return psee;
   }

   vector<int> find_nse(vector<int> &nums)
   {
      int n = nums.size();
      vector<int> nse(n);
      stack<int> st;

      for(int i=n-1; i>=0; i--)
      {
         while(!st.empty() && nums[st.top()] >= nums[i])
         {
            st.pop();
         }

         nse[i] = st.empty() ? n : st.top(); // hypothetical index -1

         st.push(i);
      }

      return nse;
   }

   int subArrayMinSum(vector<int> &nums)
   {
      int mod = (int)(1e9 + 7);
      vector<int> pse = find_psee(nums);
      vector<int> nse = find_nse(nums);
      int n = nums.size();
      int total = 0;

      for(int i=0; i<n; ++i)
      {
         int prevSubarray = i - pse[i];
         int nextSubarray = nse[i] - i;

         total += (prevSubarray * nextSubarray * 1LL * nums[i])%mod;
         total %= mod;
      }

      return total;
   }
};

int main()
{
   int n;
   cin>>n;

   Solution sol;
   vector<int> arr(n);
   for(int i=0; i<n; ++i)
   {
      cin>>arr[i];
   }

   int result = sol.subArrayMinSum(arr);

   cout<<result<<endl;

   return 0;
}

/*
COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(N), where N is the number of elements in the array `arr`. We iterate through the array twice to calculate the previous smaller and next smaller elements.
- The space complexity is O(N) as we use additional space to store the previous smaller and next smaller elements.
*/
