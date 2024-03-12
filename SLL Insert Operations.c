//Ah shit here we go again!! Voila!! Singly Linked List Operations
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void linkedlistTraversal(struct node* ptr){
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

//Insertion At Beginning
struct node* insertAtFirst(struct node* head,int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}


//Insert in Between
struct node* insertAtIndex(struct node* head,int data,int index){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return ptr;
}


struct node* insertAtEnd(struct node* head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p = head;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct node* insertAfterNode(struct node* head, struct node* prevNode, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
}

int main(){
    struct node *head, *N2, *N3;
    
    head =(struct node*)malloc(sizeof(struct node));
    N2 = (struct node*)malloc(sizeof(struct node));
    N3 = (struct node*)malloc(sizeof(struct node));
    
    //Linking the nodes
    head->next = N2;
    head->data = 2;
    
    N2->next = N3;
    N2->data = 5;
    
    N3->next = NULL;
    N3->data = 6;
    
    
    linkedlistTraversal(head);
    // head=insertAtFirst(head,1);
    // linkedlistTraversal(head);
    
    // insertAtIndex(head,56,1);
    // linkedlistTraversal(head);
    
    // insertAtEnd(head,45);
    // linkedlistTraversal(head);
    
    insertAfterNode(head,N2,12);
    linkedlistTraversal(head);
    
    return 0;
    
}