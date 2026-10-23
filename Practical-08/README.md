
## Practical 8

### Practical Title
Binary Search Tree Operations for Online Directory System.

### Problem Statement
Develop an online telephone directory management system using a Binary Search Tree (BST) that supports dynamic contact insertion, logarithmic search by contact name, and alphabetical listing via inorder traversal.

### Objective
- Implement hierarchical tree data structures using pointers.
- Maintain the Binary Search Tree ordering invariant ($Left < Root < Right$).
- Implement recursive traversals (Inorder, Preorder, Postorder) and understand search mechanics.

### Algorithm/Approach
1. Define a BST node structure:
   ```c
   struct BSTNode {
       char name[50];
       char phone[15];
       struct BSTNode* left;
       struct BSTNode* right;
   };
   ```
2. Initialize `root = NULL`.
3. **Insertion (Recursive):**
   - If the current root is `NULL`, dynamically allocate a node, populate the fields, set child pointers to `NULL`, and return it.
   - Use `strcmp(new_name, root->name)`:
     - If result $< 0$, recursively route to `root->left`.
     - If result $> 0$, recursively route to `root->right`.
     - If result $== 0$, reject or update duplicate record.
4. **Search Operation:**
   - If current pointer is `NULL`, report "Contact Not Found".
   - If `strcmp(target, root->name) == 0`, return record details.
   - If target is smaller, search recursively in the left subtree; otherwise, search in the right subtree.
5. **Inorder Traversal (Alphabetical Retrieval):**
   - Traverse the left subtree: `inorder(root->left)`.
   - Visit and display the current node record: `printf("%s", root->name)`.
   - Traverse the right subtree: `inorder(root->right)`.

### Data Structure/Concept Used
- Binary Search Tree (BST)
- Recursion
- Tree Traversal (Inorder, Preorder, Postorder)
- Lexicographical string comparisons

### Test Cases
- **Test Case 1 (Balanced Insertion & Sorted Output):** Insert names `"Rohan"`, `"Amit"`, `"Vikram"`. Inorder traversal outputs `"Amit"`, `"Rohan"`, `"Vikram"`.
- **Test Case 2 (Search Target Present):** Search for `"Amit"` returns associated phone number with logarithmic traversal steps.
- **Test Case 3 (Skewed Tree Degeneration):** Inserting alphabetically pre-sorted inputs (`"A"`, `"B"`, `"C"`, `"D"`) creates a right-skewed degenerate tree, showing that search behavior degrades toward $O(n)$.

### Sample Input and Output
**Sample Input:**
```text
Insert Contacts:
1. ("Rohan", "9822011111")
2. ("Amit", "9422022222")
3. ("Varun", "9722033333")
Action: Inorder Traversal
Action: Search Contact "Amit"
```

**Sample Output:**
```text
--- Alphabetical Directory Listing (Inorder) ---
Name: Amit      Phone: 9422022222
Name: Rohan     Phone: 9822011111
Name: Varun     Phone: 9722033333

Search Query: "Amit"
Result: Contact Found! Phone: 9422022222
```

### Time Complexity
- **Search and Insertion:**
  - Average Case (Balanced BST): $O(\log n)$
  - Worst Case (Degenerate/Skewed Tree): $O(n)$
- **Inorder Traversal:** $O(n)$ to visit every node once.

### Space Complexity
- Auxiliary Space: $O(h)$ where $h$ is the height of the tree, representing the recursion stack overhead ($O(\log n)$ average, $O(n)$ worst-case).

### Conclusion
Confirmed that a Binary Search Tree provides efficient, logarithmic-time dynamic lookups on average while demonstrating that an inorder traversal naturally retrieves stored contact records in sorted alphabetical order.

---
