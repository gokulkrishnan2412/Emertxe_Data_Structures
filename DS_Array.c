#include<stdio.h>
#include<stdlib.h>

// Macros
#define MAXSIZE 10

// Global Variables
int arr[MAXSIZE];
int size = 0; // Initialize size to 0

// Function Declarations
void display();
void insertAtEnd(int val);
void insertAtPos(int val, int pos);
void deleteAtPos(int pos);

// Function Definitions

// Display the list elements
void display() {
    if (size == 0) {
        printf("\nList is empty\n");
        return;
    }
    printf("\nList elements are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insert at the end of the list
void insertAtEnd(int val) {
    if (size >= MAXSIZE) {
        printf("\nList is full, cannot insert at the end.\n");
        return;
    }
    arr[size++] = val;  // Insert the value and increment the size
    printf("\nValue %d inserted at the end.\n", val);
}

// Insert at a specific position in the list
void insertAtPos(int val, int pos) {
    if (pos < 0 || pos > size || size >= MAXSIZE) {
        printf("\nInvalid position or List is full, cannot insert.\n");
        return;
    }

    for (int i = size - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];  // Shift elements to the right
    }
    arr[pos] = val;  // Insert the value at the specific position
    size++;  // Increment size
    printf("\nValue %d inserted at position %d.\n", val, pos);
}

// Delete an element at a specific position
void deleteAtPos(int pos) {
    if (pos < 0 || pos >= size) {
        printf("\nInvalid position, cannot delete.\n");
        return;
    }
    int del = arr[pos];
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];  // Shift elements to the left
    }
    size--;  // Decrement size
    printf("\nDeleted %d from position %d.\n", del, pos);
}

// Main function
int main() {
    int choice;
    int val, pos;
    while (1) {
        printf("\n-----List Menu-----");
        printf("\n1.Insert at end");
        printf("\n2.Insert at specific position");
        printf("\n3.Delete at specific position");
        printf("\n4.Display the array values");
        printf("\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert at end
                printf("\nEnter the value to insert at the end: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 2:
                // Insert at specific position
                printf("\nEnter the value and position to insert: ");
                scanf("%d %d", &val, &pos);
                insertAtPos(val, pos);
                break;
            case 3:
                // Delete at specific position
                printf("\nEnter the position to delete: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;
            case 4:
                // Display the list
                display();
                break;
            case 5:
                // Exit the program
                printf("\nExiting...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice, try again.\n");
                break;
        }
    }
}
