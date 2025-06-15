# Maximum Days of Color Pairing

This program calculates the maximum number of days you can pair balls of different colors, given counts of red, green, and blue balls.

## Overview

- On each day, you can remove two balls of **different** colors.
- The process continues until you can no longer form such pairs.
- For each test case, compute the **maximum number of days** this operation can be performed.

## Input Format

- An integer `t`, the number of test cases.
- For each test case:
  - Three integers `r`, `g`, and `b` representing the number of red, green, and blue balls.

## Output Format

- For each test case, print a single integer — the maximum number of days pairs can be formed.

## Example

### Input
3  
3 4 5  
10 1 1  
1 1 1  

### Output
6  
2  
1  