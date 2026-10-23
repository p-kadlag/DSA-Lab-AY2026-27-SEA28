## Practical 9

### Practical Title
Graph Traversal for Campus Navigation Using BFS and DFS.

### Problem Statement
Model a college campus network as a graph structure using an adjacency matrix, and implement Breadth-First Search (BFS) and Depth-First Search (DFS) traversal algorithms to determine building connectivity and compute traversal paths.

### Objective
- Model topological real-world networks using Graph theory.
- Implement an Adjacency Matrix representation for graph topologies.
- Implement Breadth-First Search using an auxiliary Queue and Depth-First Search using Recursion/Stacks.

### Algorithm/Approach
1. Represent the campus consisting of $V$ buildings as vertices labeled from $0$ to $V - 1$.
2. Initialize an adjacency matrix `adj[V][V]` with $0$. Read direct bidirectional pathways between buildings to set `adj[u][v] = 1` and `adj[v][u] = 1`.
3. Maintain a boolean array `visited[V]` initialized to all `false`.
4. **Breadth-First Search (BFS):**
   - Initialize an empty queue.
   - Enqueue the starting vertex $s$ and mark it as visited (`visited[s] = true`).
   - While the queue is not empty:
     - Dequeue front vertex $u$ and print it.
     - Iterate through all adjacent vertices $v$ from $0$ to $V - 1$:
     - If `adj[u][v] == 1` and `visited[v] == false`, set `visited[v] = true` and enqueue $v$.
5. **Depth-First Search (DFS):**
   - Define a recursive function `DFS(u)`:
     - Mark $u$ as visited and print its label.
     - For every adjacent vertex $v$ from $0$ to $V - 1$:
       - If `adj[u][v] == 1` and `visited[v] == false`, recursively invoke `DFS(v)`.

### Data Structure/Concept Used
- Graph Abstract Data Type
- Adjacency Matrix representation
- Queue ADT (used in BFS)
- System Call Stack / Recursion (used in DFS)

### Test Cases
- **Test Case 1 (Standard Connected Graph):** Traversal successfully visits all buildings across the campus map without encountering infinite cycles.
- **Test Case 2 (Shortest Route in BFS):** Unweighted BFS traversal starting at Admin building guarantees discovery of target building via the fewest intermediate edges.
- **Test Case 3 (Disconnected Building Component):** Testing a graph containing an isolated node verifies that single-source traversal terminates, and an outer component loop is required to locate disconnected vertices.

### Sample Input and Output
**Sample Input:**
```text
Vertices: 4 (0: Admin, 1: Library, 2: Canteen, 3: Hostel)
Edges: (0-1), (0-2), (1-3), (2-3)
Start Node: 0 (Admin)
```

**Sample Output:**
```text
Adjacency Matrix:
  0 1 2 3
0 0 1 1 0
1 1 0 0 1
2 1 0 0 1
3 0 1 1 0

BFS Traversal Order: Admin -> Library -> Canteen -> Hostel
DFS Traversal Order: Admin -> Library -> Hostel -> Canteen
```

### Time Complexity
- **Time Complexity (Adjacency Matrix):** $O(V^2)$ for both BFS and DFS, as evaluating adjacent nodes requires scanning an entire row of length $V$.

### Space Complexity
- **Matrix Storage:** $O(V^2)$ to store the adjacency matrix.
- **Auxiliary Space:** $O(V)$ to maintain the `visited` array along with the auxiliary traversal queue or recursion stack.

### Conclusion
Demonstrated how graph models apply to physical campus navigation, establishing that Breadth-First Search reliably determines the shortest path across unweighted topologies, whereas Depth-First Search provides an effective recursive mechanism for exhaustive network exploration.
