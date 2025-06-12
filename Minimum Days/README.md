# Minimum Days to Collect Coffee

This program determines the minimum number of initial days required to collect at least `m` units of coffee, following a specific decay rule for leftover coffee over time.

## Overview

- For each test case:
  - Reads the amount of coffee available each day.
  - Finds the minimum number of initial days `d` such that the total coffee collected (with decreasing value over time) is at least `m`.
- The value of leftover coffee decreases over every `d` days by 1.

## Input Format

- An integer `t`, the number of test cases.
- For each test case:
  - Two integers `n` and `m` — number of days and required coffee amount.
  - `n` integers representing the amount of coffee available each day.

## Output Format

- For each test case, prints the minimum number of initial days needed to collect at least `m` units of coffee.
- If it is impossible, prints `-1`.

## Example

### Input
2  
5 15  
3 3 3 3 3  
4 12  
5 4 2 1  

### Output
3  
2  