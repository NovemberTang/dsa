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

void twoDimArraySum(int arr1[3][3], int arr2[3][3])
{
    int resultArray[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            resultArray[i][j] = arr1[i][j] + arr2[i][j];
        }
        printArray(resultArray[i], 3);
    }
}

void transpose(int arr[3][3])
{
    int resultArray[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            resultArray[i][j] = arr[j][i];
        }
        printArray(resultArray[i], 3);
    }
}

void print3dArray(int arr[2][2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printArray(arr[i][j], 2);
        }
    }
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
        printf("Taking no action, queue is empty\n"); //TODO fix this. it's not working
        traverseDouble(queue->front);
    }
    
    else if(queue->rear->prev == NULL){
        printf("Queue only has one element\n");
        queue->front = NULL;
        queue->rear = NULL;
        free(current_rear);
        traverseDouble(queue->front);
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
}


int main()
{

    doubleNode *myNode1 = malloc(sizeof(doubleNode));
    doubleNode *myNode2 = malloc(sizeof(doubleNode));

    *myNode1 = (doubleNode){0, myNode2, NULL};
    *myNode2 = (doubleNode){1, NULL, myNode1};

    struct irdeq myQueue = {myNode1, myNode2};

    traverseDouble(myQueue.front);
    pop(&myQueue);
    pop(&myQueue);
    pop(&myQueue);

    return 0;
}
