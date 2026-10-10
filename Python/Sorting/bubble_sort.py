"""

Bubble Sort Algorithm: Steps and Time Complexity
164.5k
4
An integer array arr is given. Rearrange all values in non-decreasing order by applying the bubble sort algorithm.

During every pass, adjacent values must be compared. Whenever a left value is greater than a right value, both values must be swapped. Return the sorted array.

Example 1
Input: arr = [5, 1, 4, 2, 8]
Output: [1, 2, 4, 5, 8]
Explanation: Larger values move right after adjacent swaps. Value 8 stays near the end, and values 5 and 4 move right until the final order becomes sorted.

Example 2
Input: arr = [7]
Output: [7]
Explanation: A single value already occupies the correct position, so no comparison or swap is required.


Time -> O(n2)
Space -> O(1)

"""

class Solution:
    def Bubble(self, arr):
        n = len(arr)

        for i in range(n):
            for j in range(n-i-1):
                if(arr[j] > arr[j+1]):
                    temp = arr[j]
                    arr[j] = arr[j+1]
                    arr[j+1] = temp

        return arr


def main() -> None:
    n = int(input("Size of array : "))
    li = list(map(int, input().split()))
    sol = Solution()
    arr = sol.Bubble(li)
    print(arr)

if __name__ == "__main__":
    main()