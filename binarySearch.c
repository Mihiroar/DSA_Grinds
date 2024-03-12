#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *arr, int n, int key)
{
    int low = 0, high = n-1, mid;
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
}

int main()
{
  int n, key, *arr, i;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  arr = (int *)malloc(n*sizeof(int));
  printf("Enter the elements of the array: ");
  for(i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
    printf("Enter the key to be searched: ");
    scanf("%d", &key);
    int index = binarySearch(arr, n ,key);
    if (index == -1) {
        printf("Element not found\n");
    }
    else {
        printf("Element found at index %d\n", index);
    }
  return 0;
}