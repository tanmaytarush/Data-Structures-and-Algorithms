"""
06. heapq -> Priority Queue
---------------------------
Python's heapq is a MIN-HEAP on a plain list.
  heappush / heappop   O(log n)
  heapify              O(n)
  heap[0]              O(1) peek smallest
Max-heap: push negatives (-x), or use heapq.heappush_max etc. (Python 3.14+).
"""

import heapq

# ============================================================
# 1. Basics
# ============================================================
h = []
heapq.heappush(h, 5)
heapq.heappush(h, 1)
heapq.heappush(h, 3)
print(h[0])                  # 1   peek min
print(heapq.heappop(h))      # 1   pop min
print(len(h), bool(h))

arr = [5, 2, 8, 1]
heapq.heapify(arr)           # in-place, O(n)

print(heapq.heappushpop(arr, 4))   # push then pop (faster than both)
print(heapq.heapreplace(arr, 0))   # pop then push

print(heapq.nlargest(2, [5, 1, 8, 3]))    # [8, 5]
print(heapq.nsmallest(2, [5, 1, 8, 3]))   # [1, 3]
print(heapq.nlargest(1, ["aa", "b"], key=len))

# ============================================================
# 2. Max heap (negate values)
# ============================================================
mx = []
for x in [3, 1, 4, 1, 5]:
    heapq.heappush(mx, -x)
print(-mx[0])                # 5   peek max
print(-heapq.heappop(mx))    # 5

# ============================================================
# 3. Tuples -> compared lexicographically (priority, tiebreak, item)
# ============================================================
pq = []
heapq.heappush(pq, (2, "task B"))
heapq.heappush(pq, (1, "task A"))
dist, name = heapq.heappop(pq)       # (1, 'task A')

# If the payload isn't comparable (e.g. ListNode), add a unique counter:
#   heapq.heappush(pq, (val, i, node))

# ============================================================
# 4. Custom objects -> define __lt__
# ============================================================
class Task:
    def __init__(self, pri, name):
        self.pri, self.name = pri, name
    def __lt__(self, other):          # heap uses only `<`
        return self.pri < other.pri

t = []
heapq.heappush(t, Task(3, "c"))
heapq.heappush(t, Task(1, "a"))
print(heapq.heappop(t).name)          # 'a'

# ============================================================
# 5. Classic patterns
# ============================================================

# Kth largest element -> min-heap of size k
def kth_largest(nums, k):
    h = []
    for x in nums:
        heapq.heappush(h, x)
        if len(h) > k:
            heapq.heappop(h)
    return h[0]
print(kth_largest([3, 2, 1, 5, 6, 4], 2))   # 5

# Top K frequent
from collections import Counter
def top_k_frequent(nums, k):
    return [x for x, _ in heapq.nlargest(k, Counter(nums).items(), key=lambda kv: kv[1])]
print(top_k_frequent([1, 1, 1, 2, 2, 3], 2))  # [1, 2]

# Merge K sorted lists
def merge_k_sorted(lists):
    h = [(lst[0], i, 0) for i, lst in enumerate(lists) if lst]
    heapq.heapify(h)
    res = []
    while h:
        val, i, j = heapq.heappop(h)
        res.append(val)
        if j + 1 < len(lists[i]):
            heapq.heappush(h, (lists[i][j + 1], i, j + 1))
    return res
print(merge_k_sorted([[1, 4, 5], [1, 3, 4], [2, 6]]))
# Also: list(heapq.merge(*lists))

# Median from data stream -> two heaps
class MedianFinder:
    def __init__(self):
        self.lo = []   # max-heap (negated) -> smaller half
        self.hi = []   # min-heap           -> larger half

    def addNum(self, num):
        heapq.heappush(self.lo, -num)
        heapq.heappush(self.hi, -heapq.heappop(self.lo))
        if len(self.hi) > len(self.lo):
            heapq.heappush(self.lo, -heapq.heappop(self.hi))

    def findMedian(self):
        if len(self.lo) > len(self.hi):
            return -self.lo[0]
        return (-self.lo[0] + self.hi[0]) / 2

mf = MedianFinder()
for x in [1, 2, 3]:
    mf.addNum(x)
print(mf.findMedian())   # 2

# Dijkstra -> see 09_dsa_templates.py

print("06_heapq OK")
