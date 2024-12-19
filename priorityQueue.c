#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "priorityQueue.h"

struct priority_queue;
struct pq_node;


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

}

void insertIntoPriorityQueue(int priority, int value, priority_queue *queue){
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
