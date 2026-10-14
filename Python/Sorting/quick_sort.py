"""

Quick Sort Algorithm: Partitioning and Time Complexity
188.1k
3
An integer array arr is given. Rearrange all values in non-decreasing order by applying the Quick Sort algorithm.

During every partition step, one pivot value must be selected and placed at the correct sorted position. Values smaller than or equal to the pivot are moved toward the left side, and greater values are moved toward the right side. Return the sorted array.

Example 1
Input: arr = [10, 7, 8, 9, 1, 5]
Output: [1, 5, 7, 8, 9, 10]
Explanation: Pivot-based partitioning places value 5 first. Smaller values move left, greater values move right, and the same sorting process continues on both sides.

Example 2
Input: arr = [4]
Output: [4]
Explanation: A single value already occupies the correct sorted position, so no partition step is required.

Approach
A pivot is chosen to split the array into two smaller parts. Values smaller than the pivot are moved to its left, while larger values remain on its right.

A boundary index helps build the smaller-value region during the scan. After placing the pivot between the two regions, its position becomes fixed.

The same process is then repeated on the left and right parts. Each step breaks the array into smaller sections until every section has at most one element and is already sorted.

Algorithm
Start with the range 0 to n - 1 because it represents the complete array that needs to be sorted.

Process a range only when low < high because an empty or single-value range is already sorted.

Choose the last value as the pivot because it gives the scan one fixed value for comparison.

Start the boundary before the range because the smaller-value region is empty at the beginning.

Scan from low to high - 1 because the pivot at high should remain unchanged during comparison.

Move values no greater than the pivot into the left region so smaller values stay together.

Place the pivot just after the left region because that is its correct sorted position.

Repeat the process on both sides of the pivot because only those parts still need sorting.


Time -> O(N*logN)
Space -> O(1)

"""

class Solution:
    """
    Logic for quick sorting algorithm
    """
    def quickSort(self, arr):
        n = len(arr)
        self.solve(arr, 0, n-1)
        return arr


    def solve(self, arr, low, high):
        if low>=high:
            return

        # Find the partition index for the range low-high
        pIndex = self.partition(arr, low, high)

        # Call the function for low - pIndex
        self.solve(arr, low, pIndex-1)

        # Leave pivot index bcoz after one iteration it is at the right place

        # Call the function for pIndex - high
        self.solve(arr, pIndex+1, high)


    def partition(self, arr, low, high):
        pivot = arr[high]
        smallestIndex = low

        for current in range(low, high):
            if(arr[current] <= pivot):
                arr[current], arr[smallestIndex] = arr[smallestIndex], arr[current]
                smallestIndex += 1

        arr[smallestIndex], arr[high] = arr[high], arr[smallestIndex]
        return smallestIndex


def main() -> None:
    sol = Solution()
    li = list(map(int, input().split()))
    arr = sol.quickSort(li)
    print(arr)

if __name__ == "__main__":
    main()