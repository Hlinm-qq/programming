# Substring Occurrence Counter

This program counts occurrences of a given substring within specified ranges of a main string.

## Overview

- Reads a main string and a substring.
- Preprocesses the main string to quickly count how many times the substring appears up to any position.
- Supports multiple queries asking for the maximum count of substring occurrences in various intervals.
- Prints the maximum number of substring occurrences found among the queries.

## Input Format

- A main string (up to 1000 characters).
- A substring to search for (up to 1000 characters).
- An integer `q`, the number of queries.
- Each of the next `q` lines contains two integers `l` and `r`, representing the substring search interval (1-based indices).

## Output Format

- Prints a single integer — the maximum count of substring occurrences in any queried interval.

## Example

### Input
abcabcabc  
abc  
3  
1 3  
1 6  
4 9  

### Output
2  