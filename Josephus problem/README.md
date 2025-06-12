# Josephus Problem Solver

This C program solves the classic Josephus problem using a circular linked list and recursion.

## Overview

- The Josephus problem involves `n` people standing in a circle and eliminating every `k`th person until only one remains.
- This program constructs a circular linked list of size `n`.
- The recursive function `solveJosephus` computes the position of the survivor without simulating the entire elimination.
- The program reads multiple test cases from standard input until EOF.

## Input Format

Each test case consists of two integers:
- `n`: the total number of people
- `k`: the step count for elimination

## Output Format

- Prints the position (1-based) of the last surviving person for each test case.

## Example

### Input
7 3  
5 2  

### Output
4  
3  