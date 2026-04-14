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

CODE:*/

// NOTE:- The code could be more concise if done in double traversal but I find this more intuitive

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
    
};

int main()
{

}

/*
COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(N), where N is the number of elements in the array `arr`. We iterate through the array multiple times to calculate the previous smaller, next smaller, previous greater, and next greater elements.
- The space complexity is O(N) as we use additional space to store the previous smaller, next smaller, previous greater, and next greater elements.
*/

