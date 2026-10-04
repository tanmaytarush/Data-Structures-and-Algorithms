"""
09. DSA Templates in Python (mapped to this repo's topic folders)
-----------------------------------------------------------------
Binary Search | Linked List | Recursion/Backtracking | Stack & Queue |
Sliding Window | Binary Trees | BST | Graphs | DP | Tries
"""

import heapq
from collections import deque, defaultdict
from functools import cache
from typing import List, Optional

# ============================================================
# 02. Binary Search
# ============================================================
def binary_search(nums, target):
    lo, hi = 0, len(nums) - 1
    while lo <= hi:
        mid = (lo + hi) // 2          # no overflow in Python
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            lo = mid + 1
        else:
            hi = mid - 1
    return -1

# Binary search on answer: smallest x in [lo, hi] where ok(x) is True
def first_true(lo, hi, ok):
    while lo < hi:
        mid = (lo + hi) // 2
        if ok(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo
print(first_true(1, 100, lambda x: x * x >= 50))   # 8

# ============================================================
# 04. Linked List
# ============================================================
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def build_list(arr):
    dummy = cur = ListNode()
    for x in arr:
        cur.next = ListNode(x)
        cur = cur.next
    return dummy.next

def to_list(head):
    out = []
    while head:
        out.append(head.val)
        head = head.next
    return out

def reverse_list(head):
    prev, cur = None, head
    while cur:
        cur.next, prev, cur = prev, cur, cur.next
    return prev

def middle(head):                     # slow / fast pointers
    slow = fast = head
    while fast and fast.next:
        slow, fast = slow.next, fast.next.next
    return slow

def has_cycle(head):
    slow = fast = head
    while fast and fast.next:
        slow, fast = slow.next, fast.next.next
        if slow is fast:              # `is` -> same object
            return True
    return False

print(to_list(reverse_list(build_list([1, 2, 3]))))   # [3,2,1]

# ============================================================
# 05/17. Recursion & Backtracking
# ============================================================
def subsets(nums):
    res, path = [], []
    def backtrack(i):
        if i == len(nums):
            res.append(path[:])       # COPY the path!
            return
        path.append(nums[i])          # take
        backtrack(i + 1)
        path.pop()                    # undo
        backtrack(i + 1)              # not take
    backtrack(0)
    return res

def permutations(nums):
    res, used, path = [], [False] * len(nums), []
    def backtrack():
        if len(path) == len(nums):
            res.append(path[:])
            return
        for i in range(len(nums)):
            if used[i]:
                continue
            used[i] = True; path.append(nums[i])
            backtrack()
            used[i] = False; path.pop()
    backtrack()
    return res

def combination_sum(cands, target):
    res = []
    def backtrack(start, remain, path):
        if remain == 0:
            res.append(path[:]); return
        for i in range(start, len(cands)):
            if cands[i] <= remain:
                path.append(cands[i])
                backtrack(i, remain - cands[i], path)   # i (reuse allowed)
                path.pop()
    backtrack(0, target, [])
    return res
print(combination_sum([2, 3, 6, 7], 7))

# ============================================================
# 07. Stack & Queue -> monotonic stack
# ============================================================
def next_greater(nums):
    res, st = [-1] * len(nums), []    # stack holds indices
    for i, x in enumerate(nums):
        while st and nums[st[-1]] < x:
            res[st.pop()] = x
        st.append(i)
    return res
print(next_greater([2, 1, 2, 4, 3]))  # [4,2,4,-1,-1]

def valid_parentheses(s):
    pairs, st = {")": "(", "]": "[", "}": "{"}, []
    for ch in s:
        if ch in pairs:
            if not st or st.pop() != pairs[ch]:
                return False
        else:
            st.append(ch)
    return not st

# ============================================================
# 08. Sliding Window
# ============================================================
def longest_unique_substring(s):
    last, l, best = {}, 0, 0
    for r, ch in enumerate(s):
        if ch in last and last[ch] >= l:
            l = last[ch] + 1
        last[ch] = r
        best = max(best, r - l + 1)
    return best
print(longest_unique_substring("abcabcbb"))   # 3

def min_subarray_len(target, nums):           # variable window (shrink while valid)
    l, cur, best = 0, 0, float("inf")
    for r, x in enumerate(nums):
        cur += x
        while cur >= target:
            best = min(best, r - l + 1)
            cur -= nums[l]; l += 1
    return 0 if best == float("inf") else best

# ============================================================
# 11. Binary Trees
# ============================================================
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build_tree(arr):                    # level-order list with None -> tree
    if not arr or arr[0] is None:
        return None
    root = TreeNode(arr[0]); q = deque([root]); i = 1
    while q and i < len(arr):
        node = q.popleft()
        if i < len(arr) and arr[i] is not None:
            node.left = TreeNode(arr[i]); q.append(node.left)
        i += 1
        if i < len(arr) and arr[i] is not None:
            node.right = TreeNode(arr[i]); q.append(node.right)
        i += 1
    return root

def inorder(root):                      # recursive
    return inorder(root.left) + [root.val] + inorder(root.right) if root else []

def inorder_iter(root):                 # iterative with stack
    res, st, cur = [], [], root
    while cur or st:
        while cur:
            st.append(cur); cur = cur.left
        cur = st.pop()
        res.append(cur.val)
        cur = cur.right
    return res

def level_order(root):
    if not root:
        return []
    res, q = [], deque([root])
    while q:
        level = []
        for _ in range(len(q)):
            node = q.popleft()
            level.append(node.val)
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        res.append(level)
    return res

def max_depth(root):
    return 1 + max(max_depth(root.left), max_depth(root.right)) if root else 0

def diameter(root):
    best = 0
    def height(node):
        nonlocal best
        if not node:
            return 0
        l, r = height(node.left), height(node.right)
        best = max(best, l + r)
        return 1 + max(l, r)
    height(root)
    return best

t = build_tree([3, 9, 20, None, None, 15, 7])
print(level_order(t), inorder_iter(t), max_depth(t), diameter(t))

# ============================================================
# 12. BST
# ============================================================
def bst_insert(root, val):
    if not root:
        return TreeNode(val)
    if val < root.val:
        root.left = bst_insert(root.left, val)
    else:
        root.right = bst_insert(root.right, val)
    return root

def is_valid_bst(root, lo=float("-inf"), hi=float("inf")):
    if not root:
        return True
    if not (lo < root.val < hi):
        return False
    return is_valid_bst(root.left, lo, root.val) and is_valid_bst(root.right, root.val, hi)

# ============================================================
# 13. Graphs
# ============================================================
def build_graph(n, edges, directed=False):
    g = defaultdict(list)     # or [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        if not directed:
            g[v].append(u)
    return g

def dfs(g, start):
    seen, order = set(), []
    def go(u):
        seen.add(u); order.append(u)
        for v in g[u]:
            if v not in seen:
                go(v)
    go(start)
    return order

def num_islands(grid):
    rows, cols = len(grid), len(grid[0])
    def sink(r, c):
        if r < 0 or c < 0 or r >= rows or c >= cols or grid[r][c] != "1":
            return
        grid[r][c] = "0"
        for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            sink(r + dr, c + dc)
    count = 0
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == "1":
                sink(r, c); count += 1
    return count

def topo_sort(n, edges):                 # Kahn's algorithm (BFS)
    g, indeg = defaultdict(list), [0] * n
    for u, v in edges:
        g[u].append(v); indeg[v] += 1
    q = deque(i for i in range(n) if indeg[i] == 0)
    order = []
    while q:
        u = q.popleft(); order.append(u)
        for v in g[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                q.append(v)
    return order if len(order) == n else []   # [] -> cycle

def dijkstra(n, edges, src):             # edges: (u, v, w)
    g = defaultdict(list)
    for u, v, w in edges:
        g[u].append((v, w))
    dist = [float("inf")] * n
    dist[src] = 0
    pq = [(0, src)]
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue                     # stale entry
        for v, w in g[u]:
            if d + w < dist[v]:
                dist[v] = d + w
                heapq.heappush(pq, (dist[v], v))
    return dist
print(dijkstra(3, [(0, 1, 4), (0, 2, 1), (2, 1, 2)], 0))   # [0,3,1]

class DSU:                               # Disjoint Set Union / Union-Find
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
    def find(self, x):
        while self.parent[x] != x:
            self.parent[x] = self.parent[self.parent[x]]   # path compression
            x = self.parent[x]
        return x
    def union(self, a, b):
        ra, rb = self.find(a), self.find(b)
        if ra == rb:
            return False
        if self.size[ra] < self.size[rb]:
            ra, rb = rb, ra
        self.parent[rb] = ra
        self.size[ra] += self.size[rb]
        return True

def kruskal(n, edges):                   # MST
    dsu, total = DSU(n), 0
    for u, v, w in sorted(edges, key=lambda e: e[2]):
        if dsu.union(u, v):
            total += w
    return total

# ============================================================
# 14. Dynamic Programming
# ============================================================
# Top-down (memo)
def climb_stairs(n):
    @cache
    def f(i):
        if i <= 1:
            return 1
        return f(i - 1) + f(i - 2)
    return f(n)

# Bottom-up (tabulation) + space optimised
def rob(nums):
    prev2 = prev1 = 0
    for x in nums:
        prev2, prev1 = prev1, max(prev1, prev2 + x)
    return prev1

# 2D DP: LCS
def lcs(a, b):
    n, m = len(a), len(b)
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if a[i - 1] == b[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    return dp[n][m]

# 0/1 Knapsack (1D, iterate capacity backwards)
def knapsack(wt, val, W):
    dp = [0] * (W + 1)
    for w, v in zip(wt, val):
        for c in range(W, w - 1, -1):
            dp[c] = max(dp[c], dp[c - w] + v)
    return dp[W]

print(climb_stairs(5), rob([2, 7, 9, 3, 1]), lcs("abcde", "ace"), knapsack([1, 3, 4], [15, 20, 30], 4))

# ============================================================
# 15. Trie
# ============================================================
class TrieNode:
    __slots__ = ("children", "end")      # saves memory
    def __init__(self):
        self.children = {}
        self.end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    def insert(self, word):
        node = self.root
        for ch in word:
            node = node.children.setdefault(ch, TrieNode())
        node.end = True
    def _walk(self, s):
        node = self.root
        for ch in s:
            if ch not in node.children:
                return None
            node = node.children[ch]
        return node
    def search(self, word):
        node = self._walk(word)
        return node is not None and node.end
    def starts_with(self, prefix):
        return self._walk(prefix) is not None

tr = Trie(); tr.insert("apple")
print(tr.search("apple"), tr.search("app"), tr.starts_with("app"))

print("09_dsa_templates OK")
