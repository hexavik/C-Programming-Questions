# Checking Anagram between Two Strings

**Problem Statement:**

Determine whether two given strings are anagrams of each other. Two strings are considered anagrams if they contain the same characters with the same frequency, regardless of the order.

**Requirements:**

Write a program or function to check if the given strings are anagrams.

**Input:**

A string `str1` containing characters (letters, digits, or symbols).
Another string `str2` to compare against `str1`.

```bash
str1 = "listen"
str2 = "silent"
```

**Output:**

Return `true` if the two strings are anagrams, else `false`.

```bash
result = true
```

**Constraints:**

- Both input strings can contain uppercase and lowercase letters. Comparisons should be case-insensitive.
- Strings may include non-alphabetical characters, which should be ignored during comparisons.
- Empty strings cannot be anagrams of non-empty strings.

**Notes:**

- Approach:
  - Normalize both strings by: Removing non-alphabetical characters and converting all characters to lowercase.
  - Count the frequency of each character in both strings.
  - Compare the character frequency distributions of the two strings.
- Optimal Solution:
  - Use a hash map or dictionary to count character frequencies.
  - Alternatively, sort both strings and compare them.
- Edge Cases:
  - Strings with different lengths cannot be anagrams.
  - Empty strings should return `False`.
  - Strings containing only spaces or special characters should be treated as empty.
