# Group Count by Shared Characters

This program determines how many distinct groups of strings exist based on shared characters. Two strings belong to the same group if they share **at least one common character**, directly or indirectly.

## Overview

- Each string is initially treated as a separate group.
- If a string shares any character with a previously seen group, they are merged.
- The final output is the number of distinct groups after processing all strings in a test case.

## Input Format

- An integer `t`, the number of test cases.
- For each test case:
  - An integer `n`, the number of strings.
  - `n` strings consisting of lowercase English letters.

## Output Format

- For each test case, print a single integer — the number of distinct groups formed.

## Example

### Input
2  
4  
ab 
bc  
de   
ef   
3  
abc  
def  
gh  

### Output
2  
3  