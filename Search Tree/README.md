# Binary Search Tree Operations: Query, Insert, and Delete

This program builds a balanced binary search tree (BST) from a sorted array, supports querying and deleting nodes by value, and inserting new nodes.

## Overview

- Builds a balanced BST from a sorted array of integers.
- Supports two operations via commands:
  - `heatstroke x`: Queries if `x` exists in the BST; if yes, deletes the node with value `x` and prints confirmation; otherwise prints a failure message.
  - Insert operation (any command other than `heatstroke`): Inserts a new node with value `x` into the BST.
- Frees all allocated memory after processing.

## Input Format

- An integer `n`, the number of elements in the initial sorted array.
- `n` integers in ascending order.
- An integer `q`, the number of commands.
- `q` lines, each containing a command string and an integer `x`.

## Output Format

- For each `heatstroke` command:
  - Prints `"We might as well eat it."` if the value existed and was deleted.
  - Prints `"No dinner tonight."` if the value was not found.

## Example

### Input
5  
1 3 5 7 9  
4  
heatstroke 5  
heatstroke 6  
insert 4  
heatstroke 4  

### Output
We might as well eat it.  
No dinner tonight.  
We might as well eat it.  