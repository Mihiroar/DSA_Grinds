//Stack Using Array

// #include <stdio.h>
// #include <stdlib.h>

// struct stack{
//     int size;
//     int top;
//     int *arr;
// };

// int isEmpty(struct stack *ptr){
//     if(ptr->top == -1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// int isFull(struct stack *ptr){
//     if(ptr->top == ptr->size-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// void push(struct stack *ptr, int val){
//     if(isFull(ptr)){
//         printf("Stack Overflow! Cannot push %d to the stack\n", val);
//     }
//     else{
//         ptr->top++;
//         ptr->arr[ptr->top] = val;
//     }

// }

// int pop(struct stack *ptr){
//     if(isEmpty(ptr)){
//         printf("Stack Underflow! Cannot pop from the stack\n");
//         return -1;
//     }
//     else{
//         int val = ptr->arr[ptr->top];
//         ptr->top--;
//         return val;
//     }
// }

// int peek(struct stack *sp, int i){
//     int arrayInd = sp->top - i + 1;
//     if(arrayInd < 0){
//         printf("Not a valid position for the stack\n");
//         return -1;
//     }
//     else{
//         return sp->arr[arrayInd];
//     }
// }

// int stackTop(struct stack *sp){
//     return sp->arr[sp->top];
// }

// int stackBottom(struct stack *sp){
//     return sp->arr[0];
// }

// int main(){
//     struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
//     sp->size = 10;
//     sp->top = -1;
//     sp->arr = (int *) malloc(sp->size * sizeof(int));
//     printf("Stack has been created successfully\n");

//     printf("Before pushing, Full: %d\n", isFull(sp));
//     printf("Before pushing, Empty: %d\n", isEmpty(sp));
    
    
//     push(sp, 1);
//     push(sp, 23);
//     push(sp, 99);
//     push(sp, 75);

//     printf("After pushing, Full: %d\n", isFull(sp));
//     printf("After pushing, Empty: %d\n", isEmpty(sp));

    // printf("Popped %d from the stack\n", pop(sp));
    // printf("Popped %d from the stack\n", pop(sp));
    // printf("Popped %d from the stack\n", pop(sp));

    // printf("After popping, Full: %d\n", isFull(sp));
    // printf("After popping, Empty: %d\n", isEmpty(sp));

//     for (int j = 1; j <= sp->top+1; j++){
//         printf("The value at position %d is %d\n", j, peek(sp, j));
//     }

//     printf("The topmost value of this stack is %d\n", stackTop(sp));
//     printf("The bottommost value of this stack is %d\n", stackBottom(sp));

//     return 0;
// }



// Stack using Linked List

#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;
};



void linkedListTraversal(struct node* ptr){
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }
}


int isEmpty(struct node* top){
    if(top==NULL){
        printf("Stack Underflow :(\n");
    }
    else{
        return 0;
    }
}

int isFull(struct node* top){
    struct node *p = (struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        printf("Stack Overflow :(\n");
    }
    else{
        return 0;
    }
}



struct node *push(struct node *top, int x){
    if(isFull(top)){
        printf("Stack Overflow :(\n");
    }
    else{
        struct node *n = (struct node*)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}


int pop(struct node **top){
    if(isEmpty(*top)){
        printf("Stack Underflow :(");
    }
    else{
        struct node *n = *top;
        (*top) = (*top) -> next;
        int x = n->data;
        free(n);
        return x;
    }
}


int main(){
    struct node *top = NULL;
    
    top = push(top,2);
    top = push(top,4);
    top = push(top,9);
    top = push(top,7);
    linkedListTraversal(top);
    
    int element = pop(&top);
    printf("Popped Element is %d\n",element);
    linkedListTraversal(top);
    
    
    return 0;
}


