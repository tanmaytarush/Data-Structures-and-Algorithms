"""
05. collections module
----------------------
from collections import Counter, defaultdict, deque, OrderedDict, namedtuple

NOTE: never name your own file `collections.py` - it shadows this module.
"""

from collections import Counter, defaultdict, deque, OrderedDict, namedtuple

# ============================================================
# 1. Counter  -> frequency map (dict subclass)
# ============================================================
c = Counter("banana")              # Counter({'a': 3, 'n': 2, 'b': 1})
c2 = Counter([1, 2, 2, 3, 3, 3])
print(c["a"], c["z"])              # 3 0   (missing keys -> 0, no KeyError)
c["a"] += 1
c["n"] -= 1
print(c.most_common(2))            # [('a', 4), ('b', 1)] or ties - top k by count
print(list(c.elements()))          # expands back into elements
print(sum(c.values()), len(c))     # total count, distinct count
c.update("aaa")                    # add counts
c.subtract("a")                    # subtract counts (can go to 0 / negative)

x, y = Counter("aab"), Counter("abc")
print(x + y)                       # add counts
print(x - y)                       # subtract, drops <= 0
print(x & y)                       # min of each  (intersection)
print(x | y)                       # max of each  (union)
print(Counter("listen") == Counter("silent"))   # anagram check

# Remove zero counts after subtract:
c += Counter()                     # unary trick: keeps only positive counts

# Sliding window freq pattern
window = Counter()
window["a"] += 1
window["a"] -= 1
if window["a"] == 0:
    del window["a"]                # keep len(window) == distinct count

# ============================================================
# 2. defaultdict -> dict with default factory
# ============================================================
freq = defaultdict(int)            # default 0
for ch in "hello":
    freq[ch] += 1

graph = defaultdict(list)          # adjacency list
edges = [(0, 1), (0, 2), (1, 2)]
for u, v in edges:
    graph[u].append(v)
    graph[v].append(u)             # undirected

groups = defaultdict(set)          # default empty set
groups["x"].add(1)

nested = defaultdict(lambda: defaultdict(int))   # 2-level map
nested["a"]["b"] += 1

# Trie in 1 line
Trie = lambda: defaultdict(Trie)
root = Trie()
node = root
for ch in "cat":
    node = node[ch]
node["#"] = True                   # end-of-word marker

# CAREFUL: just *reading* graph[k] inserts k. Use `k in graph` to check.

# ============================================================
# 3. deque -> double ended queue, O(1) both ends
#    Use for: Queue, BFS, sliding window max, 0-1 BFS
# ============================================================
dq = deque()
dq = deque([1, 2, 3])
dq.append(4)            # push back
dq.appendleft(0)        # push front
dq.pop()                # pop back   -> 4
dq.popleft()            # pop front  -> 0
print(dq[0], dq[-1])    # front, back (O(1)); middle indexing is O(n)
print(len(dq), bool(dq))
dq.extend([5, 6]); dq.extendleft([-1])
dq.rotate(1)            # rotate right by 1 (negative -> left)
dq.clear()
last3 = deque(maxlen=3) # fixed size, auto drops from other end
for i in range(5):
    last3.append(i)     # deque([2,3,4])

# BFS template
def bfs(start, graph):
    q = deque([start])
    seen = {start}
    order = []
    while q:
        u = q.popleft()
        order.append(u)
        for v in graph[u]:
            if v not in seen:
                seen.add(v)
                q.append(v)
    return order
print(bfs(0, graph))

# Level-order (process level by level)
q = deque([0]); seen = {0}; level = 0
while q:
    for _ in range(len(q)):
        u = q.popleft()
        for v in graph[u]:
            if v not in seen:
                seen.add(v); q.append(v)
    level += 1

# Sliding window maximum (monotonic deque of indices)
def max_sliding_window(nums, k):
    dq, res = deque(), []
    for i, x in enumerate(nums):
        while dq and nums[dq[-1]] <= x:
            dq.pop()
        dq.append(i)
        if dq[0] <= i - k:
            dq.popleft()
        if i >= k - 1:
            res.append(nums[dq[0]])
    return res
print(max_sliding_window([1, 3, -1, -3, 5, 3, 6, 7], 3))  # [3,3,5,5,6,7]

# ============================================================
# 4. OrderedDict -> remembers order + move_to_end (LRU Cache!)
# ============================================================
class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)          # mark as recently used
        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key)
        self.cache[key] = value
        if len(self.cache) > self.cap:
            self.cache.popitem(last=False)   # pop least recently used (front)

lru = LRUCache(2)
lru.put(1, 1); lru.put(2, 2); lru.get(1); lru.put(3, 3)
print(lru.get(2))     # -1 (evicted)

# ============================================================
# 5. namedtuple -> lightweight immutable record
# ============================================================
Point = namedtuple("Point", ["x", "y"])
p = Point(1, 2)
print(p.x, p.y, p[0])
x, y = p
p2 = p._replace(x=10)
Edge = namedtuple("Edge", "u v w")
edges = sorted([Edge(0, 1, 5), Edge(1, 2, 1)], key=lambda e: e.w)

print("05_collections_module OK")
