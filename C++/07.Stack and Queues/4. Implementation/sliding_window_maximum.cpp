/*
QUESTION:
Given an array of integers nums and a sliding window of size k, we need to find the maximum element in each sliding window as it moves from left to right.

APPROACH:
To solve this problem, we can use a deque (double-ended queue) to store the indices of elements in the current sliding window.
1. We iterate through the first k elements and keep track of the maximum element by maintaining the following property:
   - The deque stores the indices of elements in non-increasing order of their corresponding values in the nums array.
   - If the current element is greater than or equal to the element at the back of the deque, we remove elements from the back until this condition is satisfied.
   - This ensures that the front element of the deque is always the maximum element in the sliding window.
2. After processing the first k elements, we start from the (k+1)th element and continue the following steps:
   - If the index at the front of the deque is less than or equal to i-k, it means the maximum element in the previous sliding window is no longer valid. So, we remove it from the deque.
   - Similar to step 1, we remove elements from the back of the deque until the current element is greater than or equal to the element at the back.
   - Add the index of the current element to the deque.
   - Add the maximum element (front of the deque) to the result for the current sliding window.
3. Repeat step 2 until we process all elements in the nums array.

Example:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]


INTUITION :-

1.  Consider an input nums[] array as [1,3,-1,-3,5,3,6,7] being given as input, with window_size k = 3.
    Now, for each set of 3 different numbers, we need to trace out the maximum element per window and 
    store it in an output array.

2.  Now in an optimized fashion while we move one element forward, we need to pop out the previous 
    element out of the temporary storage, and that's why chose to have a data structure which can 
    handle pushing ans popping from both the ends.

3.  Firstly we start by adding the first element index into our queue data structure. We move forward,
    if the current element is greater than the ones in the queue, then simply pop the elements out
    starting from the very back of the hood. This will leave with the maximum element of a particular
    window at the front() of the queue.

4.  Add the maximum of a particular window, in such a manner that the given current index i >= k-1. And,
    finally return the array of maximums.

5.  Time Complexity -> O(2N) and Space Complexity -> O(N+K).

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<stack>
#include<deque>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    vector<int> slidingWindowMax(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> result;
        deque<int> dq;

        if(n<k)
        {
            return nums;
        }

        for(int i=0; i<n; ++i)
        {
            if(!dq.empty() && dq.front() <= i-k)
            {
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if(i>=k-1)
            {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;

    int n;
    cin>>n;

    int k;
    cin>>k;

    vector<int> nums(n);
    for(int i=0; i<n; ++i)
    {
        cin>>nums[i];
    }

    vector<int> result = sol.slidingWindowMax(nums, k);

    for(vector<int>::iterator it = result.begin(); it != result.end(); ++it)
    {
        cout<<*it<<" ";
    }

    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Let n be the number of elements in the nums array.
- The time complexity of the solution is O(n) because we iterate through each element once.
- The space complexity is O(k) because the deque stores at most k elements at any given time.
*/
