"""

Insertion Sort Algorithm: Steps and Time Complexity
169k
4
An integer array arr is given. Rearrange all values in non-decreasing order by applying the insertion sort algorithm.

During every pass, the current value from the unsorted part must be inserted into the correct position inside the sorted prefix. Return the sorted array.

Example 1
Input: arr = [12, 11, 13, 5, 6]
Output: [5, 6, 11, 12, 13]
Explanation: Value 11 is inserted before 12, value 13 remains after the sorted prefix, value 5 moves to the front, and value 6 is inserted after 5.

Example 2
Input: arr = [4]
Output: [4]
Explanation: A single value already forms a sorted array, so no shift or insertion is required.

"""