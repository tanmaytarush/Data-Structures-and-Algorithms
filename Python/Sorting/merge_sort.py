"""

Merge Sort Algorithm: Divide and Conquer Explained
232.4k
3
An integer array arr is given. Rearrange all values in non-decreasing order by applying the merge sort algorithm.

The array must be divided into smaller parts, sorted parts must be merged in order, and the final sorted array must be returned.

Example 1
Input: arr = [38, 27, 43, 10]
Output: [10, 27, 38, 43]
Explanation: The array is divided into [38, 27] and [43, 10]. Smaller parts become [27, 38] and [10, 43], then both sorted parts are merged into [10, 27, 38, 43].

Example 2
Input: arr = [5]
Output: [5]
Explanation: A single value already forms a sorted range, so no split or merge is required.

Practice it by yourself before moving onto the solution
Try now
Approach
Merge sort follows the Divide-and-Conquer idea. The array is repeatedly divided into two halves until each range contains only one element, which is already sorted.

The sorted ranges are then merged by comparing their current values and placing the smaller value first. Equal values are taken from the left range to preserve stability.

Each merge builds a larger sorted range, and this process continues until the complete array becomes sorted.

Algorithm
Begin with the full range from index 0 to index n - 1 so every array position participates in sorting.

Stop a recursive call when left >= right because a range containing at most one value is already sorted.

Calculate the middle index with left + (right - left) / 2 so two balanced smaller ranges are formed without adding both boundaries directly.

Sort the left and right ranges recursively so both ranges satisfy the ordered-input requirement of the merge operation.

Keep two range pointers and a temporary array so comparisons preserve every unmerged value from both sorted ranges.

Compare both current values and take the left value on equality because the smallest available value belongs next and left-first equality preserves stability.

Copy remaining values and write the temporary array back into the current range so the parent call receives one completely sorted range.



Time -> O(N*LogN)
Space -> O(N)

"""

class Solution:
    def merge(self, arr, left, mid, right):
        left_part = []
        right_part = []

        for i in range(left, mid+1):
            left_part.append(arr[i])

        for i in range(mid+1, right+1):
            right_part.append(arr[i])

        n = len(left_part)
        m = len(right_part)

        index = left
        left_index = 0
        right_index = 0
            
        while(left_index<n and right_index<m):
            if(left_part[left_index] <= right_part[right_index]):
                arr[index] = left_part[left_index]
                left_index += 1
            else:
                arr[index] = right_part[right_index]
                right_index += 1
            index += 1

        while(left_index<n):
            arr[index] = left_part[left_index]
            left_index += 1
            index += 1

        while(right_index<m):
            arr[index] = right_part[right_index]
            right_index += 1
            index += 1


    def merge_sort_helper(self, arr, left, right):
        if left>=right:
            return

        mid = left + (right - left) // 2

        # Break the array from left to mid
        self.merge_sort_helper(arr, left, mid)

        # Break the array from mid+1 to right
        self.merge_sort_helper(arr, mid+1, right)

        # Merge the broken arrays in sorted order
        self.merge(arr, left, mid, right)


    def merge_sort(self, arr):
        n = len(arr)
        if n<2:
            return arr
        self.merge_sort_helper(arr, 0, n-1)
        return arr


def main() -> None:
    li = []
    n = int(input("Enter size : "))
    for i in range(n):
        element = int(input())
        li.append(element)
    sol = Solution()
    arr = sol.merge_sort(li)
    print(arr)


if __name__ == "__main__":
    main()