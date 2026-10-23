#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int adj[MAX][MAX];
int visited[MAX];
int n;
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int vertex) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    rear++;
    queue[rear] = vertex;
}
int dequeue() {
    if (front == -1 || front > rear) return -1;
    int vertex = queue[front];
    front++;
    return vertex;
}
int isQueueEmpty() {
    return (front == -1 || front > rear);
}
void resetVisited() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}
void BFS(int startNode) {
    resetVisited();
    front = rear = -1;
    printf("\n[BFS Traversal] Path order: ");
    visited[startNode] = 1;
    enqueue(startNode);
    while (!isQueueEmpty()) {
        int currentNode = dequeue();
        printf("%d ", currentNode);
        for (int i = 0; i < n; i++) {
            if (adj[currentNode][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}
void DFS_Recursive(int node) {
    printf("%d ", node);
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            DFS_Recursive(i);
        }
    }
}
void DFS(int startNode) {
    resetVisited();
    printf("\n[DFS Traversal] Path order: ");
    DFS_Recursive(startNode);
    printf("\n");
}
int main() {
    int startBuilding, choice, paths;
    printf("=== Campus Navigation System ===\n");
    printf("Enter number of buildings: ");
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    printf("Enter total number of paths (edges): ");
    if (scanf("%d", &paths) != 1) return 0;
    printf("\nEnter connected pairs line-by-line (e.g., '0 1'):\n");
    for (int k = 0; k < paths; k++) {
        int u, v;
        printf("Path %d of %d: ", k + 1, paths);
        if (scanf("%d %d", &u, &v) == 2) {
            if (u >= 0 && u < n && v >= 0 && v < n) {
                adj[u][v] = 1;
                adj[v][u] = 1;
            } else {
                printf("Invalid building numbers! Try this line again.\n");
                k--;
            }
        }
    }
    printf("\n--- Generated Campus Matrix ---\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    while (1) {
        printf("\n==============================");
        printf("\nSelect Traversal Method:");
        printf("\n1. Breadth-First Search (BFS)");
        printf("\n2. Depth-First Search (DFS)");
        printf("\n3. Exit");
        printf("\nYour choice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 3) {
            printf("Exiting system.\n");
            break;
        }
        if (choice == 1 || choice == 2) {
            printf("Enter starting building (0 to %d): ", n - 1);
            if (scanf("%d", &startBuilding) != 1) continue;

            if (startBuilding < 0 || startBuilding >= n) {
                printf("Error: Building out of range.\n");
                continue;
            }
            if (choice == 1) BFS(startBuilding);
            else DFS(startBuilding);
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
