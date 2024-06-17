// #include<stdio.h>
// #include<stdlib.h>

// // Define the Node structure
// struct Node {
//     int data;
//     struct Node *next;
// };

// // Function to traverse and print the circular linked list
// void linkedListTraversal(struct Node *head) {
//     struct Node *ptr = head;
//     do {
//         printf("Element is: %d\n", ptr->data);
//         ptr = ptr->next;
//     } while(ptr != head);
// }

// // Function to insert a node at the beginning of the circular linked list
// struct Node *insertAtFirst(struct Node *head, int data) {
//     struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
//     ptr->data = data;

//     struct Node *p = head->next;
//     while(p->next != head) {
//         p = p->next;
//     }

//     p->next = ptr;
//     ptr->next = head;
//     head = ptr;
//     return head;
// }

// // Function to insert a node at the end of the circular linked list
// struct Node *insertAtEnd(struct Node *head, int data) {
//     struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
//     ptr->data = data;

//     struct Node *p = head;
//     while(p->next != head) {
//         p = p->next;
//     }

//     p->next = ptr;
//     ptr->next = head;
//     return head;
// }

// // Function to insert a node in between the circular linked list
// struct Node *insertInBetween(struct Node *head, int data, int index) {
//     struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
//     ptr->data = data;

//     struct Node *p = head;
//     int i = 0;
//     while(i != index-1) {
//         p = p->next;
//         i++;
//     }

//     ptr->next = p->next;
//     p->next = ptr;
//     return head;
// }

// // Function to insert a node after a given node
// struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data) {
//     struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
//     ptr->data = data;

//     ptr->next = prevNode->next;
//     prevNode->next = ptr;
//     return head;
// }

// // Main function
// int main() {
//     struct Node *head;
//     struct Node *N2;
//     struct Node *N3;

//     // Allocate memory for nodes in the linked list in the heap
//     head = (struct Node*) malloc(sizeof(struct Node));
//     N2 = (struct Node*) malloc(sizeof(struct Node));
//     N3 = (struct Node*) malloc(sizeof(struct Node));

//     // Initialize nodes
//     head->data = 7;
//     head->next = N2;

//     N2->data = 9;
//     N2->next = N3;

//     N3->data = 5;
//     N3->next = head;

//     printf("Circular Linked List before insertion:\n");
//     linkedListTraversal(head);

//     head = insertAtFirst(head, 80);
//     printf("\nCircular Linked List after inserting 80 at the beginning:\n");
//     linkedListTraversal(head);

//     head = insertAtEnd(head, 45);
//     printf("\nCircular Linked List after inserting 45 at the end:\n");
//     linkedListTraversal(head);

//     head = insertInBetween(head, 25, 2);
//     printf("\nCircular Linked List after inserting 25 at index 2:\n");
//     linkedListTraversal(head);

//     head = insertAfterNode(head, N2, 30);
//     printf("\nCircular Linked List after inserting 30 after second node:\n");
//     linkedListTraversal(head);

//     return 0;
// }

// DELETION PROGRAM
// Imp point to note that successive function will take input from the output of previous one as like they assume that the previous function has already been executed and the output is the input for the next function.Eitherr you can comment the previous function and run the next function or you can run the program as it is and see the output of each function.

#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function to traverse and print the circular linked list
void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element is: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *deleteFirst(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != head)
    {
        q = q->next;
    }
    q->next = head->next;
    head = head->next;
    free(p);
    return head;
}

struct Node *deleteLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    free(q);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deleteAfterNode(struct Node *head, struct Node *prevNode)
{
    struct Node *p = prevNode;
    struct Node *q = prevNode->next;
    p->next = q->next;
    free(q);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *N2;
    struct Node *N3;
    struct Node *N4;

    // Allocate memory for nodes in the linked list in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    N2 = (struct Node *)malloc(sizeof(struct Node));
    N3 = (struct Node *)malloc(sizeof(struct Node));
    N4 = (struct Node *)malloc(sizeof(struct Node));

    // Initialize nodes
    head->data = 7;
    head->next = N2;

    N2->data = 9;
    N2->next = N3;

    N3->data = 5;
    N3->next = N4;

    N4->data = 10;
    N4->next = head;

    printf("Circular Linked List before insertion:\n");
    linkedListTraversal(head);

    head = deleteFirst(head);
    printf("\nCircular Linked List after deleting first node:\n");
    linkedListTraversal(head);

    head = deleteLast(head);
    printf("\nCircular Linked List after deleting last node:\n");
    linkedListTraversal(head);

    head = deleteAtIndex(head, 1);
    printf("\nCircular Linked List after deleting node at index 1:\n");
    linkedListTraversal(head);

    head = deleteAfterNode(head, N2);
    printf("\nCircular Linked List after deleting node after second node:\n");
    linkedListTraversal(head);

    return 0;
}
