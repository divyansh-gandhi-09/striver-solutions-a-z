#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node in the linked list
struct node {
    char name[50];
    int rollNumber;
    struct node* next;
};

// Function to create a new node
struct node* create_node(char* name, int rollNumber) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->name, name);
    newNode->rollNumber = rollNumber;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specified position
void insertion_ele(struct node** head, char* name, int rollno, int pos) {
    struct node* newnode = create_node(name, rollno);
    
    // If inserting at the beginning (position 1)
    if (pos == 1) {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    struct node* temp = *head;
    
    // Traverse the list to find the position before the insertion point
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Check if the position is out of bounds
    if (temp == NULL) {
        printf("Position is out of bounds.\n");
        free(newnode);
        return;
    }

    // Insert the new node at the correct position
    newnode->next = temp->next;
    temp->next = newnode;
}

// Function to delete a node at a specified position
void delete_node(struct node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *head;

    // If the head needs to be removed
    if (pos == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Traverse to the node before the one to be deleted
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    // Check if the position is valid
    if (temp == NULL || temp->next == NULL) {
        printf("Position is out of bounds.\n");
        return;
    }

    // Delete the node at the specified position
    struct node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Function to display the linked list
void display_list(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("Name: %s, Roll Number: %d\n", temp->name, temp->rollNumber);
        temp = temp->next;
    }
    
}

// Function to create a linked list from user input
void create_list(struct node** head) {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char name[50];
        int rollNumber;
        printf("Enter name and rollno of student %d: ", i + 1);
        scanf("%s%d", name,&rollNumber);
        
        insertion_ele(head, name, rollNumber, i + 1);  // Insert at the end
    }
}
void reverseList(struct node** head) {
    struct node* prev = NULL;
    struct node* current = *head;
    struct node* next = NULL;
    
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev to current
        current = next;       // Move to next node
    }
    
    *head = prev; // Update the head to new first element
}

int main() {
    struct node* head = NULL;
    int choice, position, rollNumber;
    char name[50];
    printf("\nMenu:\n");
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Insert Node\n");
        printf("4. Delete Node\n");
        printf("5. reverse linked list\n");
        printf("6. Exit\n");
    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_list(&head);
                break;
            case 2:
                printf("Linked list:\n");
                display_list(head);
                break;
            case 3:
                printf("Enter the name and rollno. for the new student: ");
                scanf("%s%d", name,&rollNumber);
                
                printf("Enter the position where you want to insert the new student: ");
                scanf("%d", &position);
                insertion_ele(&head, name, rollNumber, position);
                break;
            case 4:
                printf("Enter the position of the node to delete: ");
                scanf("%d", &position);
                delete_node(&head, position);
                break;
            case 5:
                reverseList(&head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}