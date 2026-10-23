#include <stdio.h>

#define MAX 20

int main() {
    int op, fr = -1, r = -1;
    int q[MAX];

    do {
        printf("\n--- Parcel Queue Menu ---\n");
        printf("1. Enter parcel ID\n");
        printf("2. Display Queue\n");
        printf("3. Delete parcel\n");
        printf("4. Exit\n");
        printf("Enter your Option: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                // Check if queue is full
                if (fr == (r + 1) % MAX) {
                    printf("Queue is full!\n");
                } else {
                    // If queue is empty, initialize front pointer
                    if (fr == -1) {
                        fr = 0;
                    }
                    r = (r + 1) % MAX;
                    printf("Enter parcel ID: ");
                    scanf("%d", &q[r]);
                }
                break;

            case 2:
                // Check if queue is empty
                if (fr == -1) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue elements: ");
                    int i = fr;
                    while (1) {
                        printf("%d ", q[i]);
                        if (i == r) {
                            break;
                        }
                        i = (i + 1) % MAX;
                    }
                    printf("\n");
                }
                break;

            case 3:
                // Check if queue is empty
                if (fr == -1) {
                    printf("Queue is empty.\n");
                } else {
                    printf("%d is deleted!\n", q[fr]);
                    // Reset queue if it becomes empty after deletion
                    if (fr == r) {
                        fr = r = -1;
                    } else {
                        fr = (fr + 1) % MAX;
                    }
                }
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid option! Please try again.\n");
        }
    } while(op != 4);

    return 0;
}
