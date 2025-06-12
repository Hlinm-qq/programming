# Power-of-Two Mapping and Query Search

This program processes an array of integers, maps even numbers to a power-of-two based value modulo `10^9+7`, and then answers queries searching for these mapped values.

## Overview

- Reads `n` and `q`, the number of elements and queries.
- For each element:
  - If even, computes `2^(element/2) mod 1,000,000,007`.
  - If odd, maps to zero.
- Stores the mapped values along with original indices.
- Sorts the mapped array by values.
- For each query, performs binary search to find the query value in the mapped array.
- Prints the original 1-based index if found; otherwise prints a failure message.
- Supports multiple test cases until input ends.

## Input Format

- Two integers `n` and `q`.
- `n` integers representing the array elements.
- `q` lines, each containing a query integer.

## Output Format

- For each query:
  - Prints the 1-based original index of the element with the mapped value equal to the query.
  - Prints `"Go Down Chicken 404"` if not found.

## Example

### Input
5 2  
4 3 6 7 8  
4  
16  

### Output
1  
3  