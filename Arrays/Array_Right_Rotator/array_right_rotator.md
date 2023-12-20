# Array Right Rotator

**Problem Statement:**

Given an integer array and non-negative integer `k`, your task is to design a program that rotates the array to the right by `k` steps.

**Requirements:**

Write a function or program that takes an integer array and an integer `k` as input and modifies the array by moving its elements to the right, wrapping them around when they reach the end, for the specified number of steps.

**Input:**

The input consists of an integer array, denoted as `arr`, and a non-negative integer `k`.

```bash
arr = [1, 2, 3, 4, 5]
k = 2
```

**Output:**

The program should modify the input array toi represent the result of rotating it to the right by `k` steps.

```bash
result = [4, 5, 1, 2, 3]
```

**Constraints:**

- The input array can have duplicate elements.
- The value of `k` will not exceed the length of the array.
- You can assume that the input array has at least one element.
