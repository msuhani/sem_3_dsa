#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node at the end of the list
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next=*head;
    } else {
        struct Node* last = *head;
        while (last->next != NULL) {
            newNode->next=last->next;
        }
        last->next = newNode;
    }
}

// Function to insert at the beginning of the list
void insertBeg(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to insert after a specific value
void insertAfterSpecific(struct Node** head, int data, int value) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp1 = *head;
        while (temp1 != NULL && temp1->data != value)
            temp1 = temp1->next;
        if (temp1 == NULL)
            printf("Node not present.\n");
        else {
            newNode->next = temp1->next;
            temp1->next = newNode;
        }
    }
}

// Function to delete the first node
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Unable to delete.\n");
    } else {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Function to delete the last node
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Unable to delete.\n");
    } else if ((*head)->next == NULL) {
        // Only one node in the list
        free(*head);
        *head = NULL;
    } else {
        struct Node* secondLast = *head;
        while (secondLast->next->next != NULL) {
            secondLast = secondLast->next;
        }
        free(secondLast->next);
        secondLast->next = NULL;
    }
}

// Function to delete a node with a specific value
void deleteValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty. Unable to delete.\n");
    } else {
        struct Node* temp = *head;
        struct Node* prev = NULL;
        if (temp != NULL && temp->data == value) {
            // Node to be deleted is the first node
            *head = temp->next;
            free(temp);
            return;
        }
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Node not found. Unable to delete.\n");
        } else {
            prev->next = temp->next;
            free(temp);
        }
    }
}

// Function to traverse and print the elements of the list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* temp = head;
        printf("Elements of the list: ");
        do{
            printf("%d", temp->data);
            temp = temp->next;
        }while(temp->next!=head);
        printf("\n");
    }
}

// Driver code
int main() {
    struct Node* head = NULL;

    // Adding elements to the list
    append(&head, 10);
    // append(&head, 20);
    // append(&head, 30);
    // append(&head, 40);
    // append(&head, 50);
    // insertBeg(&head, 70);
    // insertAfterSpecific(&head, 40, 100);

    // // Traversing and printing the list
    // traverse(head);

    // // Deleting nodes
    // deleteFirst(&head);
    // deleteLast(&head);
    // deleteValue(&head, 30);

    // // Traversing and printing the updated list
     traverse(head);

    return 0;
}
