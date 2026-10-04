"""
02. Lists  (Python's vector<> / dynamic array)
----------------------------------------------
Complexity cheat:
  append / pop()            O(1) amortised
  pop(0) / insert(0, x)     O(n)   -> use collections.deque instead
  x in list                 O(n)   -> use set for O(1)
  list[i], len(list)        O(1)
  slicing arr[a:b]          O(b-a) (creates a copy)
  sort()                    O(n log n)
"""

# ============================================================
# 1. Creation
# ============================================================
arr = [1, 2, 3]
empty = []
zeros = [0] * 5                       # [0,0,0,0,0]
r = list(range(5))                    # [0,1,2,3,4]
chars = list("abc")                   # ['a','b','c']

# 2D grid (n rows x m cols)
n, m = 3, 4
grid = [[0] * m for _ in range(n)]    # CORRECT
# bad = [[0] * m] * n                 # WRONG: all rows are the SAME object
dp = [[-1] * (m + 1) for _ in range(n + 1)]
visited = [[False] * m for _ in range(n)]
dp3 = [[[0] * 2 for _ in range(m)] for _ in range(n)]  # 3D

# ============================================================
# 2. Add / Remove
# ============================================================
arr.append(4)            # [1,2,3,4]
arr.extend([5, 6])       # [1,2,3,4,5,6]
arr.insert(0, 0)         # insert at index 0
last = arr.pop()         # removes & returns last
first = arr.pop(0)       # removes index 0 (O(n))
arr.remove(3)            # removes FIRST occurrence of value 3 (ValueError if absent)
del arr[0]               # delete by index
del arr[1:3]             # delete a slice
arr.clear()

# ============================================================
# 3. Access & Search
# ============================================================
arr = [5, 3, 8, 3, 1]
print(arr[0], arr[-1], arr[-2])   # first, last, second last
print(arr.index(3))               # 1  first index of value (ValueError if absent)
print(arr.count(3))               # 2
print(8 in arr)                   # True (O(n))
print(len(arr))

# ============================================================
# 4. Slicing  arr[start:stop:step]   (stop is exclusive)
# ============================================================
a = [0, 1, 2, 3, 4, 5]
print(a[1:4])     # [1,2,3]
print(a[:3])      # [0,1,2]
print(a[3:])      # [3,4,5]
print(a[::-1])    # reversed copy
print(a[::2])     # [0,2,4]
print(a[-3:])     # last 3
a[1:3] = [9, 9]   # slice assignment
copy1 = a[:]      # shallow copy

# ============================================================
# 5. Reorder
# ============================================================
a = [3, 1, 2]
a.sort()                  # in-place ascending
a.sort(reverse=True)      # in-place descending
a.reverse()               # in-place reverse
b = sorted(a)             # new list
intervals = [[1, 3], [0, 2], [5, 6]]
intervals.sort(key=lambda x: x[0])     # sort by start (merge intervals!)
intervals.sort(key=lambda x: (x[1], -x[0]))

# Rotate array by k (right)
nums, k = [1, 2, 3, 4, 5], 2
k %= len(nums)
nums[:] = nums[-k:] + nums[:-k]        # [4,5,1,2,3]  (nums[:] = modifies in place)

# ============================================================
# 6. Copying (shallow vs deep)
# ============================================================
import copy
g = [[1, 2], [3, 4]]
shallow = g.copy()          # or g[:] or list(g)  -> inner lists shared
deep = copy.deepcopy(g)     # fully independent
grid_copy = [row[:] for row in g]   # fast deep copy for 2D list

# ============================================================
# 7. List as Stack (preferred in Python)
# ============================================================
st = []
st.append(1)        # push
st.append(2)
top = st[-1]        # peek / top
st.pop()            # pop
is_empty = not st   # empty check (idiomatic)

# ============================================================
# 8. Useful patterns
# ============================================================
nums = [2, 7, 11, 15]

# Prefix sum (size n+1)
pre = [0] * (len(nums) + 1)
for i, x in enumerate(nums):
    pre[i + 1] = pre[i] + x
# sum(nums[l..r]) = pre[r+1] - pre[l]

from itertools import accumulate
pre2 = [0] + list(accumulate(nums))   # same thing

# Two pointers
l, r = 0, len(nums) - 1
while l < r:
    s = nums[l] + nums[r]
    if s == 9: break
    elif s < 9: l += 1
    else: r -= 1

# Matrix traversal with directions
DIRS = [(0, 1), (1, 0), (0, -1), (-1, 0)]
rows, cols = 3, 3
i, j = 1, 1
for di, dj in DIRS:
    ni, nj = i + di, j + dj
    if 0 <= ni < rows and 0 <= nj < cols:
        pass

# Transpose / rotate matrix 90 deg clockwise
mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
transposed = [list(row) for row in zip(*mat)]
rotated = [list(row) for row in zip(*mat[::-1])]   # [[7,4,1],[8,5,2],[9,6,3]]

# Flatten
flat = [x for row in mat for x in row]

# Remove duplicates while preserving order
dedup = list(dict.fromkeys([3, 1, 3, 2, 1]))       # [3,1,2]

# Index of max
idx = max(range(len(nums)), key=lambda i: nums[i])

print("02_lists OK")