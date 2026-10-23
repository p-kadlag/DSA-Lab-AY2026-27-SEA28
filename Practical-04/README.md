## Practical 4

### Practical Title
Decimal to Binary Conversion Using Stack.

### Problem Statement
Implement a Last-In-First-Out (LIFO) Stack abstract data type using an array in C to convert an arbitrary positive decimal integer into its positional binary equivalent.

### Objective
- Implement fundamental stack operations: `push()`, `pop()`, `isEmpty()`, and `isFull()`.
- Prevent stack overflow and underflow conditions using boundary validation.
- Apply LIFO access semantics to reverse remainder sequences in mathematical base conversions.

### Algorithm/Approach
1. Define a stack structure or an array `stack[MAX]` with an integer index pointer $top = -1$.
2. Define `push(val)`: If $top == MAX - 1$, raise overflow; otherwise, increment $top$ and store `val`.
3. Define `pop()`: If $top == -1$, raise underflow; otherwise, return `stack[top]` and decrement $top$.
4. Read a positive decimal integer $N$ from the user.
5. If $N == 0$, directly print $0$ and terminate.
6. While $N > 0$:
   - Calculate the binary remainder: $rem = N \pmod 2$.
   - Push $rem$ onto the stack.
   - Update $N = \lfloor N / 2 \rfloor$.
7. After the division loop completes, execute a loop while the stack is not empty:
   - Pop the top bit and print it to the console.
8. The resulting sequence of popped elements forms the correct binary representation.

### Data Structure/Concept Used
- Stack ADT (LIFO Principle)
- Array implementation of stacks
- Modulo and integer division arithmetic

### Test Cases
- **Test Case 1 (Standard Value):** $N = 13 \rightarrow$ Binary Output: `1101`.
- **Test Case 2 (Boundary Zero):** $N = 0 \rightarrow$ Binary Output: `0`.
- **Test Case 3 (Power of Two):** $N = 16 \rightarrow$ Binary Output: `10000`.

### Sample Input and Output
**Sample Input:**
```text
Enter a decimal integer: 25
```

**Sample Output:**
```text
Pushing remainders: 1 -> 0 -> 0 -> 1 -> 1
Popping from stack (LIFO order):
Binary equivalent: 11001
```

### Time Complexity
- **Time Complexity:** $O(\log_2 n)$ operations, since the value of $N$ is halved during each division cycle.

### Space Complexity
- **Auxiliary Space:** $O(\log_2 n)$ to store the binary digits on the stack.

### Conclusion
Confirmed that the Last-In-First-Out property of the stack data structure is suited for positional number base conversions, naturally reversing generated mathematical remainders into their correct positional order.

---
