"""
Count Odd digits in a Number
102.1k
0
Given a number find the number of odd digits in the number.

Odd digits are those which when divided with 2 leaves a remainder 1.

Example 1
Input: n = 45231

Output: 3

Explanation: The odd digits are 5, 3, and 1, so the count is 3.

Example 2
Input: n = 2048

Output: 0

Explanation: All digits are even, so there are no odd digits in the number.
"""

class Solution:
    def count(self, n: int) -> int:
        num: int = abs(n)

        if num==0:
            return 0

        count: int = 0

        while(num>0):
            digit = num%10
            if(digit % 2 == 1):
                count+=1
            num = num//10

        return count

def main() -> None:
    n = int(input("Enter a number : "))
    sol = Solution()
    print(sol.count(n))

if __name__ == "__main__":
    main()