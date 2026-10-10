"""

Selection Sort Algorithm: Steps and Time Complexity
225.2k
8
An integer array arr is given. Rearrange all values in non-decreasing order by applying the selection sort algorithm.

During every pass, the smallest value from the unsorted part must be selected and placed at the first position of the same part. Return the sorted array.

Example 1
Input: arr = [29, 10, 14, 37, 13]
Output: [10, 13, 14, 29, 37]
Explanation: Value 10 is selected first, followed by 13, 14, and 29. Every selected value is placed at the next boundary of the sorted part.

Example 2
Input: arr = [7]
Output: [7]
Explanation: A single value already occupies the correct position, so no pass or swap is required.


Time -> O(n2)
Space -> O(1)

"""

class Solution:
    def selectionSort(self, arr):
        n = len(arr)

        for i in range(n-1):
            minimum = i
            for j in range(i+1, n):
                if(arr[j] < arr[minimum]):
                    minimum = j

            temp = arr[i]
            arr[i] = arr[minimum]
            arr[minimum] = temp

        return arr


def main() -> None:
    n = int(input("Array size : "))
    li = []
    for i in range(n):
        element = int(input())
        li.append(element)
    # li = list(map(int, input().split()))
    sol = Solution()
    arr = sol.selectionSort(li)
    print(arr)


if __name__ == "__main__":
    main()