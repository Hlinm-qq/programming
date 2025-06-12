# Sandwich Dish Printer

This program reads and prints descriptions of different kinds of food, specifically sandwiches, using polymorphism and dynamic memory in C++.

## Overview

- Supports two food types:
  - `IdiotSandwich`: Created when input starts with "Ramsay", followed by an integer representing intelligence.
  - `NormalSandwich`: Created with any other name string.
- Uses polymorphism and virtual functions to print a type-specific message.
- Manages memory dynamically using a `Dish` wrapper class.
- Demonstrates use of abstract base classes, `enum class`, dynamic dispatch, and operator overloading.

## Input Format

- An integer `n`, the number of dishes.
- `n` lines follow, each representing one dish:
  - If the line starts with `"Ramsay"`, it is followed by an integer (e.g., `Ramsay 3`).
  - Otherwise, it is interpreted as a `NormalSandwich` with the name as the first word.

## Output Format

- For each dish, prints a line describing the sandwich:
  - `"An idiot sandwich with intelligence level X only."` for `IdiotSandwich`.
  - `"<name>. Masterpiece of sandwiches."` for `NormalSandwich`.

## Example

### Input
3  
Ramsay 1  
Clubhouse  
Ramsay 7  

### Output
An idiot sandwich with intelligence level 1 only.  
Clubhouse. Masterpiece of sandwiches.  
An idiot sandwich with intelligence level 7 only.  