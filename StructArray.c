#include<stdio.h>
#include<stdlib.h>

struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray*a,int tSize,int Usize){
    a->total_size = tSize;
    a->used_size = Usize;
    a->ptr = (int*)malloc(tSize*sizeof(int));
}

void show(struct myArray*a){
    for(int i=0; i<a->used_size; i++){
        printf("%d ",(a->ptr)[i]);
    }
}

void setVal(struct myArray *a){
    int n;
    for(int i=0; i<a->used_size;i++){
        printf("Enter element '%d': ", i);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
}


int main(){
    struct myArray names;
    createArray(&names,10,3);
    printf("We are running setVal now:\n");
    setVal(&names);
    
    printf("We are running show now:\n");
    show(&names);
    return 0;
}



