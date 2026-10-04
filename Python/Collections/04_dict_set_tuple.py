"""
04. dict (unordered_map), set (unordered_set), tuple (pair)
----------------------------------------------------------
dict / set: average O(1) insert, lookup, delete (hash tables).
dict keeps INSERTION order (3.7+), but it is NOT sorted like C++ map.
Keys must be hashable: int, str, tuple, frozenset  (NOT list / set / dict).
"""

# ============================================================
# 1. dict basics
# ============================================================
d = {"a": 1, "b": 2}
d["c"] = 3                    # insert / update
print(d["a"])                 # KeyError if missing!
print(d.get("z"))             # None if missing
print(d.get("z", 0))          # default if missing
print("a" in d)               # key membership O(1)
del d["a"]                    # delete (KeyError if missing)
val = d.pop("b")              # remove & return
val = d.pop("zz", None)       # safe pop
print(len(d))

d = {"x": 10, "y": 20}
for k in d: pass                    # keys
for k, v in d.items(): pass         # key + value
for v in d.values(): pass
print(list(d.keys()), list(d.values()), list(d.items()))

d.setdefault("z", []).append(1)     # create if missing, then use
d.update({"x": 99, "w": 1})         # merge
merged = {**d, "new": 5}            # merge into new dict
merged2 = d | {"k": 1}              # 3.9+
last_k, last_v = d.popitem()        # removes last inserted (LIFO)

# ============================================================
# 2. Frequency counting patterns
# ============================================================
nums = [1, 2, 2, 3, 3, 3]
freq = {}
for x in nums:
    freq[x] = freq.get(x, 0) + 1    # classic
# Better: collections.Counter / defaultdict(int)  -> see 05_collections_module.py

# Sort dict by value (desc), then key
by_val = sorted(freq.items(), key=lambda kv: (-kv[1], kv[0]))
print(by_val)                       # [(3,3),(2,2),(1,1)]
print(max(freq, key=freq.get))      # key with max value -> 3

# Two Sum (value -> index)
def two_sum(nums, target):
    seen = {}
    for i, x in enumerate(nums):
        if target - x in seen:
            return [seen[target - x], i]
        seen[x] = i
    return []
print(two_sum([2, 7, 11, 15], 9))

# Prefix sum count (subarray sum equals k)
def subarray_sum(nums, k):
    count, cur, seen = 0, 0, {0: 1}
    for x in nums:
        cur += x
        count += seen.get(cur - k, 0)
        seen[cur] = seen.get(cur, 0) + 1
    return count
print(subarray_sum([1, 1, 1], 2))   # 2

# Tuple as key (grid coordinates, memo states)
memo = {}
memo[(0, 1)] = 5
inverted = {v: k for k, v in {"a": 1, "b": 2}.items()}
keys_init = dict.fromkeys(["a", "b"], 0)   # {'a':0,'b':0}

# ============================================================
# 3. set
# ============================================================
s = set()                     # NOT {}  ({} is an empty dict!)
s = {1, 2, 3}
s.add(4)
s.remove(4)                   # KeyError if absent
s.discard(99)                 # safe remove
x = s.pop()                   # removes arbitrary element
print(2 in s)                 # O(1)
s2 = set([1, 1, 2])           # dedupe -> {1, 2}

a, b = {1, 2, 3}, {2, 3, 4}
print(a | b)      # union         {1,2,3,4}
print(a & b)      # intersection  {2,3}
print(a - b)      # difference    {1}
print(a ^ b)      # symmetric diff {1,4}
print(a <= b, a.issubset(b), a.issuperset({1}), a.isdisjoint({9}))
a.update([7, 8])  # add many

# frozenset: immutable & hashable -> can be dict key / set element
fs = frozenset([1, 2])
seen_states = {fs}

# Visited set for BFS/DFS on grid
visited = set()
visited.add((0, 0))
print((0, 0) in visited)

# Longest consecutive sequence pattern
def longest_consecutive(nums):
    st, best = set(nums), 0
    for x in st:
        if x - 1 not in st:          # start of a sequence
            y = x
            while y + 1 in st:
                y += 1
            best = max(best, y - x + 1)
    return best
print(longest_consecutive([100, 4, 200, 1, 3, 2]))  # 4

# ============================================================
# 4. tuple (immutable, hashable -> C++ pair / tuple)
# ============================================================
p = (1, 2)
x, y = p                         # unpacking
single = (5,)                    # trailing comma for single element tuple
print(p[0], p[1], len(p))
print((1, 2) < (1, 3))           # lexicographic compare (great for heaps / sort)
t = tuple([1, 2, 3])
print(t.count(1), t.index(2))

# Sorted containers (C++ map / set with ordering) are NOT built-in.
# Options: sort keys when needed: for k in sorted(d): ...
#          use bisect on a sorted list (06/07 files)
#          `pip install sortedcontainers` -> SortedList, SortedDict (available on LeetCode)
# from sortedcontainers import SortedList
# sl = SortedList(); sl.add(5); sl.remove(5); sl.bisect_left(3); sl[0]; sl[-1]

print("04_dict_set_tuple OK")
