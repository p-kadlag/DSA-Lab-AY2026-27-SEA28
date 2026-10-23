// Parth Harish Kadlag 
// SEA28 
// Binary Search Tree Operations for Online Directory System 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Simple structure for our phonebook node 
typedef struct Node { 
    char name[50];
    char phone[20];
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createnode(char name[50], char phone[20]) { 
    Node* newnode = (Node*) malloc(sizeof(Node));
    strcpy(newnode->name, name);
    strcpy(newnode->phone, phone);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
} 

// Function to insert a contact into the BST
Node* insertNode(Node* root, char name[50], char phone[20]) { 
    if (root == NULL) { 
        return createnode(name, phone);
    } 
    
    int check = strcmp(name, root->name);
    if (check < 0) { 
        root->left = insertNode(root->left, name, phone);
    } 
    else if (check > 0) { 
        root->right = insertNode(root->right, name, phone);
    } 
    else { 
        printf("\nContact already exists! Updating phone number.\n");
        strcpy(root->phone, phone);
    } 
    return root;
} 

// Function to search for a contact in the BST
Node* searchNode(Node* root, char target[50]) { 
    if (root == NULL || strcmp(root->name, target) == 0) { 
        return root;
    } 
    if (strcmp(target, root->name) < 0) { 
        return searchNode(root->left, target);
    } 
    else { 
        return searchNode(root->right, target);
    } 
} 

// Inorder Traversal (Left, Root, Right)
void inorder(Node* root) { 
    if (root != NULL) { 
        inorder(root->left);
        printf("Name: %s, Phone: %s\n", root->name, root->phone);
        inorder(root->right);
    } 
} 

// Preorder Traversal (Root, Left, Right)
void preorder(Node* root) { 
    if (root != NULL) { 
        printf("Name: %s, Phone: %s\n", root->name, root->phone);
        preorder(root->left);
        preorder(root->right);
    } 
} 

// Postorder Traversal (Left, Right, Root)
void postorder(Node* root) { 
    if (root != NULL) { 
        postorder(root->left);
        postorder(root->right);
        printf("Name: %s, Phone: %s\n", root->name, root->phone);
    } 
} 

int main() { 
    Node* root = NULL;
    int op;
    char name[50], phone[20];
    
    while (1) { 
        printf("\n*** PHONEBOOK BST MENU ***\n");
        printf("1. Insert Contact\n");
        printf("2. Search Contact\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your op: ");
        scanf("%d", &op);
        
        switch(op) { 
            case 1: 
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                printf("Enter Phone: ");
                scanf(" %[^\n]", phone);
                root = insertNode(root, name, phone);
                printf("Contact added successfully! \n");
                break;
                
            case 2: 
                printf("Enter Name to search: ");
                scanf(" %[^\n]", name);
                Node* result = searchNode(root, name);
                if (result != NULL) { 
                    printf("\nFound! Phone number is: %s\n", result->phone);
                } 
                else { 
                    printf("\nContact not found.\n");
                } 
                break;
                
            case 3: 
                printf("\n--- INORDER TRAVERSAL ---\n");
                inorder(root);
                break;
                
            case 4: 
                printf("\n--- PREORDER TRAVERSAL ---\n");
                preorder(root);
                break;
                
            case 5: 
                printf("\n--- POSTORDER TRAVERSAL ---\n");
                postorder(root);
                break;
                
            case 6: 
                printf("Exiting program......\n");
                return 0;
                
            default: 
                printf("Invalid choice! Try again.\n");
        } 
    } 
    return 0;
}
