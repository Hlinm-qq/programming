# Binary Tree Postorder Traversal from Inorder and Preorder

This program reconstructs a binary tree from given inorder and preorder traversal sequences and outputs the postorder traversal of the reconstructed tree.

## Overview

- Reads the number of nodes in the tree.
- Reads the inorder traversal sequence.
- Reads the preorder traversal sequence.
- Rebuilds the binary tree using these sequences.
- Prints the postorder traversal of the reconstructed tree.
- Repeats for multiple test cases until input ends.

## Input Format

- An integer `n`, the number of nodes.
- A line of `n` integers representing the inorder traversal.
- A line of `n` integers representing the preorder traversal.

Multiple test cases can be provided sequentially.

## Output Format

- For each test case, prints `testcaseX: ` followed by the postorder traversal of the tree (`X` is the test case number starting from 1).

## Example

### Input
8  
4 8 2 5 1 6 3 7  
1 2 4 8 5 6 3 7  

### Output
testcase1: 8 4 5 2 6 7 3 1  