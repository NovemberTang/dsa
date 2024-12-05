#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "arrayUtils.h"
#include "queue.h"
#include "linkedList.h"

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

//PRIORITY QUEUE
typedef struct pq_node{
    int priority;
    int value;
    struct pq_node* next;
}pq_node;

typedef struct {
    pq_node* first;
}priority_queue;

pq_node* findLastElementWithPriorityX(int priority, priority_queue *queue){
 pq_node* current = queue->first;
 printf("priority: %d, value: %d\n", current->priority, current->value);
 if(current == NULL){
    printf("Nothing here!\n");
    return NULL;
 }
 while(current->next != NULL && current->next->priority < priority+1){
    current = current->next;
    printf("priority: %d, value: %d\n", current->priority, current->value);
 }
 return current;

};

void insertIntoQueue(int priority, int value, priority_queue *queue){
    pq_node* lastNodeWithHigherPriority = findLastElementWithPriorityX(priority, queue);

    pq_node *newNode = malloc(sizeof(pq_node));
    *newNode = (pq_node){priority, value, NULL};

    if(lastNodeWithHigherPriority == NULL){
        queue->first = newNode;
    }
    else {
        pq_node* firstElementWithLowerPriority = lastNodeWithHigherPriority->next;
        newNode->next = firstElementWithLowerPriority;
        lastNodeWithHigherPriority->next = newNode;
    }
}

void traversePriorityQueue(priority_queue *queue){
    pq_node* current = queue->first;
    printf("\n\npriority: %d, value: %d\n", current->priority, current->value);
    while(current->next !=NULL){
        current = current->next;
        printf("priority: %d, value: %d\n", current->priority, current->value);
    }
    

}

int popPriorityQueue(priority_queue *queue){
    int poppedValue = queue->first->value;
    pq_node* newHead = queue->first->next;
    free(queue->first);
    queue->first = newHead;
    return poppedValue;
}

int main()
{

    pq_node *myNode2 = malloc(sizeof(pq_node));
    *myNode2= (pq_node){3,0,NULL};

    pq_node *myNode = malloc(sizeof(pq_node));
    *myNode= (pq_node){1,0,myNode2};

    priority_queue *myQueue = malloc(sizeof(priority_queue));
    *myQueue = (priority_queue){myNode};

    insertIntoQueue(2, 1, myQueue);
    traversePriorityQueue(myQueue);

    int x = popPriorityQueue(myQueue);
    printf("\n%d\n", x);
    traversePriorityQueue(myQueue);
    return 0;
}
