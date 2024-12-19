#include "linkedList.h"
#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "queue.h"

struct queueHeader queueHeader;

void pushQueue(struct queueHeader *header, int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    *newNode = (struct node){value, NULL};
    if (header->firstNode == NULL)
    {
        header->firstNode = newNode;
    }
    else
    {
        header->lastNode->next = newNode;
    }
    header->lastNode = newNode;
}

void traverseQueue(struct queueHeader *header)
{
    if (header->firstNode == NULL)
    {
        printf("No elements in queue\n");
    }
    else
    {
        traverse(*header->firstNode);
    }
}

int popQueue(struct queueHeader *header)
{
    if (header->firstNode == NULL)
    {
        printf("No elements in queue\n");
        return -1;
    }
    else
    {
        struct node *firstNode = header->firstNode;
        int returnValue = firstNode->value;
        struct node *secondNode = firstNode->next;
        header->firstNode = secondNode;
        free(firstNode);

        if (header->firstNode == NULL)
        {
            header->lastNode = NULL;
        }

        return returnValue;
    }
}
