"""
Recursive Bubble Sorting
"""

class Solution:
    """
    Bubble Sorting through recursion
    """
    def bubbleSort(self, arr, n):
        if(n==1):
            return arr

        for i in range(n-1):
            if arr[i] > arr[i+1]:
                temp = arr[i]
                arr[i] = arr[i+1]
                arr[i+1] = temp

        return self.bubbleSort(arr, n-1)


def main() -> None:
    n = int(input("Enter size : "))
    arr = list(map(int, input().split()))
    sol = Solution()
    li = sol.bubbleSort(arr, n)
    print(li)


if __name__ == "__main__":
    main()