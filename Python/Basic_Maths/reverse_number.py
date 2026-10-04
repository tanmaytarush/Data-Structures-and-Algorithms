"""
Reverse Digits of a Number
174.4k
0
Given an integer N, return the number formed by reversing its digits.

If the number ends with zeroes, those zeroes disappear in the reversed value because a number does not keep leading zeroes.

Example 1
Input: n = 12345

Output: 54321

Explanation: The digits are read from right to left, so 12345 becomes 54321.

Example 2
Input: n = -1200

Output: -21

Explanation: First reverse the digits of 1200, which gives 21, and then keep the negative sign.

"""

class Solution:
    def reverse(self, n : int) -> int:
        is_negative: bool = n < 0

        num: int = abs(n)
        revNum: int = 0

        while(num > 0):
            digit = num%10
            revNum = revNum*10 + digit
            num = num//10

        if(is_negative):
            return -revNum

        return revNum


def main() -> None:
    n = int(input("Enter the number : "))
    sol = Solution()
    print(sol.reverse(n))


if __name__ == "__main__":
    main()