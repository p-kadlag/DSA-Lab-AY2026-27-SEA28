#include <stdio.h>
#include <string.h>

#define MAX 5
#define WMAX 100

typedef struct {
    int id;
    char name[100]; 
} ticket;

ticket conf[MAX];
ticket waitq[WMAX];

int n_conf = 0;
int head = 0;
int tail = -1;
int n_wait = 0;
int auto_id = 1;

void do_book() {
    ticket p;
    if (n_conf >= MAX && n_wait >= WMAX) {
        printf("\nSystem is full\n");
        return;
    }
    
    p.id = auto_id++;
    printf("Enter passenger name: ");
    scanf("%99s", p.name); 
    
    if (n_conf < MAX) {
        conf[n_conf++] = p;
        printf("\n\tTicket Confirmed Successfully\n");
    } else {
        tail = (tail + 1) % WMAX;
        waitq[tail] = p;
        n_wait++;
        printf("\nPassenger added to Waiting List\n");
        printf("Waiting Position: %d\n", n_wait);
    }
    printf("Booking Number: %d\n", p.id);
    printf("Passenger Name: %s\n", p.name);
}

void do_cancel() {
    int target, idx;
    int found = 0;
    ticket tmp;
    
    printf("Enter booking number to cancel: ");
    scanf("%d", &target);
    for (idx = 0; idx < n_conf; idx++) {
        if (conf[idx].id == target) {
            tmp = conf[idx];
            found = 1;
            for (int j = idx; j < n_conf - 1; j++) {
                conf[j] = conf[j + 1];
            }
            n_conf--;
            printf("\n\tTicket cancelled for %s\n", tmp.name);
            if (n_wait > 0) {
                tmp = waitq[head];
                head = (head + 1) % WMAX;
                n_wait--;
                conf[n_conf++] = tmp;
                printf("Waiting passenger promoted to Confirmed\n");
                printf("Booking Number: %d, Name: %s\n", tmp.id, tmp.name);
            }
            return;
        }
    }
    if (!found) {
        for (idx = 0; idx < n_wait; idx++) {
            int cur = (head + idx) % WMAX;
            if (waitq[cur].id == target) {
                printf("\n\tWaiting list ticket cancelled for %s\n", waitq[cur].name);
                found = 1;
                for (int j = idx; j < n_wait - 1; j++) {
                    int c = (head + j) % WMAX;
                    int n = (head + j + 1) % WMAX;
                    waitq[c] = waitq[n];
                }
                tail = (tail - 1 + WMAX) % WMAX;
                n_wait--;
                return;
            }
        }
    }
    
    if (!found) {
        printf("\n\tBooking number not found anywhere in the system\n");
    }
}

void show_all() {
    int idx, pos;
    printf("\nCONFIRMED BOOKINGS\n");
    if (n_conf == 0) {
        printf("No confirmed bookings\n");
    } else {
        for (idx = 0; idx < n_conf; idx++) {
            printf("Booking No: %d | Name: %s\n", conf[idx].id, conf[idx].name);
        }
    }
    
    printf("\nWAITING LIST\n");
    if (n_wait == 0) {
        printf("Waiting list is empty\n");
    } else {
        for (idx = 0; idx < n_wait; idx++) {
            pos = (head + idx) % WMAX;
            printf("Booking No: %d | Name: %s\n", waitq[pos].id, waitq[pos].name);
        }
    }
    
    printf("\nAvailable Seats: %d\n", MAX - n_conf);
    printf("Waiting Passengers: %d\n", n_wait);
}

int main() {
    int opt;
    while (1) {
        printf("\n--- TRAIN TICKET BOOKING SYSTEM ---\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Display Bookings\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &opt) != 1) {
            printf("Invalid input. Exiting\n");
            return 0;
        }
        
        if (opt == 4) {
            printf("Thank you!\n");
            break;
        }
        
        switch (opt) {
            case 1: do_book(); break;
            case 2: do_cancel(); break;
            case 3: show_all(); break;
            default: 
                printf("Invalid choice\n");
                return 0;
        }
    }
    return 0;
}
