# Maximum Range Sum in Circular Array

This C program reads an array and a series of queries, and finds the query range that yields the maximum sum. It supports circular ranges, meaning the end index can wrap around to the beginning of the array.

## Overview

- Input format:
  - First line: Two integers `n` and `q` (array size and number of queries)
  - Next line: `n` integers (the array values)
  - Next `q` lines: Each contains two integers `a` and `b`, indicating a query range
- For each query, the program calculates the sum of elements from index `a` to `b` (inclusive), wrapping around if `a > b`
- After processing all queries, the program outputs the range `(a, b)` with the maximum sum and its value

## Example

### Input
5 3
1 2 3 4 5
1 3
4 2
2 2

### Output
Max_range: (4,2); Value: 15