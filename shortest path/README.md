# Thanos Eliminator Path Finder

This program finds the shortest path to eliminate all Thanos ('T') targets on a grid map, starting from an initial position ('I') and avoiding obstacles ('C').

## Overview

- Accepts a 2D grid of characters representing the map.
- 'I' marks the starting point.
- 'T' marks targets that must be reached.
- 'C' marks obstacles that cannot be traversed.
- Empty cells are traversable.
- Uses Breadth-First Search (BFS) to find the minimum number of steps required to reach all 'T' cells.
- Outputs the shortest number of steps required to eliminate all targets, or -1 if impossible.

## Input Format

- Two integers `n` and `m` — number of rows and columns in the map.
- A grid of `n` lines, each with `m` characters:
  - 'I': Initial position
  - 'T': Thanos (targets)
  - 'C': Obstacle
  - Any other character: open space

## Output Format

- A single integer — the minimum number of steps to reach all 'T' targets, or -1 if not possible.

## Example

### Input
4 5  
I...T  
.C.C.  
..C..  
T...T  

### Output
10  