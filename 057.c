#include <stdio.h>
#include <stdlib.h>

void allocateArray(int *arr, int size, int value){
    arr = (int *)malloc(size * sizeof(int));
    if(arr!=NULL){
        for(int i=0; i<size; i++){
            arr[i] = value;
        }
    }
}


int main() {
    int *vector = NULL;
    allocateArray(&vector,5,45);
    printf("%p\n", vector); // show 0x0
    return 0;
}
