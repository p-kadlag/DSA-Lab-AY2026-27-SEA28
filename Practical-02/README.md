
## Practical 2

### Practical Title
Student Result Database Management Using Array of Structures.

### Problem Statement
Implement a menu-driven student academic database in C using an array of structures capable of performing record creation, insertion, linear search by name, modification by roll number, sorting by marks, and formatted display.

### Objective
- Implement user-defined composite data types using the `struct` keyword in C.
- Manage tabular, multi-attribute entity records via an array of structures.
- Implement fundamental searching and sorting algorithms on heterogeneous datasets.

### Algorithm/Approach
1. Define a user-defined structure `Student` containing members: `int roll_no`, `char name[50]`, and `float marks`.
2. Declare an array of type `struct Student` with a predefined capacity ($MAX$).
3. Present an interactive menu loop with options: Insert, Display, Search, Modify, Sort, and Exit.
4. **Insert:** Check if current count $< MAX$. If valid, read roll number, name, and marks; increment total count.
5. **Search (By Name):** Accept a target query string. Traverse the array sequentially and evaluate equality using `strcmp()`. Return the matching record index or an error flag.
6. **Modify:** Search for the record by unique `roll_no`. Upon discovery, read new field values and update the structure members in place.
7. **Sort (By Marks):** Apply Bubble Sort or Insertion Sort to compare the `marks` attribute between adjacent elements, swapping the entire structure record when elements are out of order.

### Data Structure/Concept Used
- Structures (`struct`)
- Array of Structures
- Linear Search
- Bubble Sort / Insertion Sort
- String manipulation functions (`string.h`)

### Test Cases
- **Test Case 1 (Normal Execution):** Insert 3 student records, sort by marks, and display in descending order.
- **Test Case 2 (Search Non-Existent Key):** Search for a name not present in the database; system gracefully reports "Record not found".
- **Test Case 3 (Boundary Capacity):** Attempting to insert a record when the array is fully populated ($count == MAX$) triggers an "Array Overflow" alert.

### Sample Input and Output
**Sample Input:**
```text
Select Option: 1 (Insert)
Enter Roll No: 101
Enter Name: Rahul
Enter Marks: 88.5
```

**Sample Output:**
```text
--- Student Database ---
Roll No    Name       Marks
---------------------------
101        Rahul      88.50
102        Sneha      92.00
---------------------------
Sorted successfully by marks!
```

### Time Complexity
- **Insertion (at end):** $O(1)$
- **Search (by name):** $O(n)$
- **Modification:** $O(n)$
- **Sorting (Bubble Sort):** $O(n^2)$
- **Display:** $O(n)$

### Space Complexity
- Auxiliary Space: $O(1)$ beyond the pre-allocated static storage of $O(n)$ reserved for the structure array.

### Conclusion
Successfully demonstrated that an array of structures enables the structured aggregation of diverse data types into unified records, while highlighting static array limitations such as fixed capacity bounds and contiguous shifting costs.

---
