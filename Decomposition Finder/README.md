# Special Sum Decomposition Finder

This program finds the smallest positive integer `s` such that the input `x` can be expressed as the sum of a specific arithmetic series derived from the formula:

$x = k * ((2^i - 1) + (k - 1)/2)$


## Overview

- For each test case:
  - Finds the smallest value `s = k * 2^i` (with integer `k` and non-negative integer `i`) such that the above condition holds.
- If no valid `s` is found, returns `-1`.
- Always returns at least `2` when `x == 1`.

## Input Format

- An integer `t`, the number of test cases.
- `t` lines follow, each containing a single integer `x`.

## Output Format

- For each test case, prints the smallest valid value `s` that satisfies the condition.
- If no such value exists, prints `-1`.

## Example

### Input
3  
1  
3  
7  

### Output
2  
3  
7  