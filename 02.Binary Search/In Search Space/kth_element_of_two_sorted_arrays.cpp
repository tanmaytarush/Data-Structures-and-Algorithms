/*
Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer 'k'. Find the 'kth' positive integer missing from 'vec'.

Examples

Example 1:
Input Format: vec[]={4,7,9,10}, k = 1
Result: 1
Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 1, the first missing element is 1.
Example 2:
Input Format: vec[]={4,7,9,10}, k = 4
Result: 5
Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 4, the fourth missing element is 5.

Approach:
1. Compare the sizes of the two arrays, arr1 and arr2. If the size of arr1 is greater than arr2, swap the arrays to ensure arr1 is the smaller sized array.
2. Set the low and high variables for binary search.
   - If m < k, set low = k - m, otherwise set low = 0.
   - If k < n, set high = k, otherwise set high = n.
3. Perform binary search within the range [low, high] to find the kth element.
4. In each iteration of binary search:
   - Calculate the cut positions, cut1 and cut2, based on the mid position.
   - Determine the left and right elements of arr1 and arr2 based on the cut positions.
   - Compare the left and right elements and adjust the low and high pointers accordingly.
5. Return the maximum element among the left elements, as it would be the kth element in the final sorted array.

CODE
*/

