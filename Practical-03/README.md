## Practical 3

### Practical Title
Searching Contact Names Using Sequential Search and Binary Search.

### Problem Statement
Develop a contact directory lookup program to search for a specific contact name from a telephone directory dataset using both Sequential (Linear) Search and Binary Search, followed by an empirical comparison of their operational efficiencies.

### Objective
- Implement Linear Search and Binary Search algorithms on string arrays.
- Understand the precondition of sorting for Binary Search.
- Evaluate the computational disparity between linear $O(n)$ and logarithmic $O(\log n)$ search behaviors.

### Algorithm/Approach
1. Store a list of contact names within an array of strings.
2. **Sequential Search Algorithm:**
   - Iterate a loop index $i$ from $0$ to $n - 1$.
   - Compare `contact[i]` with the target name using `strcmp()`.
   - If `strcmp() == 0`, return index $i$ and the total comparison count.
   - If the loop terminates without a match, report the contact as absent.
3. **Binary Search Algorithm:**
   - Sort the contact list in lexicographical (ascending) order.
   - Initialize pointers: $low = 0$, $high = n - 1$.
   - While $low \le high$:
     - Compute the midpoint: $mid = low + \lfloor(high - low) / 2\rfloor$.
     - Compare `target` with `contact[mid]`.
     - If equal, return $mid$.
     - If `target` is lexicographically smaller, set $high = mid - 1$.
     - If `target` is lexicographically larger, set $low = mid + 1$.
   - If $low > high$, report the contact as absent.

### Data Structure/Concept Used
- String Arrays / 2D Character Arrays
- Sequential Search
- Binary Search (Divide and Conquer)
- Lexicographical Comparison (`strcmp`)

### Test Cases
- **Test Case 1 (Element Present at Midpoint):** Target contact resides precisely at the initial midpoint index of a sorted array; Binary Search terminates in $1$ comparison.
- **Test Case 2 (Element Absent):** Querying a non-existent name correctly checks all $n$ items in Sequential Search and $\lfloor\log_2 n\rfloor + 1$ items in Binary Search.
- **Test Case 3 (Unsorted Binary Search Failure):** Executing Binary Search on an unsorted array demonstrates algorithmic failure, returning false negatives.

### Sample Input and Output
**Sample Input:**
```text
Directory: ["Aditi", "Karan", "Pooja", "Rohit", "Zoya"]
Target Contact: "Pooja"
```

**Sample Output:**
```text
[Sequential Search] Contact found at index 2. Comparisons: 3
[Binary Search]     Contact found at index 2. Comparisons: 1
```

### Time Complexity
- **Sequential Search:** Best Case: $O(1)$, Average and Worst Case: $O(n)$.
- **Binary Search:** Best Case: $O(1)$, Average and Worst Case: $O(\log n)$.

### Space Complexity
- Auxiliary Space: $O(1)$ for both iterative search implementations.

### Conclusion
Verified that Binary Search yields superior performance with $O(\log n)$ runtime efficiency over large datasets by discarding half of the remaining problem space at each step, while establishing that Linear Search remains the only dependable technique for unsorted collections.

---
