#include <stdio.h>
#include <stdlib.h>

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

// Function to delete the Kth node from the end
void deleteKthFromEnd(struct Node** head, int k) {
    if (*head == NULL || k <= 0) {
        printf("Invalid input.\n");
        return;
    }

    struct Node *slow = *head, *fast = *head;
    struct Node* prev = NULL;

    // Move the fast pointer K nodes ahead
    for (int i = 0; i < k; i++) {
        if (fast == NULL) {
            printf("List is shorter than K.\n");
            return;
        }
        fast = fast->next;
    }

    // Move both slow and fast pointers until fast reaches the end
    while (fast != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    // Delete the Kth node from the end
    if (prev == NULL) {
        // If the first element needs to be deleted
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        struct Node* temp = prev->next;
        prev->next = temp->next;
        free(temp);
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int k = 2; // Delete the 2nd node from the end
    printf("Original Linked List: ");
    printList(head);

    deleteKthFromEnd(&head, k);

    printf("Linked List after deleting the %d-th node from the end: ", k);
    printList(head);

    // Free memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
