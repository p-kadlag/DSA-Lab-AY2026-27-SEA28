## Practical 7

### Practical Title
Dynamic Text Editor Using Singly Linked List.

### Problem Statement
Design and implement a basic dynamic text editing line buffer in C utilizing a Singly Linked List, supporting arbitrary text insertion, character/line deletion, list reversal, and formatted traversal.

### Objective
- Apply dynamic memory allocation (`malloc`, `free`) to manage data on the heap.
- Master pointer management for node creation, linking, and traversal.
- Implement in-place node sequence reversal without allocating duplicate data buffers.

### Algorithm/Approach
1. Define a node structure:
   ```c
   struct Node {
       char data;
       struct Node* next;
   };
   ```
2. Initialize `head = NULL`.
3. **Insert at Position $k$:**
   - Dynamically allocate memory for a new node using `malloc()`.
   - If inserting at the head ($k = 1$), set `newNode->next = head` and update `head = newNode`.
   - Otherwise, traverse to position $k - 1$. If the end of the list is reached prematurely, abort (invalid index).
   - Link `newNode->next = curr->next` and update `curr->next = newNode`.
4. **Delete at Position $k$:**
   - If `head == NULL`, return underflow error.
   - If deleting head ($k = 1$), set temporary pointer `temp = head`, advance `head = head->next`, and release memory with `free(temp)`.
   - Otherwise, traverse to position $k - 1$, assign `temp = curr->next`, adjust `curr->next = temp->next`, and execute `free(temp)`.
5. **Reverse Operation:**
   - Initialize three sliding pointers: `prev = NULL`, `curr = head`, and `next = NULL`.
   - Traverse the list: store `next = curr->next`, redirect `curr->next = prev`, shift `prev = curr`, and advance `curr = next`.
   - Update `head = prev`.

### Data Structure/Concept Used
- Singly Linked List ADT
- Self-referential structures
- Dynamic memory management (`stdlib.h`: `malloc`, `free`)
- In-place pointer reversal

### Test Cases
- **Test Case 1 (Arbitrary Insertion):** Insert nodes sequentially to form text `"DSA"`, insert `'*'` at position $2$ to yield `"D*SA"`.
- **Test Case 2 (Invalid Deletion Index):** Attempt to delete a node at position $10$ in a $3$-node list; system catches the out-of-bounds error and maintains list integrity.
- **Test Case 3 (List Reversal):** Reverse list containing `"ABC"`; verify head points to `'C'` and terminal node `'A'` links to `NULL`.

### Sample Input and Output
**Sample Input:**
```text
1. Insert 'E' at pos 1
2. Insert 'D' at pos 1
3. Insert 'T' at pos 3
4. Display
5. Reverse
6. Display
```

**Sample Output:**
```text
Current Text: D -> E -> T -> NULL
Reversing Text Buffer...
Reversed Text: T -> E -> D -> NULL
```

### Time Complexity
- **Insertion/Deletion at Head:** $O(1)$
- **Insertion/Deletion at Position $k$:** $O(n)$ where $n$ is the traversal distance.
- **List Reversal:** $O(n)$ passing through the list once.
- **Display:** $O(n)$

### Space Complexity
- Auxiliary Space: $O(1)$ auxiliary memory overhead; heap scales dynamically at $O(n)$ based on the total number of allocated nodes.

### Conclusion
Demonstrated that dynamic linked lists eliminate the fixed-capacity constraints of static arrays and allow localized insertions and deletions without shifting adjacent elements.

---
