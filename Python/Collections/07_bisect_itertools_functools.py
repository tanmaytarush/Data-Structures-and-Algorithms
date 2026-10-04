"""
07. bisect, itertools, functools
--------------------------------
bisect    -> binary search on sorted lists (lower_bound / upper_bound)
itertools -> permutations, combinations, product, accumulate, groupby ...
functools -> lru_cache / cache (memoization), reduce, cmp_to_key
"""

import bisect
import itertools
import functools
import operator

# ============================================================
# 1. bisect   (list MUST be sorted)
# ============================================================
a = [1, 2, 4, 4, 4, 7]
print(bisect.bisect_left(a, 4))    # 2  -> first index with a[i] >= 4  (C++ lower_bound)
print(bisect.bisect_right(a, 4))   # 5  -> first index with a[i] >  4  (C++ upper_bound)
print(bisect.bisect(a, 4))         # same as bisect_right
print(bisect.bisect_right(a, 4) - bisect.bisect_left(a, 4))  # 3 -> count of 4s

bisect.insort(a, 5)                # insert keeping sorted (O(n) shift)

def contains(arr, x):              # binary_search
    i = bisect.bisect_left(arr, x)
    return i < len(arr) and arr[i] == x

# Floor (largest <= x) and ceil (smallest >= x)
def floor_val(arr, x):
    i = bisect.bisect_right(arr, x) - 1
    return arr[i] if i >= 0 else None
def ceil_val(arr, x):
    i = bisect.bisect_left(arr, x)
    return arr[i] if i < len(arr) else None
print(floor_val(a, 6), ceil_val(a, 6))   # 5 7

# key= parameter (3.10+) -> search list of tuples by a field
events = [(1, "a"), (5, "b"), (9, "c")]
print(bisect.bisect_left(events, 5, key=lambda e: e[0]))   # 1

# Search range [lo, hi)
print(bisect.bisect_left(a, 4, 0, 3))

# LIS in O(n log n)
def length_of_lis(nums):
    tails = []
    for x in nums:
        i = bisect.bisect_left(tails, x)
        if i == len(tails):
            tails.append(x)
        else:
            tails[i] = x
    return len(tails)
print(length_of_lis([10, 9, 2, 5, 3, 7, 101, 18]))   # 4

# ============================================================
# 2. itertools
# ============================================================
print(list(itertools.permutations([1, 2, 3])))        # all 3! orderings
print(list(itertools.permutations([1, 2, 3], 2)))     # nPr
print(list(itertools.combinations([1, 2, 3], 2)))     # nCr -> (1,2),(1,3),(2,3)
print(list(itertools.combinations_with_replacement([1, 2], 2)))
print(list(itertools.product([0, 1], repeat=3)))      # all binary strings length 3
print(list(itertools.product("ab", "xy")))            # cartesian product (nested loops)

print(list(itertools.accumulate([1, 2, 3, 4])))                 # prefix sums [1,3,6,10]
print(list(itertools.accumulate([1, 2, 3, 4], operator.mul)))   # prefix products
print(list(itertools.accumulate([3, 1, 5, 2], max)))            # running max
print(list(itertools.accumulate([1, 2, 3], initial=0)))         # [0,1,3,6]

# groupby -> groups CONSECUTIVE equal elements (sort first if needed)
print([(k, len(list(g))) for k, g in itertools.groupby("aaabbc")])  # run-length encoding
print(list(itertools.chain([1, 2], [3], [4, 5])))     # concat iterables
print(list(itertools.chain.from_iterable([[1, 2], [3]])))
print(list(itertools.zip_longest([1, 2, 3], "ab", fillvalue="-")))
print(list(itertools.pairwise([1, 2, 3, 4])))         # (1,2),(2,3),(3,4)  3.10+
print(list(itertools.islice(itertools.count(10), 3))) # [10,11,12]
print(list(itertools.repeat("x", 3)))
print(list(itertools.compress("abcd", [1, 0, 1, 0]))) # ['a','c']
print(list(itertools.batched(range(7), 3)))           # (0,1,2),(3,4,5),(6,) 3.12+

# All subsets (power set)
nums = [1, 2, 3]
subsets = [list(c) for r in range(len(nums) + 1) for c in itertools.combinations(nums, r)]
print(subsets)

# ============================================================
# 3. functools
# ============================================================

# Memoization -> top-down DP with one decorator
@functools.cache                       # unlimited cache (3.9+), same as lru_cache(maxsize=None)
def fib(n):
    return n if n < 2 else fib(n - 1) + fib(n - 2)
print(fib(100))

@functools.lru_cache(maxsize=None)
def grid_paths(r, c):
    if r == 0 or c == 0:
        return 1
    return grid_paths(r - 1, c) + grid_paths(r, c - 1)
print(grid_paths(10, 10))
grid_paths.cache_clear()               # clear between test cases if needed
# NOTE: arguments must be hashable -> pass tuples, not lists.

# reduce -> fold
print(functools.reduce(operator.mul, [1, 2, 3, 4]))        # 24
print(functools.reduce(lambda x, y: x ^ y, [4, 1, 2, 1, 2]))  # 4 (single number)
print(functools.reduce(lambda acc, x: acc * 10 + x, [1, 2, 3], 0))  # 123

# cmp_to_key -> C++ style comparator for sort
def compare(a, b):
    if a[0] != b[0]:
        return a[0] - b[0]       # ascending by first
    return b[1] - a[1]           # descending by second
print(sorted([(1, 2), (1, 5), (0, 9)], key=functools.cmp_to_key(compare)))

# partial -> fix some arguments
to_int_base2 = functools.partial(int, base=2)
print(to_int_base2("101"))       # 5

# ============================================================
# 4. operator module (faster than lambdas for keys)
# ============================================================
from operator import itemgetter, attrgetter
pairs = [(1, "b"), (0, "a")]
print(sorted(pairs, key=itemgetter(1)))
print(sorted(pairs, key=itemgetter(1, 0)))

print("07_bisect_itertools_functools OK")
