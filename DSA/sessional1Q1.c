#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int row, col, value;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to update traffic density
void updateTraffic(Node** head, int row, int col, int value) {
    Node* temp = *head;
    Node* prev = NULL;

    // Search for the node
    while (temp != NULL && (temp->row != row || temp->col != col)) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        // Update the value if node is found
        if (value != 0) {
            temp->value = value;
        } else {
            // Remove the node if value is zero
            if (prev != NULL) {
                prev->next = temp->next;
            } else {
                *head = temp->next;
            }
            free(temp);
        }
    } else if (value != 0) {
        // Add new node if not found and value is non-zero
        Node* newNode = createNode(row, col, value);
        newNode->next = *head;
        *head = newNode;
    }
}
// Function to calculate total traffic for a specific row
int totalTrafficRow(Node* head, int row) {
    Node* temp = head;
    int total = 0;

    while (temp != NULL) {
        if (temp->row == row) {
            total += temp->value;
        }
        temp = temp->next;
    }

    return total;
}

// Function to calculate total traffic for a specific column
int totalTrafficColumn(Node* head, int col) {
    Node* temp = head;
    int total = 0;

    while (temp != NULL) {
        if (temp->col == col) {
            total += temp->value;
        }
        temp = temp->next;
    }

    return total;
}

// Main function for testing
int main() {
    Node* head = NULL;

    // Example updates
    updateTraffic(&head, 1, 2, 5);
    updateTraffic(&head, 1, 3, 10);
    updateTraffic(&head, 2, 2, 15);
    updateTraffic(&head, 1, 2, 0); // Setting traffic to zero

    // Calculate total traffic
    printf("Total traffic in row 1: %d\n", totalTrafficRow(head, 1));
    printf("Total traffic in column 2: %d\n", totalTrafficColumn(head, 2));

    return 0;
}
