#include <stdio.h>
#include <string.h>
typedef struct cont {
    char name[20];
    char ph[10];
} con;
int main() {
    con c1[20], temp;
    int n;
    printf("\tENTER NUMBER OF CONTACTS TO STORE: ");
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; i++) {
        printf("\n\tEnter contact: %d\n", i + 1);
        printf("Enter the name of contact: ");
        scanf("%s", c1[i].name);
        printf("Enter contact number: ");
        scanf("%s", c1[i].ph);
        }
    int j;
    for(j = 0; j < n; j++) {
        if(j == 0)
            printf("\n\tDISPLAYING CONTACTS\n");
        printf("CONTACT NAME: %s\n", c1[j].name);
        printf("CONTACT NUMBER: %s\n\n", c1[j].ph);
    }
    printf("\n\t--- SEQUENTIAL SEARCH ---");
    printf("\n\tENTER NAME TO SEARCH (UNSORTED): ");
    char seq_key[20]; // Increased size to match name array size
    scanf("%s", seq_key);

    int seq_cmp = 0;
    int seq_found = 0;

    for(i = 0; i < n; i++) {
        seq_cmp++;
        if(strcmp(c1[i].name, seq_key) == 0) {
            printf("\n\tContact found using Sequential Search!\n");
            printf("CONTACT NAME: %s\n", c1[i].name);
            printf("CONTACT NUMBER: %s\n", c1[i].ph);
            seq_found = 1;
            break;
        }
    }
    printf("\n\tNO. OF COMPARISONS (SEQUENTIAL) = %d\n", seq_cmp);
    if(seq_found != 1) {
        printf("\tContact not found using Sequential Search!\n");
    }
    printf("\t---------------------------------------\n");
    int k, l;
    for(k = 1; k < n; k++) {
        for(l = 0; l < n - k; l++) {
            if(strcmp(c1[l].name, c1[l+1].name) > 0) {
                temp = c1[l];
                c1[l] = c1[l+1];
                c1[l+1] = temp;
            }
        }
    }
    for(j = 0; j < n; j++) {
        if(j == 0)
            printf("\n\tDISPLAYING SORTED CONTACTS\n");
        printf("CONTACT NAME: %s\n", c1[j].name);
        printf("CONTACT NUMBER: %s\n\n", c1[j].ph);
    }
    printf("\n\t--- BINARY SEARCH ---");
    printf("\n\tENTER NAME TO SEARCH (SORTED): ");
    char key[20];
    scanf("%s", key);
    int cmp = 0;
    int low = 0, high = n - 1, mid, tem = 0;
    while(low <= high) {
        mid = (high + low) / 2;
        cmp++;
        if(strcmp(c1[mid].name, key) == 0) {
            printf("\n\tContact found using Binary Search!\n");
            tem = 1;
            break;
        }
        else if(strcmp(c1[mid].name, key) > 0) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    printf("\n\tNO. OF COMPARISONS (BINARY) = %d\n", cmp);
    if(tem != 1) {
        printf("\n\tContact not found using Binary Search!\n");
    }
    return 0;
}
