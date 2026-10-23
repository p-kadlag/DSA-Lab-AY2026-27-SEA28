#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple Node Structure
struct Node {
    char word[50];
    struct Node* next;
};

// Helper function to create a new node
struct Node* createNode(char* w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, w);
    newNode->next = NULL;
    return newNode;
}

// 1. Insert Word at Front
struct Node* insertFront(struct Node* head, char* w) {
    struct Node* newNode = createNode(w);
    newNode->next = head;
    return newNode;
}

// 2. Insert Word at End
struct Node* insertEnd(struct Node* head, char* w) {
    struct Node* newNode = createNode(w);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// 3. Delete Word from Front
struct Node* deleteFront(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// 4. Delete Word from End
struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// 5. Display Text in Normal Order
void displayNormal(struct Node* head) {
    if (head == NULL) {
        printf("[Empty]");
    }
    while (head != NULL) {
        printf("%s ", head->word);
        head = head->next;
    }
    printf("\n");
}

// 6. Display Text in Reverse Order (Using Recursion)
void displayReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }
    displayReverse(head->next);
    printf("%s ", head->word);
}

// 7. Reverse Entire List Permanently (Pointer Manipulation)
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *nxt = NULL;
    while (curr != NULL) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

int main() {
    struct Node* head = NULL;
    int choice;
    char w[50];

    while (1) {
        printf("\n1.AddFront \n2.AddEnd \n3.DelFront \n4.DelEnd \n5.DispNormal \n6.DispReverse \n7.PermanentRev \n8.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == 8) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter word: ");
                scanf("%s", w);
                head = insertFront(head, w);
                break;

            case 2:
                printf("Enter word: ");
                scanf("%s", w);
                head = insertEnd(head, w);
                break;

            case 3:
                head = deleteFront(head);
                printf("Deleted from front.\n");
                break;

            case 4:
                head = deleteEnd(head);
                printf("Deleted from end.\n");
                break;

            case 5:
                printf("\n--- Normal Text View ---\n");
                displayNormal(head);
                break;

            case 6:
                printf("\n--- Reverse Text View ---\n");
                if (head == NULL) {
                    printf("[Empty]");
                }
                displayReverse(head);
                printf("\n");
                break;

            case 7:
                head = reverseList(head);
                printf("Pointers completely reversed.\n");
                break;

            default:
                printf("Invalid option.\n");
        }
    }
    
    return 0;
}
