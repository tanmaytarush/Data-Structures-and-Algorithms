"""

Find the Largest Digit in a Number
116.5k
1
Given an integer n, find the largest digit present in it.

Example 1
Input: n = 58241

Output: 8

Explanation: The digits are 5, 8, 2, 4, 1, and the largest among them is 8.

Example 2
Input: n = 70039

Output: 9

Explanation: The digits are 7, 0, 0, 3, 9, and the largest among them is 9.

"""

import sys
# Similar to INT_MIN and INT_MAX

class Solution:
    def largestDigit(self, n: int) -> int:
        num: int = abs(n)

        smallest: int = sys.maxsize
        largest: int = -sys.maxsize - 1

        while(num != 0):
            digit: int = num%10
            if(digit > largest):
                largest = digit
            num = num//10

        return largest

def main() -> None:
    n: int = int(input("Enter the number : "))
    sol = Solution()
    print(sol.largestDigit(n))

if __name__ == "__main__":
    main()


# Time -> O(log N)
# Space -> O(1)