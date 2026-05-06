/*QUESTION:
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

APPROACH:
1. Initialize variables zeroCnt, start, and ans.
2. Iterate through the array nums:
   - If the current element is 0, increment zeroCnt.
   - Enter a while loop to adjust the start index until zeroCnt becomes less than or equal to k.
   - During the adjustment, decrement zeroCnt if the element at the start index is 0.
   - Update ans by taking the maximum of the current ans and the length of the current subarray if zeroCnt is less than or equal to k.
3. Return the maximum length of consecutive 1's (ans).


INTUITION BRUTE FORCE :-

1.  Consider an array nums = [1,1,1,0,0,0,1,1,1,1,0] with k=2 so we can at most flip k zeros to 1, 
    and then find out the subarray length. And finally trace out the maximum length of the sub-
    array.

2.  The outer loop starts from beginning and the inner loop moves from current index to the end of
    the loop. With each moving indexed, we get all the related sub-arrays, and within the range where
    number_of_zeros <= k, we simply calculate the length and compare with the maximum length.

3.  Time Complexity -> O(N2) and Space Complexity -> O(1).


INTUITION BETTER SOLUTION :-

1.  Consider an array nums = [1,1,1,0,0,0,1,1,1,1,0] with k=2 so we can at most flip k zeros to 1, 
    and then find out the subarray length. Here, we can take two pointers, left and right. 

2.  There are two rules which we need to take of in here. Firstly, we will move the right_pointer
    until the numZeros exceeds k. This is where condition fails and we move left till the numZeros
    is within the range of k.

3.  Within each of the subsequent left and right movements, we calculate the exact length of the 
    window, and keep a track of the maximum_window achieved untill right exceeds the total length
    of the array.

4.  Time complexity -> O(2N) and Space complexity -> O(1)


INTUITION OPTIMAL :-

1.  Consider an array nums = [1,1,1,0,0,0,1,1,1,1,0] with k=2 so we can at most flip k zeros to 1, 
    and then find out the subarray length. Here, we can take two pointers, left and right. 

2.  Now in the better solution, we used a while loop to move the left pointer shrink the window 
    size in such a manner that the maxLength remains consistent and we keep moving until one-by-
    one until left and right both are at the position such that zeros <= k.

3.  Time complexity -> O(N and Space complexity -> O(1)

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

class Solution
{
    public:
    int maxConsecutiveOnesBF(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int length = 0;
        int maxLength = 0;

        for(int i=0; i<n; ++i)
        {
            int numZeros = 0;
            for(int j=i; j<n; ++j)
            {
                if(nums[j] == 0)
                {
                    numZeros++;
                }

                if(numZeros > k)
                {
                    break;
                }
                else
                {
                    length = j-i+1;
                    maxLength = max(maxLength, length);
                }
            }
        }
        return maxLength;
    }


    int maxConsecutiveOnesBetter(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int length = 0;
        int maxLength = 0;
        int zeros = 0;

        while(r < n)
        {
            if(nums[r] == 0)
            {
                zeros++;
            }
            
            while(zeros > k)
            {
                if(nums[l] == 0)
                {
                    zeros--;
                }
                l++;
            }

            length = r-l+1;
            maxLength = max(maxLength, length);
            r++;
        }

        return maxLength;
    }

    int maxConsecutiveOnesOptimal(vector<int> &nums, int k)
    {
        int left = 0;
        int right = 0;
        int zeros = 0;
        int length = 0;
        int maxLength = 0;

        int n = nums.size();

        while(left < n)
        {
            if(nums[right] == 0)
            {
                zeros++;
            }

            if(zeros > k)
            {
                if(nums[left] == 0) zeros--;
                left++;
            }

            length = right-left+1;
            maxLength = max(length, maxLength);
            right++;
        }

        return maxLength;
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

    int k;
    cin>>k;

    int result_bf = sol.maxConsecutiveOnesBF(nums, k);
    int result_better = sol.maxConsecutiveOnesBetter(nums, k);
    int result_opt = sol.maxConsecutiveOnesOptimal(nums, k);

    cout<<result_bf<<endl;
    cout<<result_better<<endl;
    cout<<result_opt<<endl;

    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time complexity: O(N), where N is the length of the input array nums. We iterate through the array once.
- Space complexity: O(1), as we are using a constant amount of additional space to store variables.
*/
