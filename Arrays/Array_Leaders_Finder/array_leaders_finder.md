# Array Leaders Finder

## Problem Statement

Given two integer arrays, your goal is to design a program that idnetifies the leaders in the array. Leaders are defined as elements that remain greater than or equal to all elements to their right when traversing the array from right to left.

## Requirements

Write a function or program that takes an integer array as input and returns a new array containing the leader elements.

## Input

The input consists of single integer array, denoted as `arr`.

```bash
arr = [16, 17, 4, 3, 5, 2]
```

## Output

The program should outpuut a new array representing the leader elements of the input array.

```bash
leaders = [17, 5, 2]
```

## Constraints

- The input arrays can contain both positive and negative iintegers.
- If an element appears more than once in the input array, it should be considered as a leader only if it satisfies the leader condition for its rightmost occurrence.
