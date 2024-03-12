#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
  struct node* prev;
};


void linkedlistTraversal(struct node* ptr){
  while(ptr != NULL){
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  }
}

struct node* insertAtFirst(struct node* head, int data){
  struct node* ptr = (struct node*)malloc(sizeof(struct node));
  ptr->next = head;
  ptr->prev = NULL;
  ptr->data = data;
  return ptr;
}

struct node* insertAtIndex(struct node* head, int data, int index){
  struct node* ptr = (struct node*)malloc(sizeof(struct node));
  struct node* p = head;
  int i = 0;
  while(i!=index-1){
    p = p->next;
    i++;
  }
  ptr->data = data;
  ptr->next = p->next; 
  p->next = ptr;
  ptr->prev = p;
  ptr->next->prev = ptr;
  return head;
}

struct node* insertAtEnd(struct node* head, int data){
  struct node* ptr = (struct node*)malloc(sizeof(struct node));
  struct node* p = head;
  while(p->next!=NULL){
    p=p->next;
  }
  ptr->data = data;
  p->next = ptr;
  ptr->next = NULL;
  ptr->prev = p;
  return head;
}

struct node* insertAfterNode(struct node* head, struct node* prevNode, int data){
  struct node* ptr = (struct node*)malloc(sizeof(struct node));
  ptr->data = data;
  ptr->next = prevNode->next;
  prevNode->next = ptr;
  ptr->prev = prevNode;
  ptr->next->prev = ptr;
  return head;
}

// Delete Operation on Doubly Linked List

struct node* deleteFirst(struct node* head){
  struct node* ptr = head;
  head = head->next;
  head->prev = NULL;
  free(ptr);
  return head;
}


struct node* deleteAtIndex(struct node* head, int index){
  struct node* p = head;
  struct node* q = head->next;
  int i = 0;
  while(i!=index-1){
    p = p->next;
    q = q->next;
    i++;
  }
  p->next = q->next;
  q->next->prev = p;
  free(q);
  return head;
}

struct node* deleteAtEnd(struct node* head){
  struct node* p = head;
  struct node* q = head->next;
  while(q->next!=NULL){
    p = p->next;
    q = q->next;
  }
  p->next = NULL;
  free(q);
  return head;
}

struct node* deletAfterNode(struct node* head, struct node* prevNode){
  struct node* p = head;
  struct node* q = head->next;
  while(p!=prevNode){
    p = p->next;
    q = q->next;
  }
  p->next = q->next;
  q->next->prev = p;
  free(q);
  return head;
}



int main(){
  struct node* head;
  struct node* second;
  struct node* third;
  struct node* fourth;

  // Allocate memory for nodes in the linked list in Heap
  head = (struct node*)malloc(sizeof(struct node));
  second = (struct node*)malloc(sizeof(struct node));
  third = (struct node*)malloc(sizeof(struct node));
  fourth = (struct node*)malloc(sizeof(struct node));

  // Link first and second nodes
  head->data = 7;
  head->next = second;
  head->prev = NULL;

  // Link second and third nodes
  second->data = 11;
  second->next = third;
  second->prev = head;

  // Link third and fourth nodes
  third->data = 41;
  third->next = fourth;
  third->prev = second;

  // Terminate the list at the third node
  fourth->data = 66;
  fourth->next = NULL;
  fourth->prev = third;

  linkedlistTraversal(head);
  printf("\n");
  
  // Insert Function Calls
  // head = insertAtFirst(head, 56);
  // head = insertAtIndex(head, 56, 1);
  // head = insertAtEnd(head, 56);
  // head = insertAfterNode(head, third, 45);

  //Delete Function Calls
  
  // head = deleteFirst(head);
  // head = deleteAtIndex(head, 2);
  // head = deleteAtEnd(head);
  head = deletAfterNode(head, second);
  linkedlistTraversal(head);

  return 0;
}