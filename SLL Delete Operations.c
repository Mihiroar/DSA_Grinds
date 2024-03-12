#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void linkedListTraversal(struct node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node* deleteFirst(struct node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    struct node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}


struct node* deleteAtIndex(struct node* head,int index){
    struct node* p = head;
    struct node* q = head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct node* deleteAtLast(struct node* head){
    struct node* p = head;
    struct node* q = head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}


struct node* deleteAtValue(struct node* head, int value){
    struct node* p = head;
    struct node* q = head->next;
    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    
    if(q->data == value){
    p->next=q->next;
    free(q);
    return head;
    }
}



int main() {
    struct node* head = NULL;
    struct node* N2 = NULL;
    struct node* N3 = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    N2 = (struct node*)malloc(sizeof(struct node));
    N3 = (struct node*)malloc(sizeof(struct node));

    if (head == NULL || N2 == NULL || N3 == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 0;
    }

    // Linking the nodes
    head->data = 2;
    head->next = N2;

    N2->data = 5;
    N2->next = N3;

    N3->data = 6;
    N3->next = NULL;

    printf("Initial linked list: \n");
    linkedListTraversal(head);

    // head = deleteFirst(head);
    // head = deleteAtIndex(head,2);
    // head = deleteAtLast(head);
    // head = deleteAtValue(head,5);
    
    
    
    printf("Modified linked list after deleting the first element: \n");
    linkedListTraversal(head);

    return 0;
}
