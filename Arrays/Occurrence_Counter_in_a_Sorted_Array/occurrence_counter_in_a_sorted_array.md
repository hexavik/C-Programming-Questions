# Occurrence Counter in a Sorted Array

## Problem Statement

Given a sorted integer array and a target number, design a program to count the number of times the target appears in the array.

## Requirements

Write a function or program that takes a sorted array and a target number as inputs and returns the count of occurrences of the target in the array.

## Input

A sorted integer array `arr` of size `n`, where `n≥1`. An integer `target` to find in the array.

```bash
arr = [1, 2, 2, 2, 3]
target = 2
```

## Output

An integer representing the number of times the `target` appears in the array.

```bash
result = 3
```

## Constraints

- The input array is sorted in ascending order.
- The array may contain duplicate elements.
- If the target is not found, the output should be `0`.

> [!NOTE]
>
> - Aim for an efficient solution using binary search techniques to find the first and last occurrence of the target, achieving **O(log n)** time complexity.
> - A straightforward solution could involve linear traversal, with a complexity of **O(n)**.
