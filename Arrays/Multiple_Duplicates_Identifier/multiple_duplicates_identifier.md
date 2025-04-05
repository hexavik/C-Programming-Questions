# Mutliple Duplicates Identifier

## Problem Statement

Given an integer array, design a program to identify all the numbers that appear more than once in the array.

## Requirements

Write a function or program that takes an integer array as input and returns a list of numbers that have duplicates in the array.

## Input

A single integer array `arr` of size `n`, where `n≥1`.

```bash
arr = [4, 3, 2, 7, 8, 2, 3, 1]
```

## Output

An array or list of integers representing the numbers that appear more than once in the input array.

```bash
result = [2, 3]
```

## Constraints

- The input array may contain both positive and negative integers.
- The output list should only include each duplicate number once, regardless of how many times it appears.
- If no duplicates are found, the output should be an empty list.

> [!NOTE]
>
> - Aim for an efficient solution in terms of time and space complexity. If extra space is allowed, consider using a hash table or dictionary.
> - For an **in-place** solution, consider using the input array itself for marking visited elements.
