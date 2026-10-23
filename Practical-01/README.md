## Practical 1: Pattern Printing Using Nested Loops in C

### 1. Practical Title

Pattern Printing Using Nested for Loops in C

### 2. Problem Statement

Write C programs using nested loops to print different patterns:

* A right-angle triangle containing numbers.

* A diamond-like pattern containing repeated numbers.

* A pyramid made of asterisks (`*`).

* A pyramid pattern using alphabets.

The programs use a fixed value $n = 4$, as shown in the supplied source code.

### 3. Objective

* Understand how nested `for` loops work in C.

* Use loops to control the number of rows and the contents of each row.

* Use spaces to align pattern output.

* Practice printing numbers, symbols, and alphabets.

### 4. Algorithm / Approach

#### Program 1(a): Right-Angle Triangle with Numbers

1. Set $n = 4$.

2. Run the outer loop from $i = 1$ to $i \le n$ to control the rows.

3. For each row, run the inner loop from $j = 1$ to $j \le i$.

4. Print $j$ followed by a space.

5. Print a newline after each row.

#### Program 1(b): Diamond-Like Pattern with Numbers

1. Set $n = 4$.

2. Use the first outer loop, from $i = 1$ to $i \le n$, to print the upper half.

3. Print leading spaces using a loop that starts at $n - 1$ and decreases to $i$.

4. Print the current row number $i$, repeated $i$ times.

5. Use a second outer loop, from $i = n - 1$ down to $i > 0$, to print the lower half.

6. Print leading spaces and repeat the current row number as specified by the source code.

7. Print a newline after each row.

#### Program 1(c): Pyramid with Asterisks

1. Set $n = 4$.

2. Run the outer loop from $i = 1$ to $i \le n$.

3. Print leading spaces using an inner loop from $j = n - 1$ down to $j \ge i$.

4. Print `* ` exactly $i$ times.

5. Print a newline after each row.

#### Program 1(d): Pyramid Using Alphabets

1. Set $n = 4$.

2. Run the outer loop from $i = 0$ to $i < n$.

3. Set $ch = \text{'A'}$ at the beginning of each row.

4. Print leading spaces using a loop from $j = n - 1$ down to $j > i$.

5. Print ascending characters from `A` through the character at position $i$.

6. Print the descending characters to form a mirrored alphabet pattern.

7. Print a newline after each row.

### 5. Data Structure / Concept Used

* **Nested loops:** An outer loop controls rows; inner loops control spaces and pattern characters.

* **Variables:** $i$ and $j$ are loop counters; $n$ stores the pattern size.

* **Character arithmetic:** In Program 1(d), $ch + j$ generates successive alphabet characters.

* **Formatted output:** `printf()` prints numbers, characters, symbols, spaces, and newlines.

* No arrays, linked lists, or other complex data structures are used.

### 6. Test Cases

| Test Case | Input / Configuration | Expected Result | 
| ----- | ----- | ----- | 
| **TC1** | $n = 4$, Program 1(a) | Four rows of increasing numbers | 
| **TC2** | $n = 4$, Program 1(b) | Upper and lower halves of the number pattern | 
| **TC3** | $n = 4$, Program 1(c) | Four rows of asterisks in a pyramid arrangement | 
| **TC4** | $n = 4$, Program 1(d) | Four rows of a mirrored alphabet pattern | 

*Note: The supplied programs hard-code* $n = 4$*; they do not read* $n$ *from the keyboard. These test cases describe the supplied configuration rather than claiming that other values were tested.*

### 7. Sample Input and Output

The programs do not accept user input. The value $n = 4$ is set inside each program.

#### Program 1(a): Right-Angle Triangle with Numbers

```
1
1 2
1 2 3
1 2 3 4

```

#### Program 1(b): Diamond-Like Pattern with Numbers

```
   1
  2 2
 3 3 3
4 4 4 4
 3 3 3
  2 2
   1

```

#### Program 1(c): Pyramid with Asterisks

```
   *
  * *
 * * *
* * * *

```

#### Program 1(d): Pyramid Using Alphabets

```
   A
  ABA
 ABCBA
ABCDCBA

```

### 8. Time Complexity

Let $n$ be the number of rows.

* **Program 1(a):** The inner loop runs $i$ times for each row, so the total work is $(1 + 2 + \dots + n)$. Time complexity: $\mathcal{O}(n^2)$.

* **Program 1(b):** The nested loops print a total of a quadratic number of spaces and digits across the upper and lower halves. Time complexity: $\mathcal{O}(n^2)$.

* **Program 1(c):** Each row prints spaces and asterisks, with total work proportional to a quadratic sum. Time complexity: $\mathcal{O}(n^2)$.

* **Program 1(d):** Each row prints spaces and up to a linear number of characters, giving a quadratic total. Time complexity: $\mathcal{O}(n^2)$.

### 9. Space Complexity

All four programs use a fixed number of integer and character variables and do not allocate memory proportional to $n$. Their auxiliary space complexity is $\mathcal{O}(1)$, excluding the output displayed on the screen.

### 10. Conclusion

The practical demonstrates how nested `for` loops can generate number, symbol, and alphabet patterns. By changing loop bounds and printing spaces, the programs create different shapes and alignments. The programs also illustrate character arithmetic for generating alphabet sequences.

#### Source Programs

* `program1a.c` — Right-angle triangle with numbers

* `program1b.c` — Diamond-like pattern with numbers

* `program1c.c` — Pyramid with asterisks

* `program1d.c` — Pyramid using alphabets
