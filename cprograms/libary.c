//Proogram for Library Management System using hash table
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

// Book structure to hold information about each book
typedef struct Book {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int isAvailable;  // 1 if available otherwise 0
    struct Book* next; // Pointer to handle collisions (chaining) if two book IDs are hashed to the same index
} Book;

// Hash table array of pointers to Book nodes
Book* hashTable[TABLE_SIZE];

// Hash function to map book ID to hash table index
int hashFunction(int id) {
    return id % TABLE_SIZE;
}

// Function to create a new book node
Book* createBook(int id, const char* title, const char* author, int isAvailable) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    newBook->id = id;
    strncpy(newBook->title, title, MAX_TITLE_LENGTH);
    strncpy(newBook->author, author, MAX_AUTHOR_LENGTH);
    newBook->isAvailable = isAvailable;
    newBook->next = NULL;
    return newBook;
}

// Function to add a book to the hash table
void addBook(int id, const char* title, const char* author, int isAvailable) {
    int index = hashFunction(id);
    Book* newBook = createBook(id, title, author, isAvailable);

    // Insert book at the beginning of the chain at hash table index
    newBook->next = hashTable[index];
    hashTable[index] = newBook;
    printf("Book added successfully!\n");
}

// Function to search for a book by ID
void searchBook(int id) {
    int index = hashFunction(id);
    Book* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nBook found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nAvailable: %s\n",
                   temp->id, temp->title, temp->author, temp->isAvailable ? "Yes" : "No");
            return;
        }
        temp = temp->next;
    }
    printf("Book not found.\n");
}

// Function to delete a book by ID
void deleteBook(int id) {
    int index = hashFunction(id);
    Book* temp = hashTable[index];
    Book* prev = NULL;

    while (temp != NULL) {
        if (temp->id == id) {
            if (prev == NULL) {
                hashTable[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Book deleted successfully!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Book not found.\n");
}

// Function to display all books in the hash table
void displayBooks() {
    printf("\nLibrary Book List:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Book* temp = hashTable[i];
        if (temp != NULL) {
            printf("Index %d:\n", i);
            while (temp != NULL) {
                printf("ID: %d, Title: %s, Author: %s, Available: %s\n",
                       temp->id, temp->title, temp->author, temp->isAvailable ? "Yes" : "No");
                temp = temp->next;
            }
            printf("\n");
        }
    }
}
int main() {
    int choice, id, isAvailable;
    char title[MAX_TITLE_LENGTH], author[MAX_AUTHOR_LENGTH];

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Delete Book\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                printf("Enter Book Title: ");
                getchar(); // to clear newline
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline character
                printf("Enter Author Name: ");
                fgets(author, MAX_AUTHOR_LENGTH, stdin);
                author[strcspn(author, "\n")] = '\0';
                printf("Is the book available? (1 for Yes, 0 for No): ");
                scanf("%d", &isAvailable);
                addBook(id, title, author, isAvailable);
                break;
            case 2:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                searchBook(id);
                break;
            case 3:
                printf("Enter Book ID to delete: ");
                scanf("%d", &id);
                deleteBook(id);
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}