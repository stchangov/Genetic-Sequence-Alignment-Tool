# Genetic Sequence Alignment Tool

## Description
A command-line program that calculates the similarity between two genetic sequences using **edit distance**. It employs **dynamic programming** to generate an optimal alignment, showing matches, mismatches, and gaps between sequences.

## Features
- Computes the minimum edit distance between two sequences.
- Produces a clear alignment with step-by-step costs.
- Efficiently handles sequences of any length using a 2D dynamic programming table.
- Correctly handles edge cases, including empty sequences.

## Usage
Run the program and provide two sequences as input:

```bash
./EDistance
GACT
GAT
```

The output displays the edit distance followed by the alignment:

```text
Edit distance = 4
G - 2
A A 0
C - 2
T T 0
```

## Example
Input:  
```
GACT
GAT
```
Output:  
```
Edit distance = 4
G - 2
A A 0
C - 2
T T 0
```

## Performance
- Efficient memory usage with a 2D vector.
- Execution time scales reasonably with sequence length.
- Tested with sequences up to 100,000 characters.
