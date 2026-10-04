# Data Structures & Algorithms — C++ and Python

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white)
![Python](https://img.shields.io/badge/Python-3-3776AB?logo=python&logoColor=white)
![Problems](https://img.shields.io/badge/C%2B%2B%20solutions-500%2B-success)

My DSA practice, notes and solutions, organised by topic. Problems are grouped from basics up to advanced, with a difficulty split inside most topics. Most solutions have their time and space complexity written in the comments.

---

## 📂 Repository Layout

```
.
├── C++/                 # Main track, organised by topic (01 → 17)
├── Python/              # Python syntax notes, cheat sheets and DSA templates
├── Leetcode_daily/      # LeetCode daily challenge solutions
└── atcoder_contests/    # AtCoder Beginner Contest (ABC) submissions
```

---

## 🧱 C++ Track

### Foundations

| Folder | What's inside |
| --- | --- |
| [Basics_C++](C++/Basics_C++) | Syntax, I/O, control flow, arrays and references |
| [Patterns](C++/Patterns) | Classic star and number pattern printing |
| [C++_STL](C++/C++_STL) | Containers, iterators and algorithms in the STL |
| [Pointers](C++/Pointers) | Notes and demos on pointers, references and dynamic allocation |
| [OOPS](C++/OOPS) | Classes, inheritance, polymorphism, abstraction |
| [Basic_Maths](C++/Basic_Maths) | Digits, palindromes, GCD, primes, divisors |
| [Basic_Recursion](C++/Basic_Recursion) | First steps with recursion |
| [Basic_Hashing](C++/Basic_Hashing) | Frequency counting with arrays and maps |
| [Sorting](C++/Sorting) | Selection, bubble, insertion, merge and quick sort |

### Core Topics

| # | Topic | Subtopics |
| --- | --- | --- |
| 01 | [Arrays](C++/01.Arrays) | Easy · Medium · Hard |
| 02 | [Binary Search](C++/02.Binary%20Search) | 1D arrays · 2D arrays · Binary search on answer space |
| 03 | [Strings](C++/03.Strings) | Easy · Medium |
| 04 | [Linked List](C++/04.Linked%20List) | Singly LL · Doubly LL · Medium & hard problems |
| 05 | [Recursion](C++/05.Recursion) | Fundamentals · Subsequence patterns · Backtracking |
| 06 | [Bit Manipulation](C++/06.Bit%20Manipulation) | Basics · Interview problems · Advanced maths |
| 07 | [Stack and Queues](C++/07.Stack%20and%20Queues) | Basics · Infix/Postfix/Prefix · Monotonic stack · Implementations |
| 08 | [Sliding Window](C++/08.%20Sliding%20Window) | Medium · Hard |
| 09 | [Heaps](C++/09.%20Heaps) | Basics · Medium · Hard |
| 10 | [Greedy](C++/10.%20Greedy%20Approach) | Easy · Medium |
| 11 | [Binary Trees](C++/11.%20Binary%20Trees) | Traversals · Medium · Hard |
| 12 | [Binary Search Trees](C++/12.%20Binary%20Search%20Trees) | Concepts · Practice problems |
| 13 | [Graphs](C++/13.%20Graphs) | BFS/DFS · Topo sort · Shortest paths · MST · Other algorithms |
| 14 | [Dynamic Programming](C++/14.%20Dynamic%20Programming) | 1D · 2D · Subsequences · Strings · Stocks · LIS · Partition · Squares |
| 15 | [Tries](C++/15.%20Tries) | Theory · Problems |
| 16 | [Strings (Hard)](C++/16.%20Strings%20(Hard)) | Advanced string algorithms |
| 17 | [Recursion End-to-End](C++/17.%20Recursions%20end-to-end) | Basics · Patterns · Subsets · Combination sum · Permutations · Recursive sorts |

---

## 🐍 Python Track

[Python/Collections](Python/Collections) is a set of numbered reference files for writing DSA solutions in Python, most useful for interview prep:

| File | Covers |
| --- | --- |
| `01_builtins_and_syntax.py` | Core syntax and built-in functions |
| `02_lists.py` | List operations, slicing, comprehensions |
| `03_strings.py` | String methods and common tricks |
| `04_dict_set_tuple.py` | Hashing with dicts, sets and tuples |
| `05_collections_module.py` | `Counter`, `defaultdict`, `deque`, `OrderedDict` |
| `06_heapq.py` | Min-heaps, max-heaps and top-k patterns |
| `07_bisect_itertools_functools.py` | Binary search, combinatorics, memoisation |
| `08_bit_manipulation.py` | Bitwise tricks |
| `09_dsa_templates.py` | Templates that match the C++ topic folders (BS, LL, trees, graphs, DP, tries, …) |
| `10_oops.py` | Classes, dunder methods, dataclasses |
| `11_gotchas_and_complexity.py` | Common pitfalls and time complexities of built-in operations |

[Python/Basic_Maths](Python/Basic_Maths) has Python versions of the basic maths problems (count digits, reverse a number, palindrome, …).

---

## 🏆 Contests & Daily Practice

- **[Leetcode_daily](Leetcode_daily)**: solutions to LeetCode daily challenges.
- **[atcoder_contests](atcoder_contests)**: AtCoder Beginner Contest submissions, one folder per contest (e.g. `abc_473`).

---

## ▶️ Running the Code

**C++**

```bash
clang++ -std=c++17 -O2 file.cpp -o file && ./file
# or
g++ -std=c++17 -O2 file.cpp -o file && ./file
```

In VS Code, the build task in [C++/.vscode/tasks.json](C++/.vscode/tasks.json) compiles the active file (`⇧⌘B`).

**Python**

```bash
python3 path/to/file.py
```

---

## 🗺️ Learning Path

```
Basics → Patterns → STL → Maths/Hashing/Sorting
   → Arrays → Binary Search → Strings → Linked List → Recursion
   → Bit Manipulation → Stack & Queue → Sliding Window → Heaps → Greedy
   → Binary Trees → BST → Graphs → Dynamic Programming → Tries → Hard Strings
```

The numbered folders follow this order, so working through them from 01 to 17 builds each topic on the ones before it.

---

## 📌 Conventions

- Folder numbers show the recommended study order.
- Most topics are split by difficulty (`1.Easy`, `2.Medium`, `3.Hard`) or by sub-pattern.
- Each solution is a standalone file with its own `main()` / driver code.
- Complexity notes (`TC` / `SC`) are written as comments next to each approach.

---

⭐ If you find this useful, feel free to star the repo.
