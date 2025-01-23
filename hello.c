#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "arrayUtils.h"
#include "queue.h"
#include "doublyLinkedList.h"
#include "priorityQueue.h"

int findIndex(int *arr, int value, int arr_len)
{
    int i;
    for (i = 0; i < arr_len; i++)
    {
        if (arr[i] == value)
        {
            printf("Found value %d at position %d\n", value, i);
            return i;
        }
    }
    printf("Couldn't find value %d in array\n", value);
    return -1; // couldn't find the value.
}

struct ringBuffer
{
    int lastReadAddress;
    int nextWriteAddress;
    int *array;
    int arrayLength;
};

int readRingBuffer(struct ringBuffer *r)
{
    int nextAddress = (r->lastReadAddress + 1) % r->arrayLength;
    printf("Reading value from position %d\n", nextAddress);
    int valueToRead = r->array[nextAddress];
    r->lastReadAddress = nextAddress;
    return valueToRead;
}

void writeRingBuffer(struct ringBuffer *r, int value)
{
    printf("Writing value %d to position %d\n", value, r->nextWriteAddress);
    r->array[r->nextWriteAddress] = value;
    r->nextWriteAddress = (r->nextWriteAddress + 1) % r->arrayLength;
}


int interpolation_search_imp(int value, int* arr, int low_pos, int high_pos){

 int low = arr[low_pos];
 int high = arr[high_pos];
 int mid = low_pos + ((high_pos-low_pos) * (value-low)) / (high-low);

 if(arr[mid]==value)
 {
    printf("%d: %d\n", mid, arr[mid]);
    return arr[mid];
 }
 else if(value < arr[mid]){
    return interpolation_search_imp(value, arr, low_pos, mid-1);
 }
 else { // if(value > arr[mid]){
    return interpolation_search_imp(value, arr,mid+1, high_pos);
 };

}

//SO we don't need to remember to decrement the array size to get the last element
int interpolation_search(int value, int* arr, int arr_size){
    return interpolation_search_imp(value, arr, 0, arr_size-1);
}


void placeUnsortedElem(int* arr, int arr_size, int first_unsorted_index){
    for(int i=first_unsorted_index; i>0; i--){
        if(arr[i-1]>arr[i]){
            printf("swapping elements %d and %d\n", i, i-1);
            int tmp = arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=tmp;
            printArray(arr, arr_size);
        }
        else{break;}
    }
}


void insertion_sort(int* arr, int arr_size){
    int last_sorted_index = 0;
    for(;last_sorted_index<arr_size-1; last_sorted_index++){
        int current_index = last_sorted_index+1;

        if(arr[current_index]>=arr[last_sorted_index]){
            printf("last sorted index: %d - array: ", last_sorted_index);
            printArray(arr, arr_size);
            //do nothing
            continue;
        }else{ //arr[current_index]<arr[last_sorted_index]
            placeUnsortedElem(arr,arr_size, current_index);
            printf("last sorted index: %d - array: ", last_sorted_index);
            printArray(arr, arr_size);
        }
    }

    return;

}

void single_pass_swap(int* arr, int unsorted_arr_size, int arr_size){
    for(int idx=1; idx<unsorted_arr_size; idx++){
        if(arr[idx-1]<=arr[idx]){
            printf("elements %d: %d and %d: %d are in the correct order\n", idx-1, arr[idx-1], idx, arr[idx]);
            printArray(arr, arr_size);
        }
        else{
            printf("swapping idx %d: %d and idx %d: %d\n",
                idx-1, arr[idx-1], idx, arr[idx]
            );
            int tmp=arr[idx];
            arr[idx]=arr[idx-1];
            arr[idx-1]= tmp;
            printArray(arr, arr_size);
        }
        printf("\n");
    }

}

void bubble_sort(int* arr, int arr_size){
    printArray(arr, arr_size);

    int unsorted_arr_size=arr_size;
    for(;unsorted_arr_size>0; unsorted_arr_size--){
        if(unsorted_arr_size<2){
            printf("Sorted!\n");
            return;
        }
        printf("%d elements to be sorted.\n", unsorted_arr_size);
        single_pass_swap(arr, unsorted_arr_size, arr_size);
        printf("Position of element %d finalised.\n", unsorted_arr_size-1);
    }

}

int main()
{

    int array[5] = {2,1,6,0,8};
    bubble_sort(array, 5);
    printArray(array, 5);
}
