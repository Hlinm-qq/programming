# Triangle Count with Constraints

This program computes the number of valid triangles that can be formed using three side lengths `x`, `y`, and `z`, where the side lengths are chosen from constrained ranges:

- `x ∈ [a, b]`
- `y ∈ [b, c]`
- `z ∈ [c, d]`

A **valid triangle** satisfies the **triangle inequality**:

$x + y > z$


## Problem Statement

Given ranges `[a, b]`, `[b, c]`, and `[c, d]`, count the number of **distinct integer triplets** `(x, y, z)` such that:
- `x` in `[a, b]`
- `y` in `[b, c]`
- `z` in `[c, d]`
- and `x + y > z`

## Input Format

- First line: integer `t` — number of test cases.
- For each test case: four integers `a`, `b`, `c`, `d`.

## Output Format

- For each test case, output the number of valid triangle triplets.

## Example

### Input
1  
1 2 3 4  

### Output
5  


## How It Works

1. Loop over all valid values of `x` in `[a, b]` and `y` in `[b, c]`.
2. For each `(x, y)` pair, compute `s = x + y`, and record how many times each sum `s` appears using a **difference array** technique.
3. Compute a prefix sum to track how many `(x, y)` pairs result in each `s`.
4. For each valid `z ∈ [c, d]`, count how many `(x, y)` pairs satisfy `x + y > z`.
5. Accumulate the total count of such triplets.

## Optimizations Used

- **Difference Array (`sum[]`)** for fast range updates.
- **Prefix Sums** to build cumulative frequencies.
- Efficient linear time algorithm avoiding triple loops.

## Variables

- `sum[i]`: Number of `(x, y)` pairs such that `x + y == i`.
- `ans[i]`: Number of such pairs where `x + y > i`.
- `total`: Total valid triangle triplets for one test case.

## Constraints

- Reasonable constraints (e.g., `a, b, c, d ≤ 5000`) ensure this algorithm runs efficiently in all cases.
