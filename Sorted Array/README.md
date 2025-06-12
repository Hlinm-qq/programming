# Frequency Query on Sorted Array

This program counts occurrences of unique numbers in a sorted array and answers frequency queries efficiently.

## Overview

- Reads the size of the array `n`.
- Reads `n` integers and sorts them.
- Extracts unique numbers and counts their occurrences.
- For each query, performs binary search on the unique number list.
- Prints the frequency of the queried number, or `0` if not found.

## Input Format

- An integer `n`, the number of elements.
- A line with `n` integers.
- An integer `q`, the number of queries.
- `q` lines each containing an integer query.

## Output Format

- For each query, prints the frequency count of the queried number in the array.

## Example

### Input
7  
1 2 2 3 3 3 4  
3  
2  
3  
5  

### Output
2  
3  
0  