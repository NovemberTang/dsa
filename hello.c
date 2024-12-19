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

int sequential_search(int val, int *arr, int arraySize){
    for(int i=0;i<arraySize;i++){
        if(arr[i]==val)
        return i;
    }
    printf("%d not found in array\n", val);
    return -1;
}

int main()
{

    int arr[5] = {1,2,3,4,5};

    int notfound = sequential_search(0, arr, 5);
    printf("%d\n", notfound);
    int found = sequential_search(4,arr, 5);
    printf("%d\n", found);

    return 0;
}
