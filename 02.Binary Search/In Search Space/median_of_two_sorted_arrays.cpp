/*QUESTION:
Given two sorted arrays nums1 and nums2 of sizes m and n respectively, you need to find the median of the two sorted arrays.

APPROACH:
To find the median of two sorted arrays, we can apply the concept of binary search. The overall time complexity of the solution should be O(log (m+n)).

1. First, we ensure that nums1 is the smaller sized array. If not, we swap nums1 and nums2.
2. Calculate the optimal count opt_cnt, which is (nums1.size() + nums2.size() + 1) / 2. This represents the median index in the merged array.
3. Initialize low to 0 and high to nums1.size() - 1.
4. Perform binary search until low is less than or equal to high:
     - Calculate the cut1 as low + (high - low) / 2, which represents the potential index to partition nums1.
     - Calculate cut2 as opt_cnt - cut1, which represents the corresponding index in nums2.
     - Calculate l1, l2, r1, and r2 as the left and right elements around the potential partition points.
     - If l1 is less than or equal to r2 and l2 is less than or equal to r1, it means we have found the correct partition points.
          - If the total number of elements is even, return the average of the maximum of l1 and l2 and the minimum of r1 and r2.
          - If the total number of elements is odd, return the maximum of l1 and l2.
     - If l1 is greater than r2, move the high pointer to cut1 - 1.
     - Otherwise, move the low pointer to cut1 + 1.
5. If no median is found, return 0.0.

CODE:*/

#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;



int main()
{
    
}

/*
COMPLEXITY ANALYSIS:
- Time complexity: O(log(min(m, n))), where m and n are the sizes of the input arrays nums1 and nums2, respectively. We perform binary search on the smaller array.
- Space complexity: O(1), as we use constant extra space throughout the algorithm.
*/
