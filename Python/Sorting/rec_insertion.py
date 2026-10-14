"""
Recursive Insertion Sorting Algorithm
"""

class Solution:
    def insertionRecursive(self, arr, index, n):
        if(index == n-1):
            return arr

        for i in range(1, n):
            j = i
            while(j>0 and arr[j]<arr[j-1]):
                arr[j], arr[j-1] = arr[j-1], arr[j] 

        return self.insertionRecursive(arr, index+1, n)


def main() -> None:
    n = int(input("Enter size : "))
    li = list(map(int, input().split()))
    sol = Solution()
    arr = sol.insertionRecursive(li, 0, n)
    print(arr)


if __name__ == "__main__":
    main()