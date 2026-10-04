"""
01. Built-ins & Core Syntax for DSA
-----------------------------------
Everything here is available without any import (except where noted).
Run: python3 01_builtins_and_syntax.py
"""

import math
import sys

# ============================================================
# 1. Fast Input / Output (competitive programming style)
# ============================================================
# input = sys.stdin.readline                 # faster than input() for big inputs
# n = int(input())
# a, b = map(int, input().split())
# arr = list(map(int, input().split()))
# grid = [list(input().strip()) for _ in range(n)]
# print(*arr)                                # prints "1 2 3" (space separated)
# print(*arr, sep="\n")                      # one per line
# sys.stdout.write(" ".join(map(str, arr)) + "\n")

sys.setrecursionlimit(10**6)  # default is ~1000 -> deep DFS / recursion will crash otherwise

# ============================================================
# 2. Numbers & Arithmetic
# ============================================================
a, b = 17, 5
print(a / b)          # 3.4   true division (always float)
print(a // b)         # 3     floor division
print(a % b)          # 2     modulo
print(divmod(a, b))   # (3, 2) -> (quotient, remainder)
print(a ** b)         # power
print(pow(2, 10))     # 1024
print(pow(2, 10, 1_000_000_007))  # modular exponentiation (fast)
print(pow(3, -1, 7))  # 5 -> modular inverse (Python 3.8+)
print(abs(-7))        # 7
print(round(2.5), round(3.5))  # 2 4  (banker's rounding!)

# Python ints have NO overflow -> no need for long long
print(2**100)

# Infinity (use for min/max initialisation)
INF = float("inf")
NEG_INF = float("-inf")
# or: INF = math.inf  / sys.maxsize

# Integer division that truncates toward zero (like C++)
print(int(-7 / 2))    # -3  (C++ style)
print(-7 // 2)        # -4  (Python floors!)

# ============================================================
# 3. math module (import math)
# ============================================================
print(math.sqrt(16))        # 4.0
print(math.isqrt(17))       # 4   integer sqrt (exact, use this for perfect-square checks)
print(math.ceil(3.2))       # 4
print(math.floor(3.8))      # 3
print(math.gcd(12, 18))     # 6
print(math.lcm(4, 6))       # 12   (3.9+)
print(math.factorial(5))    # 120
print(math.comb(5, 2))      # 10   nCr
print(math.perm(5, 2))      # 20   nPr
print(math.log2(8), math.log10(100), math.log(math.e))
print(math.inf, math.pi)
print(math.hypot(3, 4))     # 5.0
print(math.prod([1, 2, 3, 4]))  # 24
# Ceil division without floats: (a + b - 1) // b   or   -(-a // b)

# ============================================================
# 4. Type conversion
# ============================================================
print(int("42"), float("3.14"), str(99))
print(int("1010", 2))       # 10   binary string -> int
print(int("ff", 16))        # 255
print(bin(10))              # '0b1010'
print(bin(10)[2:])          # '1010'
print(format(10, "b"))      # '1010'
print(format(5, "08b"))     # '00000101' zero-padded
print(hex(255), oct(8))
print(ord("a"), chr(97))    # 97 'a'
print(ord("c") - ord("a"))  # 2 -> char to index (0..25)
print(chr(ord("a") + 2))    # 'c'
print(bool(0), bool([]), bool(""), bool(None))  # all False

# ============================================================
# 5. Iteration helpers
# ============================================================
nums = [4, 1, 3, 2]

for i in range(5): pass            # 0..4
for i in range(2, 10, 2): pass     # 2,4,6,8
for i in range(10, -1, -1): pass   # 10..0 (reverse)

for i, x in enumerate(nums):       # index + value
    pass
for i, x in enumerate(nums, start=1):
    pass

names = ["a", "b", "c"]
ages = [1, 2, 3]
for n, ag in zip(names, ages):     # parallel iteration (stops at shortest)
    pass
print(list(zip(*[[1, 2], [3, 4]])))  # transpose -> [(1, 3), (2, 4)]

for x in reversed(nums):           # reverse iteration (no copy)
    pass

print(list(map(str, nums)))        # ['4', '1', '3', '2']
print(list(filter(lambda x: x % 2 == 0, nums)))  # [4, 2]
print(any(x > 3 for x in nums))    # True
print(all(x > 0 for x in nums))    # True

# ============================================================
# 6. Aggregates
# ============================================================
print(len(nums), sum(nums), min(nums), max(nums))
print(min(3, 7, 1))                         # 1
print(max(["apple", "kiwi"], key=len))      # 'apple'
print(min([], default=0))                   # 0 (avoid ValueError on empty)
pairs = [(1, "b"), (3, "a"), (2, "c")]
print(max(pairs, key=lambda p: p[0]))       # (3, 'a')

# ============================================================
# 7. Sorting
# ============================================================
print(sorted(nums))                        # new list
print(sorted(nums, reverse=True))
nums.sort()                                # in-place, returns None
print(sorted(pairs, key=lambda p: p[1]))   # sort by 2nd element
print(sorted(pairs, key=lambda p: (-p[0], p[1])))  # desc first, asc second
words = ["bb", "a", "ccc"]
print(sorted(words, key=len))
# Sort is STABLE (TimSort, O(n log n)) -> multi-pass sorting works.

# Custom comparator (like C++ comparator) -> functools.cmp_to_key
from functools import cmp_to_key
def cmp(x, y):                 # negative => x first, positive => y first
    return -1 if x + y > y + x else 1
print("".join(sorted(["3", "30", "34", "5", "9"], key=cmp_to_key(cmp))))  # largest number: 9534330

# ============================================================
# 8. Comprehensions & lambdas
# ============================================================
squares = [x * x for x in range(5)]
evens = [x for x in range(10) if x % 2 == 0]
labels = ["even" if x % 2 == 0 else "odd" for x in range(4)]
grid = [[0] * 3 for _ in range(2)]          # 2x3 matrix (CORRECT way)
flat = [v for row in grid for v in row]
sq_map = {x: x * x for x in range(4)}       # dict comprehension
uniq = {x % 3 for x in range(10)}           # set comprehension
gen = (x * x for x in range(10))            # generator (lazy, O(1) memory)
add = lambda x, y: x + y

# ============================================================
# 9. Handy syntax
# ============================================================
x, y = 1, 2
x, y = y, x                       # swap
first, *rest = [1, 2, 3, 4]       # first=1, rest=[2,3,4]
*init, last = [1, 2, 3, 4]
print(1 < x < 5)                  # chained comparison
val = "big" if x > 1 else "small" # ternary
if (n := len(nums)) > 3:          # walrus operator (3.8+)
    print(n)

# Multiple return values
def min_max(arr):
    return min(arr), max(arr)
lo, hi = min_max(nums)

# Nested function + nonlocal (very common in tree/DFS problems)
def count_nodes():
    count = 0
    def dfs(k):
        nonlocal count            # modify enclosing var (ints are immutable)
        if k == 0:
            return
        count += 1
        dfs(k - 1)
    dfs(5)
    return count
print(count_nodes())              # 5

# Type hints (LeetCode signatures use these)
from typing import List, Optional
def two_sum(nums: List[int], target: int) -> List[int]:
    return []
# Modern alternative: list[int], dict[str, int], int | None
