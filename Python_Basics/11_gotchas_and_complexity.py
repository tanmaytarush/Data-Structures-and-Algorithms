"""
11. Python Gotchas for DSA + Complexity Cheat Sheet
---------------------------------------------------
Mistakes that commonly cause wrong answers or TLE when moving from C++.
"""

# ============================================================
# 1. 2D list with * shares rows
# ============================================================
bad = [[0] * 3] * 2
bad[0][0] = 1
print(bad)                      # [[1,0,0],[1,0,0]]  both rows changed!
good = [[0] * 3 for _ in range(2)]

# ============================================================
# 2. Mutable default argument
# ============================================================
def append_bad(x, lst=[]):      # the SAME list is reused across calls
    lst.append(x)
    return lst
append_bad(1); print(append_bad(2))   # [1, 2]  surprise!

def append_good(x, lst=None):
    if lst is None:
        lst = []
    lst.append(x)
    return lst

# ============================================================
# 3. Backtracking: append a COPY of path
# ============================================================
res, path = [], [1, 2]
res.append(path)                # WRONG: later changes to path show up in res
res.append(path[:])             # RIGHT (or list(path))

# ============================================================
# 4. Negative division & modulo differ from C++
# ============================================================
print(-7 // 2, int(-7 / 2))     # -4 (floor)   -3 (truncate, like C++)
print(-7 % 3)                   # 2  (Python result has sign of divisor; C++ gives -1)
# Good news: (a - b) % MOD is always non-negative in Python.

# ============================================================
# 5. `is` vs `==`
# ============================================================
a = [1, 2]; b = [1, 2]
print(a == b, a is b)           # True False
# Use `is` only for None / identity: `if node is None`

# ============================================================
# 6. Recursion limit (default ~1000)
# ============================================================
import sys
sys.setrecursionlimit(10**6)
# Very deep recursion can still crash -> convert DFS to iterative with a stack.

# ============================================================
# 7. Strings are immutable -> s += c in a loop may be O(n^2)
# ============================================================
parts = []
for ch in "abc":
    parts.append(ch)
s = "".join(parts)

# ============================================================
# 8. Integer variables in nested functions need `nonlocal`
# ============================================================
def outer():
    total = 0
    def inner():
        nonlocal total          # without this -> UnboundLocalError
        total += 1
    inner()
    return total
# Lists/dicts can be mutated without nonlocal (you're not rebinding the name).

# ============================================================
# 9. Modifying a collection while iterating
# ============================================================
d = {1: "a", 2: "b"}
for k in list(d):               # iterate over a COPY of keys
    if k == 1:
        del d[k]

# ============================================================
# 10. list.pop(0) / insert(0) are O(n) -> use deque
#     `x in list` is O(n)              -> use set
#     list.sort() returns None         -> don't do arr = arr.sort()
# ============================================================

# ============================================================
# 11. Copy semantics
# ============================================================
x = [1, 2, 3]
y = x                           # alias
y.append(4)
print(x)                        # [1,2,3,4]
# copies: x[:], x.copy(), list(x), copy.deepcopy(x) for nested

# ============================================================
# 12. Floating point
# ============================================================
print(0.1 + 0.2 == 0.3)         # False
import math
print(math.isclose(0.1 + 0.2, 0.3))
print(int(math.sqrt(10**18 + 1)), math.isqrt(10**18 + 1))  # prefer isqrt for big ints

# ============================================================
# 13. Variable leaking & default sort direction
# ============================================================
for i in range(3):
    pass
print(i)                        # 2 -> loop variable still exists after the loop

"""
COMPLEXITY CHEAT SHEET
======================
list
  l[i], l[i]=x, len, append, pop()        O(1)
  pop(i), insert(i,x), remove(x), x in l   O(n)
  l[a:b], l.copy(), l + l2                 O(k) / O(n)
  sort / sorted                            O(n log n)
  min / max / sum / index / count          O(n)

dict / set (average)
  get, set, del, in                        O(1)
  iteration                                O(n)
  set ops a|b, a&b                         O(len(a)+len(b)) / O(min(len))

deque
  append, appendleft, pop, popleft         O(1)
  dq[i] (middle)                           O(n)

heapq
  heappush, heappop                        O(log n)
  heapify                                  O(n)
  heap[0]                                  O(1)
  nlargest(k, ...)                         O(n log k)

bisect
  bisect_left / bisect_right               O(log n)
  insort                                   O(n)  (shifting)

str
  s[i], len                                O(1)
  s + t, slicing, in, find, replace        O(n)
  "".join(list)                            O(total length)

C++ -> Python quick map
  vector<int>              list
  unordered_map / map      dict  (map: sort keys or SortedDict)
  unordered_set / set      set   (set: SortedList)
  multiset                 Counter / SortedList
  stack                    list (append / pop / [-1])
  queue / deque            collections.deque
  priority_queue (max)     heapq with negatives
  priority_queue (min)     heapq
  pair / tuple             tuple
  lower_bound/upper_bound  bisect_left / bisect_right
  INT_MAX / LLONG_MAX      float('inf') / sys.maxsize
  __builtin_popcount       x.bit_count()
  next_permutation         itertools.permutations (all) / write manually
  accumulate               sum() / itertools.accumulate
  memset(dp, -1)           dp = [-1] * n
"""

print("11_gotchas OK")
