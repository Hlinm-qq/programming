# Doubly Linked List Text Editor Simulation

This program simulates a simple text editor cursor and editing operations using a doubly linked list.

## Overview

- Implements a doubly linked list with a cursor to represent text and editing position.
- Supports commands to insert characters, delete next character, backspace (delete current character), move cursor left/right by steps, and jump to start or end.
- The `show` command prints the list of characters, showing each node's previous, current, and next characters as a debugging aid.

## Supported Commands

- `insert <char>`: Insert a character after the cursor.
- `deletion`: Delete the character immediately after the cursor.
- `backspace`: Delete the character at the cursor position.
- `go_left <num>`: Move cursor left by `<num>` positions.
- `go_right <num>`: Move cursor right by `<num>` positions.
- `go_home`: Move cursor to the start (head).
- `go_end`: Move cursor to the end (tail).
- `show`: Display the list of characters with context around the cursor.

## Input Format

- The first line contains the number of commands `n`.
- Next `n` lines each contain a command as described above.

## Output Format

- The `show` command prints the list contents showing each node as `prev_char_current_char_next_char`.
- The last printed line shows the cursor node with double underscore prefix.

## Example

### Input
10  
insert a  
insert b  
insert c  
go_left 2  
deletion  
go_end  
insert d  
show  
backspace  
show  

### Output
a_b_c b_c_d c_d_a __c_d_a  
a_b_c b_c_a __b_c_a 