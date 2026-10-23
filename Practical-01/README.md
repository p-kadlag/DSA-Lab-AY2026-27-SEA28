# Data Structures and Algorithms Lab (ET-MDM-S07) Lab Manual

---

## Practical 1

### Practical Title
Program to display different patterns using numbers, alphabets, and asterisks.

### Problem Statement
Design and implement modular C programs to generate and display distinct geometric and symmetrical patterns (including half pyramids, full pyramids, diamonds, and inverted triangles) utilizing numerical sequences, English alphabets, and asterisks.

### Objective
- Understand and implement single and nested loop constructs (`for`, `while`, `do-while`).
- Master coordinate mapping across two-dimensional grid systems (rows and columns).
- Manipulate character representations using ASCII code mappings and format specifiers.

### Algorithm/Approach
1. Read the total number of rows ($n$) from the user.
2. Initialize an outer loop variable $i$ from $1$ to $n$ to govern the vertical row traversal.
3. For centered or symmetrical patterns (e.g., pyramids, diamonds):
   - Execute a first inner loop from $1$ to $n - i$ to print the required leading whitespace characters.
   - Execute a second inner loop to compute and print the visible elements (numbers, alphabets, or asterisks) based on the row index $i$.
4. For alphabet-based patterns, initialize a base character variable (e.g., `'A'` or ASCII value $65$) and increment it across rows or columns as specified.
5. Print a newline character `\n` at the completion of each outer loop iteration.
6. For inverted or diamond patterns, mirror the above logic using a decremental outer loop running from $n - 1$ down to $1$.

### Data Structure/Concept Used
- Nested iteration control structures
- Standard input/output streams
- ASCII character arithmetic

### Test Cases
- **Test Case 1 (Standard Input):** $n = 5$ generates a complete five-tier pyramid/diamond.
- **Test Case 2 (Minimal Boundary Input):** $n = 1$ renders exactly one isolated character without infinite loops or formatting errors.
- **Test Case 3 (Invalid Input):** $n \le 0$ triggers an input validation check prompting the user for a strictly positive integer.

### Sample Input and Output
**Sample Input:**
```text
Enter number of rows: 4
```

**Sample Output (Pyramid Pattern):**
```text
   *
  ***
 *****
*******
```

**Sample Output (Alphabet Pattern):**
```text
A
B B
C C C
D D D D
```

### Time Complexity
- Best, Average, and Worst Case: $O(n^2)$ due to the nested execution of row and column loops.

### Space Complexity
- Auxiliary Space: $O(1)$ since only a fixed set of scalar counter variables are maintained in memory.

### Conclusion
Demonstrated the application of nested loops in manipulating two-dimensional terminal layouts, establishing full control over row-column boundary limits, leading space indentation, and ASCII-based sequence generation.

---
