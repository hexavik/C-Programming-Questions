# Missing Number Finder in a 1-to-500 Sequence

## Problem Statement

Given an integer array containing a sequence of numbers from 1 to 500 with exactly one number missing, design a program to identify the missing number.

## Requirements

Write a function or program that takes an integer array as input and determines the missing number from the sequence.

## Input

A single integer array `arr` of size 499, containing numbers from 1 to 500 in random order, with one number missing.

```bash
arr = [1, 2, 4, 5]
```

## Output

An integer representing the missing number in the sequence.

```bash
result = 3
```

## Constraints

- The array contains no duplicates.
- The array contains integers only within the range of 1 to 500.

> [!NOTE]
>
> - The solution should work efficiently, ideally in O(n) time.
> - Consider leveraging the mathematical formula for the sum of the fisrt `n` natural numbers: Sum = n × (n + 1)​ / 2
