# Circular Doubly Linked List with Cursor

This C program implements a circular doubly linked list with a movable cursor node. The list supports insertion, deletion, navigation, and display operations relative to the cursor's position.

## Features

- Circular doubly linked list structure
- Maintains a current cursor node for operations
- Supports commands:
  - `insert <value> <count>`: Insert `<count>` nodes with `<value>` after the cursor
  - `erase <count>`: Delete `<count>` nodes after the cursor
  - `move <steps>`: Move the cursor forward (positive) or backward (negative) by `<steps>`
  - `show`: Print the list starting from the current cursor node

## Input Format

- First line: Two integers `x` and `n`, initial node value and number of operations
- Next `n` lines: Each contains one command with its parameters as described above

## Example

### Input
10 6  
insert 20 2  
show  
move 2  
erase 1  
show  
move -1  
show  

### Output
10 20 20  
20 20 10  
20 10  