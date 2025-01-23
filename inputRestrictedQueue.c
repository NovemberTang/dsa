#include "doublyLinkedList.h" //doubleNode
#include <stdlib.h> //for malloc() and NULL
#include <stdio.h>

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
