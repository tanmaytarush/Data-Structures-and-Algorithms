"""
08. Bit Manipulation in Python
------------------------------
Python ints are arbitrary precision, and negative numbers behave like
infinite two's complement. Use `& 0xFFFFFFFF` to simulate 32-bit.
"""

x, y = 10, 6          # 1010, 0110

# ============================================================
# 1. Operators
# ============================================================
print(x & y)      # 2    AND
print(x | y)      # 14   OR
print(x ^ y)      # 12   XOR
print(~x)         # -11  NOT (= -x - 1)
print(x << 2)     # 40   x * 4
print(x >> 1)     # 5    x // 2

# ============================================================
# 2. Built-ins (C++ __builtin_* equivalents)
# ============================================================
print(bin(x))             # '0b1010'
print(bin(x).count("1"))  # 2  popcount (old way)
print(x.bit_count())      # 2  popcount (3.10+)   ~ __builtin_popcount
print(x.bit_length())     # 4  number of bits needed  (31 - clz for 32-bit)
print((x & -x).bit_length() - 1)   # 1  trailing zeros  ~ __builtin_ctz
print(int("1010", 2))     # 10
print(format(x, "032b"))  # 32-bit padded string

# ============================================================
# 3. Common tricks
# ============================================================
i = 1
print((x >> i) & 1)       # check i-th bit
print(x | (1 << i))       # set i-th bit
print(x & ~(1 << i))      # clear i-th bit
print(x ^ (1 << i))       # toggle i-th bit
print(x & (x - 1))        # remove lowest set bit -> 8
print(x & -x)             # isolate lowest set bit -> 2
print(x > 0 and (x & (x - 1)) == 0)   # power of two?
print(x & 1)              # odd? (1 = odd)
a, b = 3, 5
a ^= b; b ^= a; a ^= b    # swap without temp

# Count set bits manually (Brian Kernighan)
def count_bits(n):
    c = 0
    while n:
        n &= n - 1
        c += 1
    return c

# Single number (every other appears twice)
from functools import reduce
print(reduce(lambda p, q: p ^ q, [4, 1, 2, 1, 2]))   # 4

# Counting bits for 0..n via DP
n = 5
bits = [0] * (n + 1)
for k in range(1, n + 1):
    bits[k] = bits[k >> 1] + (k & 1)
print(bits)               # [0,1,1,2,1,2]

# ============================================================
# 4. Subsets via bitmask
# ============================================================
nums = [1, 2, 3]
n = len(nums)
all_subsets = []
for mask in range(1 << n):                  # 0 .. 2^n - 1
    all_subsets.append([nums[j] for j in range(n) if mask & (1 << j)])
print(all_subsets)

# Iterate over submasks of a mask
mask = 0b1011
sub = mask
while sub:
    # process sub
    sub = (sub - 1) & mask

FULL = (1 << n) - 1          # all n bits set

# ============================================================
# 5. 32-bit simulation (e.g. "sum of two integers" without +)
# ============================================================
MASK = 0xFFFFFFFF
MAX_INT = 0x7FFFFFFF
def get_sum(a, b):
    while b & MASK:
        a, b = (a ^ b) & MASK, ((a & b) << 1) & MASK
    return a if a <= MAX_INT else ~(a ^ MASK)
print(get_sum(-2, 3))        # 1

print("08_bit_manipulation OK")
