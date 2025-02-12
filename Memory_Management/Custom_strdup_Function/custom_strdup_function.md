# Cusotm `strdup` Function

**Problem Statement:**

Implement a custom `strdup` function that copies a string into dynamically allocated memory and returns the address of the new string.

**Requirements:**

- Memory Allocation: Use `malloc` to allocate `strlen(input) + 1` bytes to store the null-terminated string.
- String Copying: Use `strcpy` or a loop to copy the string into the allocated memory.
- Handling Edge Cases: An empty input string (`""`) should return a valid dynamically allocated empty string. The function should correctly handle strings with spaces, special characters, and digits.
- Memory Management: Ensure the caller is responsible for calling `free()` on the returned pointer to avoid memory leaks.

**Input:**

A null-terminated string (e.g., "hello").

```bash
input = "hello"
```

**Output:**

A pointer to a dunamically allocated copy of the input string.

```bash
Address of dynamically allocated "hello"
```

**Constraints:**

- The function should **not modify the original string**.
- It should **return `NULL` if memory allocation fails**.
- `NULL` input handling is optional but can be considered for robustness.

> [!NOTE]
> Performance Considerations:
>
> - The function should run in O(n) time complexity, where nn is the length of the string
> - Space complexity is O(n) due to dynamic memory allocation.
