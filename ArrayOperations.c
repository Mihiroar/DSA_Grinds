#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void display(int arr[], int n){
    // code for traversal
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


// int indInsertion(int arr[],int size,int element,int capacity,int index){
//     if(size>=capacity){
//         return -1;
//     }
//     else{
//         for(int i=size-1; i>=index; i--){
//             arr[i+1]=arr[i];
//         }
//         arr[index]=element;
//         return 1;
//     }
// }

// int main(){
//     int arr[100],n;
//     printf("Enter n:");
//     scanf("%d",&n);
//     printf("Enter the array elements:\n");
//     for(int i=0;i<n;i++){
//     scanf("%d",&arr[i]);
//     }
//     int element = 9;
//     int capacity = 100;
//     int index = 1;
//     display(arr,n);
//     indInsertion(arr,n,element,capacity,index);
//     n+=1;
//     display(arr,n);
//     return 0;
// }


void indDeletion(int arr[],int size,int index){
    for(int i=index; i<size ; i++){
        arr[i]=arr[i+1];
    }
}



int main(){
     int arr[100],n;
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    int index = 1;
    display(arr,n);
    indDeletion(arr,n,index);
    n-=1;
    display(arr,n);
    return 0;
}