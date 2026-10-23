

## Practical 5

### Practical Title
Circular Queue Implementation Using Array for Parcel Handling System.

### Problem Statement
Design and implement a parcel dispatch handling system using a static array-based Circular Queue to overcome the false overflow limitation inherent to standard linear queues.

### Objective
- Implement circular queue operations: `enqueue()`, `dequeue()`, and `display()`.
- Apply modulo arithmetic to handle pointer wrap-around.
- Contrast space utilization between linear and circular queue models.

### Algorithm/Approach
1. Define an array `queue[MAX]` with pointers $front = -1$ and $rear = -1$.
2. **Enqueue Operation:**
   - Check for Queue Full condition: `(rear + 1) % MAX == front`. If true, output "Queue Overflow".
   - If $front == -1$ (queue is empty), initialize $front = rear = 0$.
   - Otherwise, advance the rear pointer circularly: $rear = (rear + 1) \pmod{MAX}$.
   - Store the incoming parcel ID at `queue[rear]`.
3. **Dequeue Operation:**
   - Check for Queue Empty condition: $front == -1$. If true, output "Queue Underflow".
   - Retrieve the parcel ID at `queue[front]`.
   - If $front == rear$ (last element being removed), reset pointers: $front = rear = -1$.
   - Otherwise, advance the front pointer circularly: $front = (front + 1) \pmod{MAX}$.
4. **Display:** Traverse from $front$ to $rear$ using pointer advancement $i = (i + 1) \pmod{MAX}$.

### Data Structure/Concept Used
- Circular Queue ADT
- Array implementation
- Modulo Arithmetic (`%` operator)
- FIFO (First-In-First-Out) scheduling

### Test Cases
- **Test Case 1 (Normal Operations):** Enqueue three parcels, dequeue one, and verify FIFO ordering.
- **Test Case 2 (Wrap-Around Utilization):** Fill the queue completely, dequeue two parcels, and enqueue two new parcels to confirm that space at index $0$ and $1$ is reused.
- **Test Case 3 (Full Condition Detection):** Attempt to enqueue when `(rear + 1) % MAX == front`; verify that the system rejects the operation without overwriting existing data.

### Sample Input and Output
**Sample Input:**
```text
Queue Capacity = 3
1. Enqueue(Parcel_101)
2. Enqueue(Parcel_102)
3. Enqueue(Parcel_103)
4. Dequeue()
5. Enqueue(Parcel_104)
```

**Sample Output:**
```text
Parcel_101 inserted at index 0.
Parcel_102 inserted at index 1.
Parcel_103 inserted at index 2 (Queue Full).
Dispatching Parcel_101 from index 0.
Parcel_104 inserted at index 0 (Wrap-around successful).
Current Parcels in Queue: Parcel_102, Parcel_103, Parcel_104
```

### Time Complexity
- **Enqueue:** $O(1)$
- **Dequeue:** $O(1)$
- **Display:** $O(n)$ where $n$ represents the number of stored parcels.

### Space Complexity
- Auxiliary Space: $O(1)$ beyond the pre-allocated static array of capacity $MAX$.

### Conclusion
Demonstrated that circular queues resolve the false overflow problem of linear queues through modulo wrap-around logic, maximizing memory utilization without requiring costly element-shifting routines.

---
