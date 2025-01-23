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


//irdeq = input restricted double ended queue
typedef struct irdeq{
 struct doubleNode* front;
 struct doubleNode* rear;
} irdeq;

void insert_irdeq(irdeq* queue, int value){
//add to the end

 struct doubleNode* current_rear = queue->rear;
 struct doubleNode* new_rear = malloc(sizeof(doubleNode));
 *new_rear= (doubleNode){value, NULL, current_rear};
 current_rear->next = new_rear;
 queue->rear = new_rear;

}

void pop(irdeq* queue){ //remove the last element
//TODO rename
    doubleNode* current_rear = queue->rear;

    if(queue->rear == NULL){
        printf("Taking no action, queue is empty\n");
    }
    
    else if(queue->rear->prev == NULL){
        printf("Queue only has one element. Removing it.\n");
        queue->front = NULL;
        queue->rear = NULL;
        free(current_rear);
    }
    else {
        printf("Queue has more than one element, removing the last one\n");
        doubleNode* new_rear = queue->rear->prev;
        queue->rear = new_rear;
        new_rear->next = NULL;
        free(current_rear);
        traverseDouble(queue->front);
    }
}

void shift(irdeq* queue){ //remove the first element. everything moves up one (in an array)

if(queue->front == NULL){
    printf("Queue is empty. Taking no action\n");
    return;
}
else if(queue->front->next == NULL) {
    printf("One element in queue. Removing it\n");
    doubleNode* elem = queue->front;
    free(elem);
    queue->front = NULL;
    queue->rear = NULL;

}
else{
    printf("Removing the first element");
    doubleNode* elem = queue->front;
    doubleNode* newHead = queue->front->next;
    queue->front = newHead;
    free(elem);
    traverseDouble(queue->front);
}

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


void placeUnsortedElem(int* arr, int first_unsorted_index){
    for(int i=first_unsorted_index; i>0; i--){
        if(arr[i-1]>arr[i]){
        int tmp = arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=tmp;
        }
        else{break;}
    }
}


void insertion_sort(int* arr, int arr_size){
    int last_sorted_index = 0;

    for(;last_sorted_index<arr_size; last_sorted_index++){
        int current_index = last_sorted_index+1;

        if(arr[current_index]>=arr[last_sorted_index]){
            //do nothing
            continue;
        }else{ //arr[current_index]<arr[last_sorted_index]
            placeUnsortedElem(arr,current_index);
        }
    }

    return;

}

int main()
{

    int arr[28] = {1,2,3,4,5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8};

    interpolation_search(7, arr, 28);

    int array[3] = {2,1,6};
    insertion_sort(array, 3);
    printArray(array, 3);
}
