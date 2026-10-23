
## Practical 6

### Practical Title
Train Ticket Booking System Using Queue.

### Problem Statement
Develop a train ticket reservation system in C that allocates confirmed seats to passengers up to a fixed quota, queues subsequent bookings into a FIFO waiting list, and automatically promotes waitlisted passengers upon cancellations.

### Objective
- Model real-world resource allocation systems using a Linear Queue ADT.
- Enforce First-In-First-Out (FIFO) transactional fairness.
- Coordinate state handoffs between confirmed passenger arrays and waiting list queues.

### Algorithm/Approach
1. Define a passenger structure `Passenger` containing `int ticket_id`, `char name[50]`, and `char status[15]`.
2. Define a fixed limit for confirmed seats ($CONF_MAX$) and a waiting list queue ($queue[WAIT_MAX]$) managed by $front$ and $rear$ pointers.
3. **Booking Function:**
   - If confirmed seats booked $< CONF_MAX$, assign status as "CONFIRMED".
   - If confirmed seats are full, verify if the waiting list has available capacity ($rear < WAIT_MAX - 1$).
   - If space permits, enqueue the passenger into the waiting list with status set to "WAITING".
   - If both confirmed seats and waiting list are full, reject the booking.
4. **Cancellation Function:**
   - Locate the target confirmed ticket ID and remove it.
   - If the waiting list is not empty ($front \ne -1$), dequeue the passenger at the head of the waiting list queue and update their status to "CONFIRMED".
   - Insert this passenger into the newly vacated seat record.

### Data Structure/Concept Used
- Queue ADT (Linear Queue)
- First-In-First-Out (FIFO) Architecture
- Structures and Arrays

### Test Cases
- **Test Case 1 (Direct Confirmation):** Booking requested when confirmed capacity is available; status allocated as "CONFIRMED".
- **Test Case 2 (Waitlist Promotion):** System with $3$ confirmed seats and $1$ waitlisted passenger processes a cancellation; verify the waitlisted passenger is promoted to confirmed status.
- **Test Case 3 (Full Waitlist Rejection):** Booking requested when both confirmed allocation and waiting queues are fully booked; system issues an explicit rejection.

### Sample Input and Output
**Sample Input:**
```text
Confirmed Quota = 2, Waitlist Quota = 2
1. Book(Ticket 1, "Amit")
2. Book(Ticket 2, "Priya")
3. Book(Ticket 3, "Rohan")
4. Cancel(Ticket 1)
```

**Sample Output:**
```text
Ticket 1 booked: Status = CONFIRMED
Ticket 2 booked: Status = CONFIRMED
Ticket 3 booked: Confirmed full! Enqueued to Waiting List (WL-1)
--- Processing Cancellation for Ticket 1 ---
Ticket 1 removed.
Dequeuing Rohan from Waiting List -> Promoted to CONFIRMED!
```

### Time Complexity
- **Enqueue (Waiting List):** $O(1)$
- **Dequeue (Waitlist Promotion):** $O(1)$
- **Linear Search for Cancellation:** $O(n)$

### Space Complexity
- Auxiliary Space: $O(1)$ auxiliary storage; $O(C + W)$ aggregate static storage for confirmed array $C$ and waiting queue $W$.

### Conclusion
Verified the practical utility of the FIFO queue model in preserving transactional fairness, ensuring sequential allocation in ticketing operations.

---
