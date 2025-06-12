# Binary Search with Query Responses

This program performs binary search queries on a sorted array and reports the position of queried values.

## Overview

- Reads the size of the array `n` and the number of queries `q`.
- Reads `n` sorted integers into an array.
- For each query, performs a binary search for the given value.
- Prints the 1-based index if found; otherwise prints a failure message.
- Supports multiple test cases until input ends.

## Input Format

- Two integers `n` and `q`.
- A line with `n` integers sorted in ascending order.
- `q` lines, each containing an integer value to search for.

## Output Format

- For each query:
  - Prints the 1-based index of the value if found.
  - Prints `"Break your bridge!"` if the value is not found.

## Example

### Input
5 3  
1 3 5 7 9  
3  
4  
9  

### Output
2  
Break your bridge!  
5  