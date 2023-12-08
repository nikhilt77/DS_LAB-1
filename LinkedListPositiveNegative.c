#include<stdio.h>
#include<stdlib.h>

// Define a structure for a singly linked list node
struct node {
    int data;            // Data stored in the node
    struct node* next;   // Pointer to the next node in the list
};

// Function to create a new node at the end of the list
void create(struct node** head, int x) {
    // Allocate memory for a new node
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    // If the list is empty, set the head to the new node
    if (*head == NULL) {
        *head = newnode;
    } else {
        // Otherwise, traverse the list to the end and add the new node
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}

// Function to create a new node with positive data
void Positive(struct node** head, int x) {
    // Function works the same as 'create', but named differently for clarity
    create(head, x);
}

// Function to create a new node with negative data
void Negative(struct node** head, int x) {
    // Function works the same as 'create', but named differently for clarity
    create(head, x);
}

// Function to print the elements of the list
void printList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Initialize three linked lists: main list, positive list, and negative list
    struct node* head = NULL;
    struct node* positive = NULL;
    struct node* negative = NULL;

    int n, data;
    printf("Enter number of nodes:");
    scanf("%d", &n);
    printf("Enter data:");

    // Populate the main list with user input
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        create(&head, data);
    }

    // Traverse the main list and categorize nodes into positive and negative lists
    struct node* current = head;
    while (current != NULL) {
        if (current->data >= 0) {
            Positive(&positive, current->data);
        } else {
            Negative(&negative, current->data);
        }
        current = current->next;
    }

    // Print the positive and negative lists
    printf("Positive list\n");
    printList(positive);
    printf("Negative List\n");
    printList(negative);

    return 0;
}
