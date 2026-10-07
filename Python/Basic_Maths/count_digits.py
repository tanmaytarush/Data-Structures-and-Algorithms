"""
Given an integer N, count how many digits are present in it.

Only the digits should be counted. If the number is negative, the minus sign is not a digit.

Example 1
Input: n = 1567

Output: 4

Explanation: The digits are 1, 5, 6, and 7, so the count is 4.

Example 2
Input: n = -980

Output: 3

Explanation: The minus sign is not counted. The digits are 9, 8, and 0.
"""

class Solution:
    # Count Digits of a number
    def count(self, n: int) -> int:
        num: int = abs(n)
        if num==0:
            return 1

        count: int = 0
        while(num > 0):
            count += 1
            num = num // 10

        return count

def main() -> None:
    n = int(input("Enter a number : "))
    sol = Solution()
    print(sol.count(n))

if __name__ == "__main__":
    main()


# Time -> O(log N)
# Space -> O(1)