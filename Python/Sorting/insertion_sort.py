"""

Insertion Sort Algorithm: Steps and Time Complexity

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


Insertion sort takes an element and places it in its correct position

Time -> O(N2)
Space -> O(1)

"""

class Solution:
    def Insertion(self, arr):
        n = len(arr)

        for i in range(1, n):
            j = i
            while(j > 0 and arr[j-1]>arr[j]):
                temp = arr[j]
                arr[j] = arr[j-1]
                arr[j-1] = temp
                j = j-1

        return arr


def main() -> None:
    size = int(input("Enter size : "))
    li = list(map(int, input().split()))
    sol = Solution()
    arr = sol.Insertion(li)
    print(arr)

if __name__ == "__main__":
    main()