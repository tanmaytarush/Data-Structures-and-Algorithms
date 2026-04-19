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

*/

/*

INTUITION BRUTE FORCE :-

1. Generating all the subarrays.
2. Figuring out the minimum element in each subarray.
3. Summing it up.
4. Time Complexity here lies at around O(N^2), and Space complexity is O(1).


INTUITION OPTIMAL :-

1. Consider an array -> [1 4 6 7 3 7 8 1], now at an index where 3 is present there are 4 elements at the 
   back with greater elements and 3 at the front which are greater. So, total subarrays are (4x3) 12. Now, 
   since total addition is required, so total is 12x3 = 36.

2. So, for an element if we could figure out total NSE (Next Smaller Element) and PSE (Previous Smaller Element),
   then we could probably find total additions on O(2N) complexity.

3. Now, an edge case which arises is, what if there equal elements in an array like [1 1], then subarrays will
   be considered twice since we are only considering Next-Smaller and Previous-Smaller. So we should eliminate
   either the previous smaller / next smaller with an equality element check.

4. Finally, if no smaller element lies previous of current-element, then PSEE = -1. Similarly, if no smaller
   element lies next to current-element, then set NSE = n hypothetically.

5. Time Complexity -> O(2*N) and Space Complexity -> O(1).

*/

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
