"""
03. Strings
-----------
Strings are IMMUTABLE. s[i] = 'x' is an error.
  -> convert to list, modify, then "".join(list)
  -> building with s += c in a loop can be O(n^2): append to a list and join once.
"""

import string

s = "Hello World"

# ============================================================
# 1. Access & basics
# ============================================================
print(len(s), s[0], s[-1], s[0:5], s[::-1])
print("lo" in s)                 # substring check
for ch in s: pass
for i, ch in enumerate(s): pass

# ============================================================
# 2. Case & character checks
# ============================================================
print(s.lower(), s.upper(), s.title(), s.swapcase(), "abc".capitalize())
c = "a"
print(c.isalpha(), c.isdigit(), c.isalnum(), c.isspace(), c.islower(), c.isupper())
print("12a".isdigit(), "123".isnumeric())

# ============================================================
# 3. Search
# ============================================================
print(s.find("o"))        # 4   (-1 if not found)
print(s.rfind("o"))       # 7   last occurrence
print(s.index("o"))       # 4   (ValueError if not found)
print(s.count("l"))       # 3
print(s.startswith("He"), s.endswith("ld"))

# ============================================================
# 4. Split / Join / Strip / Replace
# ============================================================
words = "  the sky   is blue ".split()       # ['the','sky','is','blue'] (any whitespace)
parts = "a,b,,c".split(",")                  # ['a','b','','c']
print(" ".join(reversed(words)))             # 'blue is sky the'
print("-".join(["a", "b"]))
print("  hi  ".strip(), "xxhixx".strip("x"), "  hi".lstrip(), "hi  ".rstrip())
print(s.replace("l", "L"))                   # all occurrences
print(s.replace("l", "L", 1))                # first only
print("a1b2".translate(str.maketrans("", "", "0123456789")))  # remove digits -> 'ab'

# ============================================================
# 5. Modify (via list)
# ============================================================
chars = list("hello")
chars[0] = "j"
print("".join(chars))                         # 'jello'

res = []                                      # efficient string building
for ch in "abc":
    res.append(ch * 2)
print("".join(res))                           # 'aabbcc'

# ============================================================
# 6. Character <-> index (frequency arrays)
# ============================================================
freq = [0] * 26
for ch in "banana":
    freq[ord(ch) - ord("a")] += 1
print(freq[0])                                # 3 (a's)
print(chr(ord("a") + 1))                      # 'b'

# ============================================================
# 7. Formatting
# ============================================================
name, val = "pi", 3.14159
print(f"{name} = {val:.2f}")                  # 'pi = 3.14'
print(f"{42:05d}")                            # '00042'
print(f"{5:b}", f"{255:x}")                   # binary, hex
print(f"{'left':<8}|{'right':>8}|{'mid':^8}")
print(str(123), int("123"), "ab" * 3)

# ============================================================
# 8. string module constants
# ============================================================
print(string.ascii_lowercase)   # 'abcdefghijklmnopqrstuvwxyz'
print(string.ascii_uppercase)
print(string.digits)            # '0123456789'
print(string.ascii_letters, string.punctuation)

# ============================================================
# 9. Comparison & sorting
# ============================================================
print("apple" < "banana")       # lexicographic comparison works directly
print("".join(sorted("dcba")))  # 'abcd' -> sorted string (anagram key)
print(sorted("dcba") == sorted("abcd"))  # anagram check

# ============================================================
# 10. Common patterns
# ============================================================
def is_palindrome(t: str) -> bool:
    t = "".join(ch.lower() for ch in t if ch.isalnum())
    return t == t[::-1]
print(is_palindrome("A man, a plan, a canal: Panama"))

# All substrings O(n^2)
t = "abc"
subs = [t[i:j] for i in range(len(t)) for j in range(i + 1, len(t) + 1)]

# Expand around center (longest palindromic substring)
def expand(t, l, r):
    while l >= 0 and r < len(t) and t[l] == t[r]:
        l -= 1; r += 1
    return t[l + 1:r]

# Group anagrams key
from collections import defaultdict
groups = defaultdict(list)
for w in ["eat", "tea", "tan", "ate"]:
    groups[tuple(sorted(w))].append(w)
print(list(groups.values()))

# Compare char counts
from collections import Counter
print(Counter("anagram") == Counter("nagaram"))   # True

# String <-> list of ints
digits = [int(d) for d in "12345"]
print("".join(map(str, digits)))

print("03_strings OK")
