# Alphabetically Encoding a String

**Problem Statement:**

Encode a given string by replacing each character with the third character after it in the English alphabet. If a character exceeds 'z', it should wrap around to the start of the alphabet.

**Requirements:**

Write a program or function to transform the input string as described, ensuring that only alphabetical characters are processed, while preserving their case.

**Input:**

A string `inputString` containing any combination of lowercase and uppercase letters.

```bash
inputString = "abc"
```

**Output:**

A new string where each alphabetical character is replaced with the third character after it in the alphabet. Non-alphabetical characters remain unchanged.

```bash
result = "def"
```

**Constraints:**

- The string can include both lowercase (`a-z`) and uppercase (`A-Z`) letters.
- Non-alphabetical characters should not be altered.
- Wrapping occurs after 'z' for lowercase letters and after 'Z' for uppercase letters.

**Notes:**

> [!NOTE]
> - Transformation Rules:
>   - For lowercase letters: `newChar = ((originalChar - 'a' + 3) % 26) + 'a'`
>   - For uppercase letters: `newChar = ((originalChar - 'A' + 3) % 26) + 'A'`
> - Non-alphabetical characters (e.g., punctuation, digits, spaces) remain unchanged in the output.
> - Use modular arithmetic to handle wrapping within the alphabet.
